/*-----------------------------------------------------------------------------
 * comet_tables.c - waveform tables for the PM4351 'COMET'
 *
 * Copyright (C) 2003-2005  SBE, Inc.
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 * For further information, contact via email: support@sbei.com
 * SBE, Inc.  San Ramon, California  U.S.A.
 *-----------------------------------------------------------------------------
 */

#include <linux/types.h>


u_int8_t TWVLongHaul0DB[25][5] =
{
    {0x00, 0x44, 0x00, 0x00, 0x00},     
    {0x0A, 0x44, 0x00, 0x00, 0x00},     
    {0x20, 0x43, 0x00, 0x00, 0x00},     
    {0x32, 0x43, 0x00, 0x00, 0x00},     
    {0x3E, 0x42, 0x00, 0x00, 0x00},     
    {0x3D, 0x42, 0x00, 0x00, 0x00},     
    {0x3C, 0x41, 0x00, 0x00, 0x00},     
    {0x3B, 0x41, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x39, 0x00, 0x00, 0x00, 0x00},     
    {0x39, 0x00, 0x00, 0x00, 0x00},     
    {0x38, 0x00, 0x00, 0x00, 0x00},     
    {0x37, 0x00, 0x00, 0x00, 0x00},     
    {0x36, 0x00, 0x00, 0x00, 0x00},     
    {0x34, 0x00, 0x00, 0x00, 0x00},     
    {0x29, 0x00, 0x00, 0x00, 0x00},     
    {0x4F, 0x00, 0x00, 0x00, 0x00},     
    {0x4C, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x49, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x46, 0x00, 0x00, 0x00, 0x00},     
    {0x46, 0x00, 0x00, 0x00, 0x00},     
    {0x0C}                              
};

u_int8_t    TWVLongHaul7_5DB[25][5] =   
{
    {0x00, 0x10, 0x00, 0x00, 0x00},     
    {0x01, 0x0E, 0x00, 0x00, 0x00},     
    {0x02, 0x0C, 0x00, 0x00, 0x00},     
    {0x04, 0x0A, 0x00, 0x00, 0x00},     
    {0x08, 0x08, 0x00, 0x00, 0x00},     
    {0x0C, 0x06, 0x00, 0x00, 0x00},     
    {0x10, 0x04, 0x00, 0x00, 0x00},     
    {0x16, 0x02, 0x00, 0x00, 0x00},     
    {0x1A, 0x01, 0x00, 0x00, 0x00},     
    {0x1E, 0x00, 0x00, 0x00, 0x00},     
    {0x22, 0x00, 0x00, 0x00, 0x00},     
    {0x26, 0x00, 0x00, 0x00, 0x00},     
    {0x2A, 0x00, 0x00, 0x00, 0x00},     
    {0x2B, 0x00, 0x00, 0x00, 0x00},     
    {0x2C, 0x00, 0x00, 0x00, 0x00},     
    {0x2D, 0x00, 0x00, 0x00, 0x00},     
    {0x2C, 0x00, 0x00, 0x00, 0x00},     
    {0x28, 0x00, 0x00, 0x00, 0x00},     
    {0x24, 0x00, 0x00, 0x00, 0x00},     
    {0x20, 0x00, 0x00, 0x00, 0x00},     
    {0x1C, 0x00, 0x00, 0x00, 0x00},     
    {0x18, 0x00, 0x00, 0x00, 0x00},     
    {0x14, 0x00, 0x00, 0x00, 0x00},     
    {0x12, 0x00, 0x00, 0x00, 0x00},     
    {0x07}                      
};

