/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of G.A. Lib.

 G.A. Lib is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 G.A. Lib is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with G.A. Lib; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: G.A. Lib

 Description: Interfaces and datatypes for stacks

 CVS Information
 $Author: ron_lima $
 $Id: stack.h,v 1.4 2004-06-09 00:55:20 ron_lima Exp $
*/
 
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include "gacommon.h"
#include "list.h"

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Datatypes
 */
typedef list_t stack_t;

/* 
 * Prototypes 
 */
extern int
(stack_alloc) (stack_t ** stack, deallocator_t * dealloc);
extern int
(stack_free) (stack_t ** stack);
extern int
(stack_pop) (stack_t * stack, void **data);
extern int 
(stack_push) (stack_t * stack, const void *data);
#ifdef __cplusplus
}
#endif
#endif /* STACK_H */
