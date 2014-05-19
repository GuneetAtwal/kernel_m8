/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 1995, 1999, 2002 by Ralf Baechle
 */
#ifndef _ASM_MMAN_H
#define _ASM_MMAN_H

#define PROT_NONE	0x00		
#define PROT_READ	0x01		
#define PROT_WRITE	0x02		/* page can be written */
#define PROT_EXEC	0x04		
#define PROT_SEM	0x10		
#define PROT_GROWSDOWN	0x01000000	
#define PROT_GROWSUP	0x02000000	

#define MAP_SHARED	0x001		
#define MAP_PRIVATE	0x002		
#define MAP_TYPE	0x00f		
#define MAP_FIXED	0x010		

#define MAP_RENAME	0x020		
#define MAP_AUTOGROW	0x040		
#define MAP_LOCAL	0x080		
#define MAP_AUTORSRV	0x100		

#define MAP_NORESERVE	0x0400		
#define MAP_ANONYMOUS	0x0800		
#define MAP_GROWSDOWN	0x1000		
#define MAP_DENYWRITE	0x2000		
#define MAP_EXECUTABLE	0x4000		
#define MAP_LOCKED	0x8000		
#define MAP_POPULATE	0x10000		
#define MAP_NONBLOCK	0x20000		
#define MAP_STACK	0x40000		
#define MAP_HUGETLB	0x80000		

#define MS_ASYNC	0x0001		
#define MS_INVALIDATE	0x0002		
#define MS_SYNC		0x0004		

#define MCL_CURRENT	1		
#define MCL_FUTURE	2		

#define MADV_NORMAL	0		
#define MADV_RANDOM	1		
#define MADV_SEQUENTIAL	2		
#define MADV_WILLNEED	3		
#define MADV_DONTNEED	4		

#define MADV_REMOVE	9		
#define MADV_DONTFORK	10		
#define MADV_DOFORK	11		

#define MADV_MERGEABLE   12		
#define MADV_UNMERGEABLE 13		
#define MADV_HWPOISON    100		

#define MADV_HUGEPAGE	14		
#define MADV_NOHUGEPAGE	15		

#define MADV_DONTDUMP   16		
#define MADV_DODUMP	17		

#define MAP_FILE	0

#endif 