u_int8_t    TWVLongHaul15DB[25][5] =    
{
    {0x00, 0x2A, 0x09, 0x01, 0x00},     
    {0x00, 0x28, 0x08, 0x01, 0x00},     
    {0x00, 0x26, 0x08, 0x01, 0x00},     
    {0x00, 0x24, 0x07, 0x01, 0x00},     
    {0x01, 0x22, 0x07, 0x01, 0x00},     
    {0x02, 0x20, 0x06, 0x01, 0x00},     
    {0x04, 0x1E, 0x06, 0x01, 0x00},     
    {0x07, 0x1C, 0x05, 0x00, 0x00},     
    {0x0A, 0x1B, 0x05, 0x00, 0x00},     
    {0x0D, 0x19, 0x05, 0x00, 0x00},     
    {0x10, 0x18, 0x04, 0x00, 0x00},     
    {0x14, 0x16, 0x04, 0x00, 0x00},     
    {0x18, 0x15, 0x04, 0x00, 0x00},     
    {0x1B, 0x13, 0x03, 0x00, 0x00},     
    {0x1E, 0x12, 0x03, 0x00, 0x00},     
    {0x21, 0x10, 0x03, 0x00, 0x00},     
    {0x24, 0x0F, 0x03, 0x00, 0x00},     
    {0x27, 0x0D, 0x03, 0x00, 0x00},     
    {0x2A, 0x0D, 0x02, 0x00, 0x00},     
    {0x2D, 0x0B, 0x02, 0x00, 0x00},     
    {0x30, 0x0B, 0x02, 0x00, 0x00},     
    {0x30, 0x0A, 0x02, 0x00, 0x00},     
    {0x2E, 0x0A, 0x02, 0x00, 0x00},     
    {0x2C, 0x09, 0x02, 0x00, 0x00},     
    {0x03}                      
};

u_int8_t    TWVLongHaul22_5DB[25][5] =  
{
    {0x00, 0x1F, 0x16, 0x06, 0x01},     
    {0x00, 0x20, 0x15, 0x05, 0x01},     
    {0x00, 0x21, 0x15, 0x05, 0x01},     
    {0x00, 0x22, 0x14, 0x05, 0x01},     
    {0x00, 0x22, 0x13, 0x04, 0x00},     
    {0x00, 0x23, 0x12, 0x04, 0x00},     
    {0x01, 0x23, 0x12, 0x04, 0x00},     
    {0x01, 0x24, 0x11, 0x03, 0x00},     
    {0x01, 0x23, 0x10, 0x03, 0x00},     
    {0x02, 0x23, 0x10, 0x03, 0x00},     
    {0x03, 0x22, 0x0F, 0x03, 0x00},     
    {0x05, 0x22, 0x0E, 0x03, 0x00},     
    {0x07, 0x21, 0x0E, 0x02, 0x00},     
    {0x09, 0x20, 0x0D, 0x02, 0x00},     
    {0x0B, 0x1E, 0x0C, 0x02, 0x00},     
    {0x0E, 0x1D, 0x0C, 0x02, 0x00},     
    {0x10, 0x1B, 0x0B, 0x02, 0x00},     
    {0x13, 0x1B, 0x0A, 0x02, 0x00},     
    {0x15, 0x1A, 0x0A, 0x02, 0x00},     
    {0x17, 0x19, 0x09, 0x01, 0x00},     
    {0x19, 0x19, 0x08, 0x01, 0x00},     
    {0x1B, 0x18, 0x08, 0x01, 0x00},     
    {0x1D, 0x17, 0x07, 0x01, 0x00},     
    {0x1E, 0x17, 0x06, 0x01, 0x00},     
    {0x02}                      
};

u_int8_t    TWVShortHaul0[25][5] =      
{
    {0x00, 0x45, 0x00, 0x00, 0x00},     
    {0x0A, 0x44, 0x00, 0x00, 0x00},     
    {0x20, 0x43, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x3F, 0x42, 0x00, 0x00, 0x00},     
    {0x3F, 0x42, 0x00, 0x00, 0x00},     
    {0x3C, 0x41, 0x00, 0x00, 0x00},     
    {0x3B, 0x41, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x39, 0x00, 0x00, 0x00, 0x00},     
    {0x39, 0x00, 0x00, 0x00, 0x00},     
    {0x38, 0x00, 0x00, 0x00, 0x00},     
    {0x37, 0x00, 0x00, 0x00, 0x00},     
    {0x36, 0x00, 0x00, 0x00, 0x00},     
    {0x34, 0x00, 0x00, 0x00, 0x00},     
    {0x29, 0x00, 0x00, 0x00, 0x00},     
    {0x59, 0x00, 0x00, 0x00, 0x00},     
    {0x55, 0x00, 0x00, 0x00, 0x00},     
    {0x50, 0x00, 0x00, 0x00, 0x00},     
    {0x4D, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x48, 0x00, 0x00, 0x00, 0x00},     
    {0x46, 0x00, 0x00, 0x00, 0x00},     
    {0x46, 0x00, 0x00, 0x00, 0x00},     
    {0x0C}                      
};

