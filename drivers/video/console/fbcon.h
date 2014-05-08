/*
 *  linux/drivers/video/console/fbcon.h -- Low level frame buffer based console driver
 *
 *	Copyright (C) 1997 Geert Uytterhoeven
 *
 *  This file is subject to the terms and conditions of the GNU General Public
 *  License.  See the file COPYING in the main directory of this archive
 *  for more details.
 */

#ifndef _VIDEO_FBCON_H
#define _VIDEO_FBCON_H

#include <linux/types.h>
#include <linux/vt_buffer.h>
#include <linux/vt_kern.h>

#include <asm/io.h>

#define FBCON_FLAGS_INIT         1
#define FBCON_FLAGS_CURSOR_TIMER 2


struct display {
    
    const u_char *fontdata;
    int userfont;                   
    u_short scrollmode;             
    u_short inverse;                
    short yscroll;                  
    int vrows;                      
    int cursor_shape;
    int con_rotate;
    u32 xres_virtual;
    u32 yres_virtual;
    u32 height;
    u32 width;
    u32 bits_per_pixel;
    u32 grayscale;
    u32 nonstd;
    u32 accel_flags;
    u32 rotate;
    struct fb_bitfield red;
    struct fb_bitfield green;
    struct fb_bitfield blue;
    struct fb_bitfield transp;
    const struct fb_videomode *mode;
};

struct fbcon_ops {
	void (*bmove)(struct vc_data *vc, struct fb_info *info, int sy,
		      int sx, int dy, int dx, int height, int width);
	void (*clear)(struct vc_data *vc, struct fb_info *info, int sy,
		      int sx, int height, int width);
	void (*putcs)(struct vc_data *vc, struct fb_info *info,
		      const unsigned short *s, int count, int yy, int xx,
		      int fg, int bg);
	void (*clear_margins)(struct vc_data *vc, struct fb_info *info,
			      int bottom_only);
	void (*cursor)(struct vc_data *vc, struct fb_info *info, int mode,
		       int softback_lines, int fg, int bg);
	int  (*update_start)(struct fb_info *info);
	int  (*rotate_font)(struct fb_info *info, struct vc_data *vc);
	struct fb_var_screeninfo var;  
	struct timer_list cursor_timer; 
	struct fb_cursor cursor_state;
	struct display *p;
        int    currcon;	                
	int    cursor_flash;
	int    cursor_reset;
	int    blank_state;
	int    graphics;
	int    save_graphics; 
	int    flags;
	int    rotate;
	int    cur_rotate;
	char  *cursor_data;
	u8    *fontbuffer;
	u8    *fontdata;
	u8    *cursor_src;
	u32    cursor_size;
	u32    fd_size;
};

#define attr_fgcol(fgshift,s)    \
	(((s) >> (fgshift)) & 0x0f)
#define attr_bgcol(bgshift,s)    \
	(((s) >> (bgshift)) & 0x0f)

#define attr_bold(s) \
	((s) & 0x200)
#define attr_reverse(s) \
	((s) & 0x800)
#define attr_underline(s) \
	((s) & 0x400)
#define attr_blink(s) \
	((s) & 0x8000)
	

static inline int mono_col(const struct fb_info *info)
{
	__u32 max_len;
	max_len = max(info->var.green.length, info->var.red.length);
	max_len = max(info->var.blue.length, max_len);
	return (~(0xfff << max_len)) & 0xff;
}

static inline int attr_col_ec(int shift, struct vc_data *vc,
			      struct fb_info *info, int is_fg)
{
	int is_mono01;
	int col;
	int fg;
	int bg;

	if (!vc)
		return 0;

	if (vc->vc_can_do_color)
		return is_fg ? attr_fgcol(shift,vc->vc_video_erase_char)
			: attr_bgcol(shift,vc->vc_video_erase_char);

	if (!info)
		return 0;

	col = mono_col(info);
	is_mono01 = info->fix.visual == FB_VISUAL_MONO01;

	if (attr_reverse(vc->vc_video_erase_char)) {
		fg = is_mono01 ? col : 0;
		bg = is_mono01 ? 0 : col;
	}
	else {
		fg = is_mono01 ? 0 : col;
		bg = is_mono01 ? col : 0;
	}

	return is_fg ? fg : bg;
}

#define attr_bgcol_ec(bgshift, vc, info) attr_col_ec(bgshift, vc, info, 0)
#define attr_fgcol_ec(fgshift, vc, info) attr_col_ec(fgshift, vc, info, 1)

#define REFCOUNT(fd)	(((int *)(fd))[-1])
#define FNTSIZE(fd)	(((int *)(fd))[-2])
#define FNTCHARCNT(fd)	(((int *)(fd))[-3])
#define FNTSUM(fd)	(((int *)(fd))[-4])
#define FONT_EXTRA_WORDS 4

     

#define SCROLL_MOVE	   0x001
#define SCROLL_PAN_MOVE	   0x002
#define SCROLL_WRAP_MOVE   0x003
#define SCROLL_REDRAW	   0x004
#define SCROLL_PAN_REDRAW  0x005

#ifdef CONFIG_FB_TILEBLITTING
extern void fbcon_set_tileops(struct vc_data *vc, struct fb_info *info);
#endif
extern void fbcon_set_bitops(struct fbcon_ops *ops);
extern int  soft_cursor(struct fb_info *info, struct fb_cursor *cursor);

#define FBCON_ATTRIBUTE_UNDERLINE 1
#define FBCON_ATTRIBUTE_REVERSE   2
#define FBCON_ATTRIBUTE_BOLD      4

static inline int real_y(struct display *p, int ypos)
{
	int rows = p->vrows;

	ypos += p->yscroll;
	return ypos < rows ? ypos : ypos - rows;
}


static inline int get_attribute(struct fb_info *info, u16 c)
{
	int attribute = 0;

	if (fb_get_color_depth(&info->var, &info->fix) == 1) {
		if (attr_underline(c))
			attribute |= FBCON_ATTRIBUTE_UNDERLINE;
		if (attr_reverse(c))
			attribute |= FBCON_ATTRIBUTE_REVERSE;
		if (attr_bold(c))
			attribute |= FBCON_ATTRIBUTE_BOLD;
	}

	return attribute;
}

#define FBCON_SWAP(i,r,v) ({ \
        typeof(r) _r = (r);  \
        typeof(v) _v = (v);  \
        (void) (&_r == &_v); \
        (i == FB_ROTATE_UR || i == FB_ROTATE_UD) ? _r : _v; })

#ifdef CONFIG_FRAMEBUFFER_CONSOLE_ROTATION
extern void fbcon_set_rotate(struct fbcon_ops *ops);
#else
#define fbcon_set_rotate(x) do {} while(0)
#endif 

#endif 
