/* Copyright (c) 2012, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/module.h>
#include <linux/clocksource.h>
#include <linux/clockchips.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <mach/event_timer.h>

#define __INIT_HEAD(x)	{ .head = RB_ROOT,\
			.next = NULL, }

#define DEFINE_TIME_HEAD(x) struct timerqueue_head x = __INIT_HEAD(x)

struct event_timer_info {
	struct timerqueue_node node;
	void (*function)(void *);
	void *data;
};

static DEFINE_TIME_HEAD(timer_head);
static DEFINE_SPINLOCK(event_timer_lock);
static DEFINE_SPINLOCK(event_setup_lock);
static struct hrtimer event_hrtimer;
static enum hrtimer_restart event_hrtimer_cb(struct hrtimer *hrtimer);

static int msm_event_debug_mask;
module_param_named(
	debug_mask, msm_event_debug_mask, int, S_IRUGO | S_IWUSR | S_IWGRP
);

enum {
	MSM_EVENT_TIMER_DEBUG = 1U << 0,
};


struct event_timer_info *add_event_timer(void (*function)(void *), void *data)
{
	struct event_timer_info *event_info =
			kzalloc(sizeof(struct event_timer_info), GFP_KERNEL);

	if (!event_info)
		return NULL;

	event_info->function = function;
	event_info->data = data;
	
	timerqueue_init(&event_info->node);
	pr_debug("%s: New Event Added. Event 0x%x.",
	__func__,
	(unsigned int)event_info);

	return event_info;
}

static bool is_event_next(struct event_timer_info *event)
{
	struct event_timer_info *next_event;
	struct timerqueue_node *next;
	bool ret = false;

	next = timerqueue_getnext(&timer_head);
	if (!next)
		goto exit_is_next_event;

	next_event = container_of(next, struct event_timer_info, node);
	if (!next_event)
		goto exit_is_next_event;

	if (next_event == event)
		ret = true;

exit_is_next_event:
	return ret;
}

static bool is_event_active(struct event_timer_info *event)
{
	struct timerqueue_node *next;
	struct event_timer_info *next_event;
	bool ret = false;

	for (next = timerqueue_getnext(&timer_head); next;
			next = timerqueue_iterate_next(next)) {
		next_event = container_of(next, struct event_timer_info, node);

		if (event == next_event) {
			ret = true;
			break;
		}
	}
	return ret;
}

static void create_hrtimer(ktime_t expires)
{
	static bool timer_initialized;

	if (!timer_initialized) {
		hrtimer_init(&event_hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
		timer_initialized = true;
	}

	event_hrtimer.function = event_hrtimer_cb;
	hrtimer_start(&event_hrtimer, expires, HRTIMER_MODE_ABS);
}

static enum hrtimer_restart event_hrtimer_cb(struct hrtimer *hrtimer)
{
	struct event_timer_info *event;
	struct timerqueue_node *next;
	unsigned long flags;

	spin_lock_irqsave(&event_timer_lock, flags);
	next = timerqueue_getnext(&timer_head);

	while (next && (ktime_to_ns(next->expires)
		<= ktime_to_ns(hrtimer->node.expires))) {
		if (!next)
			goto hrtimer_cb_exit;

		event = container_of(next, struct event_timer_info, node);
		if (!event)
			goto hrtimer_cb_exit;

		if (msm_event_debug_mask && MSM_EVENT_TIMER_DEBUG)
			pr_info("%s: Deleting event 0x%x @ %lu", __func__,
			(unsigned int)event,
			(unsigned long)ktime_to_ns(next->expires));

		timerqueue_del(&timer_head, &event->node);

		if (event->function)
			event->function(event->data);
		next = timerqueue_getnext(&timer_head);
	}

	if (next)
		create_hrtimer(next->expires);

	spin_unlock_irqrestore(&event_timer_lock, flags);
hrtimer_cb_exit:
	return HRTIMER_NORESTART;
}

static void create_timer_smp(void *data)
{
	unsigned long flags;
	struct event_timer_info *event =
		(struct event_timer_info *)data;
	struct timerqueue_node *next;

	spin_lock_irqsave(&event_timer_lock, flags);
	if (is_event_active(event))
		timerqueue_del(&timer_head, &event->node);

	next = timerqueue_getnext(&timer_head);
	timerqueue_add(&timer_head, &event->node);
	if (msm_event_debug_mask && MSM_EVENT_TIMER_DEBUG)
		pr_info("%s: Adding Event 0x%x for %lu", __func__,
		(unsigned int)event,
		(unsigned long)ktime_to_ns(event->node.expires));

	if (!next ||
		(next && (ktime_to_ns(event->node.expires) <
				ktime_to_ns(next->expires)))) {
		if (msm_event_debug_mask && MSM_EVENT_TIMER_DEBUG)
			pr_info("%s: Setting timer for %lu", __func__,
			(unsigned long)ktime_to_ns(event->node.expires));
		create_hrtimer(event->node.expires);
	}
	spin_unlock_irqrestore(&event_timer_lock, flags);
}

static void setup_event_hrtimer(struct event_timer_info *event)
{
	smp_call_function_single(0, create_timer_smp, event, 1);
}

void activate_event_timer(struct event_timer_info *event, ktime_t event_time)
{
	if (!event)
		return;

	if (msm_event_debug_mask && MSM_EVENT_TIMER_DEBUG)
		pr_info("%s: Adding event timer @ %lu", __func__,
				(unsigned long)ktime_to_us(event_time));

	spin_lock(&event_setup_lock);
	event->node.expires = event_time;
	
	setup_event_hrtimer(event);
	spin_unlock(&event_setup_lock);
}


void deactivate_event_timer(struct event_timer_info *event)
{
	unsigned long flags;

	if (msm_event_debug_mask && MSM_EVENT_TIMER_DEBUG)
		pr_info("%s: Deactivate timer", __func__);

	spin_lock_irqsave(&event_timer_lock, flags);
	if (is_event_active(event)) {
		if (is_event_next(event))
			hrtimer_try_to_cancel(&event_hrtimer);

		timerqueue_del(&timer_head, &event->node);
	}
	spin_unlock_irqrestore(&event_timer_lock, flags);
}

void destroy_event_timer(struct event_timer_info *event)
{
	unsigned long flags;

	spin_lock_irqsave(&event_timer_lock, flags);
	if (is_event_active(event)) {
		if (is_event_next(event))
			hrtimer_try_to_cancel(&event_hrtimer);

		timerqueue_del(&timer_head, &event->node);
	}
	spin_unlock_irqrestore(&event_timer_lock, flags);
	kfree(event);
}

ktime_t get_next_event_time(void)
{
	unsigned long flags;
	struct timerqueue_node *next;
	ktime_t next_event = ns_to_ktime(0);

	spin_lock_irqsave(&event_timer_lock, flags);
	next = timerqueue_getnext(&timer_head);
	spin_unlock_irqrestore(&event_timer_lock, flags);

	if (!next)
		return next_event;

	next_event = hrtimer_get_remaining(&event_hrtimer);
	if (msm_event_debug_mask && MSM_EVENT_TIMER_DEBUG)
		pr_info("%s: Next Event %lu", __func__,
			(unsigned long)ktime_to_us(next_event));

	return next_event;
}