u_int8_t    TWVShortHaul1[25][5] =      
{
    {0x00, 0x44, 0x00, 0x00, 0x00},     
    {0x0A, 0x44, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x36, 0x42, 0x00, 0x00, 0x00},     
    {0x34, 0x42, 0x00, 0x00, 0x00},     
    {0x30, 0x41, 0x00, 0x00, 0x00},     
    {0x2F, 0x41, 0x00, 0x00, 0x00},     
    {0x2E, 0x00, 0x00, 0x00, 0x00},     
    {0x2D, 0x00, 0x00, 0x00, 0x00},     
    {0x2C, 0x00, 0x00, 0x00, 0x00},     
    {0x2B, 0x00, 0x00, 0x00, 0x00},     
    {0x2A, 0x00, 0x00, 0x00, 0x00},     
    {0x28, 0x00, 0x00, 0x00, 0x00},     
    {0x26, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x68, 0x00, 0x00, 0x00, 0x00},     
    {0x54, 0x00, 0x00, 0x00, 0x00},     
    {0x4F, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x49, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x46, 0x00, 0x00, 0x00, 0x00},     
    {0x10}                      
};

u_int8_t    TWVShortHaul2[25][5] =      
{
    {0x00, 0x44, 0x00, 0x00, 0x00},     
    {0x0A, 0x44, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x3A, 0x43, 0x00, 0x00, 0x00},     
    {0x3A, 0x42, 0x00, 0x00, 0x00},     
    {0x38, 0x42, 0x00, 0x00, 0x00},     
    {0x30, 0x41, 0x00, 0x00, 0x00},     
    {0x2F, 0x41, 0x00, 0x00, 0x00},     
    {0x2E, 0x00, 0x00, 0x00, 0x00},     
    {0x2D, 0x00, 0x00, 0x00, 0x00},     
    {0x2C, 0x00, 0x00, 0x00, 0x00},     
    {0x2B, 0x00, 0x00, 0x00, 0x00},     
    {0x2A, 0x00, 0x00, 0x00, 0x00},     
    {0x29, 0x00, 0x00, 0x00, 0x00},     
    {0x23, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x6C, 0x00, 0x00, 0x00, 0x00},     
    {0x60, 0x00, 0x00, 0x00, 0x00},     
    {0x4F, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x49, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x46, 0x00, 0x00, 0x00, 0x00},     
    {0x11}                      
};

u_int8_t    TWVShortHaul3[25][5] =      
{
    {0x00, 0x44, 0x00, 0x00, 0x00},     
    {0x0A, 0x44, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x3F, 0x42, 0x00, 0x00, 0x00},     
    {0x3F, 0x42, 0x00, 0x00, 0x00},     
    {0x2F, 0x41, 0x00, 0x00, 0x00},     
    {0x2E, 0x41, 0x00, 0x00, 0x00},     
    {0x2D, 0x00, 0x00, 0x00, 0x00},     
    {0x2C, 0x00, 0x00, 0x00, 0x00},     
    {0x2B, 0x00, 0x00, 0x00, 0x00},     
    {0x2A, 0x00, 0x00, 0x00, 0x00},     
    {0x29, 0x00, 0x00, 0x00, 0x00},     
    {0x28, 0x00, 0x00, 0x00, 0x00},     
    {0x19, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x7F, 0x00, 0x00, 0x00, 0x00},     
    {0x60, 0x00, 0x00, 0x00, 0x00},     
    {0x4F, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x49, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x46, 0x00, 0x00, 0x00, 0x00},     
    {0x12}                      
};

u_int8_t    TWVShortHaul4[25][5] =      
{
    {0x00, 0x44, 0x00, 0x00, 0x00},     
    {0x0A, 0x44, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x3F, 0x42, 0x00, 0x00, 0x00},     
    {0x3F, 0x42, 0x00, 0x00, 0x00},     
    {0x30, 0x41, 0x00, 0x00, 0x00},     
    {0x2B, 0x41, 0x00, 0x00, 0x00},     
    {0x2A, 0x00, 0x00, 0x00, 0x00},     
    {0x29, 0x00, 0x00, 0x00, 0x00},     
    {0x28, 0x00, 0x00, 0x00, 0x00},     
    {0x27, 0x00, 0x00, 0x00, 0x00},     
    {0x26, 0x00, 0x00, 0x00, 0x00},     
    {0x26, 0x00, 0x00, 0x00, 0x00},     
    {0x24, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x7F, 0x00, 0x00, 0x00, 0x00},     
    {0x7F, 0x00, 0x00, 0x00, 0x00},     
    {0x4F, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x49, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x46, 0x00, 0x00, 0x00, 0x00},     
    {0x14}                      
};

