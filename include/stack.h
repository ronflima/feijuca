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
 $Id: stack.h,v 1.1 2004-04-20 11:05:54 ron_lima Exp $
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
#define stack_alloc(stack)      list_alloc ((list_t **) stack)
#define stack_free(stack)       list_free  ((list_t *) stack)
#define stack_pop(stack, data)  list_del   ((list_t *)stack, data)
#define stack_push(stack, data) list_insert((list_t *)stack, data)
#ifdef __cplusplus
}
#endif
#endif /* IVECTOR_H */
