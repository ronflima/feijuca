/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This library is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as
 published by the Free Software Foundation; either version 2.1 of the
 License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
 USA

 System: G.A. Lib

 Description: Interfaces and datatypes for stacks

 CVS Information
 $Author: harq_al_ada $
 $Id: stack.h,v 1.13 2006-01-29 12:37:02 harq_al_ada Exp $
*/

#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include "gacommon.h"
#include "list.h"

GABEGINDECLS

/*
 * Datatypes
 */
typedef struct stack_t * stack_t;

/*
 * Prototypes
 */
int (stack_init) __P ((stack_t *, deallocator_t *));
int (stack_destroy) __P ((stack_t));
int (stack_pop) __P ((stack_t, void **));
int (stack_push) __P ((stack_t, const void *));
int (stack_size) __P((stack_t, size_t *));

GAENDDECLS
#endif /* STACK_H */