u_int8_t    TWVShortHaul5[25][5] =      
{
    {0x00, 0x44, 0x00, 0x00, 0x00},     
    {0x0A, 0x44, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x3F, 0x43, 0x00, 0x00, 0x00},     
    {0x3F, 0x42, 0x00, 0x00, 0x00},     
    {0x3F, 0x42, 0x00, 0x00, 0x00},     
    {0x3F, 0x41, 0x00, 0x00, 0x00},     
    {0x30, 0x41, 0x00, 0x00, 0x00},     
    {0x2A, 0x00, 0x00, 0x00, 0x00},     
    {0x29, 0x00, 0x00, 0x00, 0x00},     
    {0x28, 0x00, 0x00, 0x00, 0x00},     
    {0x27, 0x00, 0x00, 0x00, 0x00},     
    {0x26, 0x00, 0x00, 0x00, 0x00},     
    {0x25, 0x00, 0x00, 0x00, 0x00},     
    {0x24, 0x00, 0x00, 0x00, 0x00},     
    {0x4A, 0x00, 0x00, 0x00, 0x00},     
    {0x7F, 0x00, 0x00, 0x00, 0x00},     
    {0x7F, 0x00, 0x00, 0x00, 0x00},     
    {0x5F, 0x00, 0x00, 0x00, 0x00},     
    {0x50, 0x00, 0x00, 0x00, 0x00},     
    {0x49, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x47, 0x00, 0x00, 0x00, 0x00},     
    {0x46, 0x00, 0x00, 0x00, 0x00},     
    {0x15}                      
};

u_int8_t    TWV_E1_120Ohm[25][5] =      
{
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x0A, 0x00, 0x00, 0x00, 0x00},     
    {0x3F, 0x00, 0x00, 0x00, 0x00},     
    {0x3F, 0x00, 0x00, 0x00, 0x00},     
    {0x39, 0x00, 0x00, 0x00, 0x00},     
    {0x38, 0x00, 0x00, 0x00, 0x00},     
    {0x36, 0x00, 0x00, 0x00, 0x00},     
    {0x36, 0x00, 0x00, 0x00, 0x00},     
    {0x35, 0x00, 0x00, 0x00, 0x00},     
    {0x35, 0x00, 0x00, 0x00, 0x00},     
    {0x35, 0x00, 0x00, 0x00, 0x00},     
    {0x35, 0x00, 0x00, 0x00, 0x00},     
    {0x35, 0x00, 0x00, 0x00, 0x00},     
    {0x35, 0x00, 0x00, 0x00, 0x00},     
    {0x2D, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x0C}                      
};



u_int8_t    TWV_E1_75Ohm[25][5] =       
{
#ifdef PMCC4_DOES_NOT_SUPPORT
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x0A, 0x00, 0x00, 0x00, 0x00},     
    {0x28, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x3A, 0x00, 0x00, 0x00, 0x00},     
    {0x32, 0x00, 0x00, 0x00, 0x00},     
    {0x14, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
    {0x00, 0x00, 0x00, 0x00, 0x00},     
#endif
    {0x0C}                      
};


