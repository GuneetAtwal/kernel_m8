/*
 * Copyright (C) 2008-2009 Paulius Zaleckas <paulius.zaleckas@teltonika.lt>
 *
 * Based on mach-pxa/include/mach/uncompress.h:
 * Copyright:	(C) 2001 MontaVista Software Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __MACH_UNCOMPRESS_H
#define __MACH_UNCOMPRESS_H

#include <linux/serial_reg.h>
#include <mach/hardware.h>

static volatile unsigned long * const UART = (unsigned long *)GEMINI_UART_BASE;

static inline void putc(char c)
{
	while (!(UART[UART_LSR] & UART_LSR_THRE))
		barrier();
	UART[UART_TX] = c;
}

static inline void flush(void)
{
}

#define arch_decomp_setup()

#define arch_decomp_wdog()

#endif 