u_int32_t T1_Equalizer[256] =   
{
    0x03FE1840, 0x03F61840, 0x03EE1840, 0x03E61840,     
        0x03DE1840, 0x03D61840, 0x03D61840, 0x03D61840, 
        0x03CE1840, 0x03CE1840, 0x03CE1840, 0x03CE1840, 
        0x03C61840, 0x03C61840, 0x03C61840, 0x0BBE1840, 
        0x0BBE1840, 0x0BBE1840, 0x0BBE1840, 0x0BB61840, 
        0x0BB61840, 0x0BB61840, 0x0BB61840, 0x13AE1838, 
        0x13AE183C, 0x13AE1840, 0x13AE1840, 0x13AE1840, 
        0x13AE1840, 0x1BB618B8, 0x1BAE18B8, 0x1BAE18BC, 
        0x1BAE18C0, 0x1BAE18C0, 0x23A618C0, 0x23A618C0, 
        0x23A618C0, 0x23A618C0, 0x23A618C0, 0x239E18C0, 
        0x239E18C0, 0x239E18C0, 0x239E18C0, 0x239E18C0, 
        0x2B9618C0, 0x2B9618C0, 0x2B9618C0, 0x33961940, 
        0x37961940, 0x37961940, 0x37961940, 0x3F9E19C0, 
        0x3F9E19C0, 0x3F9E19C0, 0x3FA61A40, 0x3FA61A40, 
        0x3FA61A40, 0x3FA61A40, 0x3F9619C0, 0x3F9619C0, 
        0x3F9619C0, 0x3F9619C0, 0x479E1A40, 0x479E1A40, 
        0x479E1A40, 0x47961A40, 0x47961A40, 0x47961A40, 
        0x47961A40, 0x4F8E1A40, 0x4F8E1A40, 0x4F8E1A40, 
        0x4F8E1A40, 0x4F8E1A40, 0x57861A40, 0x57861A40, 
        0x57861A40, 0x57861A40, 0x57861A40, 0x5F861AC0, 
        0x5F861AC0, 0x5F861AC0, 0x5F861AC0, 0x5F861AC0, 
        0x5F861AC0, 0x5F7E1AC0, 0x5F7E1AC0, 0x5F7E1AC0, 
        0x5F7E1AC0, 0x5F7E1AC0, 0x677E2AC0, 0x677E2AC0, 
        0x677E2AC0, 0x677E2AC0, 0x67762AC0, 0x67762AC0, 
        0x67762AC0, 0x67762AC0, 0x67762AC0, 0x6F6E2AC0, 
        0x6F6E2AC0, 0x6F6E2AC0, 0x6F6E2AC0, 0x776E3AC0, 
        0x776E3AC0, 0x776E3AC0, 0x776E3AC0, 0x7F663AC0, 
        0x7F663AC0, 0x7F664AC0, 0x7F664AC0, 0x7F664AC0, 
        0x7F664AC0, 0x87665AC0, 0x87665AC0, 0x87665AC0, 
        0x87665AC0, 0x87665AC0, 0x875E5AC0, 0x875E5AC0, 
        0x875E5AC0, 0x875E5AC0, 0x875E5AC0, 0x8F5E6AC0, 
        0x8F5E6AC0, 0x8F5E6AC0, 0x8F5E6AC0, 0x975E7AC0, 
        0x975E7AC0, 0x975E7AC0, 0x975E7AC0, 0x9F5E8AC0, 
        0x9F5E8AC0, 0x9F5E8AC0, 0x9F5E8AC0, 0x9F5E8AC0, 
        0xA7569AC0, 0xA7569AC0, 0xA7569AC0, 0xA7569AC0, 
        0xA756AAC0, 0xA756AAC0, 0xA756AAC0, 0xAF4EAAC0, 
        0xAF4EAAC0, 0xAF4EAAC0, 0xAF4EAAC0, 0xAF4EAAC0, 
        0xB746AAC0, 0xB746AAC0, 0xB746AAC0, 0xB746AAC0, 
        0xB746AAC0, 0xB746AAC0, 0xB746AAC0, 0xB746BAC0, 
        0xB746BAC0, 0xB746BAC0, 0xBF4EBB40, 0xBF4EBB40, 
        0xBF4EBB40, 0xBF4EBB40, 0xBF4EBB40, 0xBF4EBB40, 
        0xBF4EBB40, 0xBF4EBB40, 0xBF4EBB40, 0xBE46CB40, 
        0xBE46CB40, 0xBE46CB40, 0xBE46CB40, 0xBE46CB40, 
        0xBE46CB40, 0xBE46DB40, 0xBE46DB40, 0xBE46DB40, 
        0xC63ECB40, 0xC63ECB40, 0xC63EDB40, 0xC63EDB40, 
        0xC63EDB40, 0xC644DB40, 0xC644DB40, 0xC644DB40, 
        0xC644DB40, 0xC63CDB40, 0xC63CDB40, 0xC63CDB40, 
        0xC63CDB40, 0xD634DB40, 0xD634DB40, 0xD634DB40, 
        0xD634DB40, 0xD634DB40, 0xDE2CDB3C, 0xDE2CDB3C, 
        0xDE2CDB3C, 0xE62CDB40, 0xE62CDB40, 0xE62CDB40, 
        0xE62CDB40, 0xE62CDB40, 0xE62CEB40, 0xE62CEB40, 
        0xE62CEB40, 0xEE2CFB40, 0xEE2CFB40, 0xEE2CFB40, 
        0xEE2D0B40, 0xEE2D0B40, 0xEE2D0B40, 0xEE2D0B40, 
        0xEE2D0B40, 0xF5250B38, 0xF5250B3C, 0xF5250B40, 
        0xF5251B40, 0xF5251B40, 0xF5251B40, 0xF5251B40, 
        0xF5251B40, 0xFD252B40, 0xFD252B40, 0xFD252B40, 
        0xFD252B40, 0xFD252740, 0xFD252740, 0xFD252740, 
        0xFD252340, 0xFD252340, 0xFD252340, 0xFD253340, 
        0xFD253340, 0xFD253340, 0xFD253340, 0xFD253340, 
        0xFD253340, 0xFD253340, 0xFD253340, 0xFC254340, 
        0xFD254340, 0xFD254340, 0xFD254344, 0xFC254348, 
        0xFC25434C, 0xFD2543BC, 0xFD2543C0, 0xFC2543C0, 
        0xFC2343C0, 0xFC2343C0, 0xFD2343C0, 0xFC2143C0, 
        0xFC2143C0, 0xFC2153C0, 0xFD2153C0, 0xFC2153C0  
};


u_int32_t   E1_Equalizer[256] = 
{
    0x07DE182C, 0x07DE182C, 0x07D6182C, 0x07D6182C,     
    0x07D6182C, 0x07CE182C, 0x07CE182C, 0x07CE182C,     
    0x07C6182C, 0x07C6182C, 0x07C6182C, 0x07BE182C,     
    0x07BE182C, 0x07BE182C, 0x07BE182C, 0x07BE182C,     
    0x07B6182C, 0x07B6182C, 0x07B6182C, 0x07B6182C,     
    0x07B6182C, 0x07AE182C, 0x07AE182C, 0x07AE182C,     
    0x07AE182C, 0x07AE182C, 0x07B618AC, 0x07AE18AC,     
    0x07AE18AC, 0x07AE18AC, 0x07AE18AC, 0x07A618AC,     
    0x07A618AC, 0x07A618AC, 0x07A618AC, 0x079E18AC,     
    0x07A6192C, 0x07A6192C, 0x07A6192C, 0x0FA6192C,     
    0x0FA6192C, 0x0F9E192C, 0x0F9E192C, 0x0F9E192C,     
    0x179E192C, 0x17A619AC, 0x179E19AC, 0x179E19AC,     
    0x179619AC, 0x1F9619AC, 0x1F9619AC, 0x1F8E19AC,     
    0x1F8E19AC, 0x1F8E19AC, 0x278E19AC, 0x278E1A2C,     
    0x278E1A2C, 0x278E1A2C, 0x278E1A2C, 0x2F861A2C,     
    0x2F861A2C, 0x2F861A2C, 0x2F7E1A2C, 0x2F7E1A2C,     
    0x2F7E1A2C, 0x377E1A2C, 0x377E1AAC, 0x377E1AAC,     
    0x377E1AAC, 0x377E1AAC, 0x3F7E2AAC, 0x3F7E2AAC,     
    0x3F762AAC, 0x3F862B2C, 0x3F7E2B2C, 0x477E2B2C,     
    0x477E2F2C, 0x477E2F2C, 0x477E2F2C, 0x47762F2C,     
    0x4F762F2C, 0x4F762F2C, 0x4F6E2F2C, 0x4F6E2F2C,     
    0x4F6E2F2C, 0x576E2F2C, 0x576E2F2C, 0x576E3F2C,     
    0x576E3F2C, 0x576E3F2C, 0x5F6E3F2C, 0x5F6E4F2C,     
    0x5F6E4F2C, 0x5F6E4F2C, 0x5F664F2C, 0x67664F2C,     
    0x67664F2C, 0x675E4F2C, 0x675E4F2C, 0x67664F2C,     
    0x67664F2C, 0x67665F2C, 0x6F6E5F2C, 0x6F6E6F2C,     
    0x6F6E6F2C, 0x6F6E7F2C, 0x6F6E7F2C, 0x6F6E7F2C,     
    0x77667F2C, 0x77667F2C, 0x775E6F2C, 0x775E7F2C,     
    0x775E7F2C, 0x7F5E7F2C, 0x7F5E8F2C, 0x7F5E8F2C,     
    0x7F5E8F2C, 0x87568F2C, 0x87568F2C, 0x87568F2C,     
    0x874E8F2C, 0x874E8F2C, 0x874E8F2C, 0x8F4E9F2C,     
    0x8F4E9F2C, 0x8F4EAF2C, 0x8F4EAF2C, 0x8F4EAF2C,     
    0x974EAF2C, 0x974EAF2C, 0x974EAB2C, 0x974EAB2C,     
    0x974EAB2C, 0x9F4EAB2C, 0x9F4EBB2C, 0x9F4EBB2C,     
    0x9F4EBB2C, 0x9F4ECB2C, 0xA74ECB2C, 0xA74ECB2C,     
    0xA746CB2C, 0xA746CB2C, 0xA746CB2C, 0xA746DB2C,     
    0xAF46DB2C, 0xAF46EB2C, 0xAF46EB2C, 0xAF4EEB2C,     
    0xAE4EEB2C, 0xAE4EEB2C, 0xB546FB2C, 0xB554FB2C,     
    0xB54CEB2C, 0xB554FB2C, 0xB554FB2C, 0xBD54FB2C,     
    0xBD4CFB2C, 0xBD4CFB2C, 0xBD4CFB2C, 0xBD44EB2C,     
    0xC544FB2C, 0xC544FB2C, 0xC544FB2C, 0xC5450B2C,     
    0xC5450B2C, 0xC5450B2C, 0xCD450B2C, 0xCD450B2C,     
    0xCD3D0B2C, 0xCD3D0B2C, 0xCD3D0B2C, 0xD53D0B2C,     
    0xD53D0B2C, 0xD53D1B2C, 0xD53D1B2C, 0xD53D1B2C,     
    0xDD3D1B2C, 0xDD3D1B2C, 0xDD351B2C, 0xDD351B2C,     
    0xDD351B2C, 0xE5351B2C, 0xE5351B2C, 0xE52D1B2C,     
    0xE52D1B2C, 0xE52D3B2C, 0xED2D4B2C, 0xED2D1BA8,     
    0xED2D1BAC, 0xED2D17AC, 0xED2D17AC, 0xED2D27AC,     
    0xF52D27AC, 0xF52D27AC, 0xF52D2BAC, 0xF52D2BAC,     
    0xF52D2BAC, 0xFD2D2BAC, 0xFD2B2BAC, 0xFD2B2BAC,     
    0xFD2B2BAC, 0xFD2B2BAC, 0xFD232BAC, 0xFD232BAC,     
    0xFD232BAC, 0xFD212BAC, 0xFD212BAC, 0xFD292BAC,     
    0xFD292BAC, 0xFD2927AC, 0xFD2937AC, 0xFD2923AC,     
    0xFD2923AC, 0xFD2923AC, 0xFD2923AC, 0xFD2123AC,     
    0xFD2123AC, 0xFD2123AC, 0xFD2133AC, 0xFD2133AC,     
    0xFD2133AC, 0xFD2143AC, 0xFD2143AC, 0xFD2143AC,     
    0xFC2143AC, 0xFC2143AC, 0xFC1943AC, 0xFC1943AC,     
    0xFC1943AC, 0xFC1943AC, 0xFC1953AC, 0xFC1953AC,     
    0xFC1953AC, 0xFC1953AC, 0xFC1963AC, 0xFC1963AC,     
    0xFC1963AC, 0xFC1973AC, 0xFC1973AC, 0xFC1973AC,     
    0xFC1973AC, 0xFC1973AC, 0xFC1983AC, 0xFC1983AC,     
    0xFC1983AC, 0xFC1983AC, 0xFC1983AC, 0xFC1993AC,     
    0xFC1993AC, 0xFC1993AC, 0xFC19A3AC, 0xFC19A3AC,     
    0xFC19B3AC, 0xFC19B3AC, 0xFC19B3AC, 0xFC19B3AC      
};

