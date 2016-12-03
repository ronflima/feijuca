/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 Contributed code by Daniel Costa Soares <daniel_csoares@yahoo.com.br>

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

 Description: Interfaces and datatypes for deques (Double Ended QUEue)

 CVS Information
 $Author: harq_al_ada $
 $Id: deque.h,v 1.5 2006-01-29 19:24:13 harq_al_ada Exp $
*/

#ifndef FJC_DEQUE_H
#define FJC_DEQUE_H

#include <stddef.h>
#include "fjc_common.h"
#include "fjc_dlist.h"

FJC_BEGINDECLS
/*
 * Datatypes
 */
typedef struct fjc_deque_t * fjc_deque_t;

/*
 * Prototypes
 */
int (fjc_deque_init)    __P ((fjc_deque_t *, fjc_deallocator_t *));
int (fjc_deque_destroy) __P ((fjc_deque_t));
int (fjc_deque_pop)     __P ((fjc_deque_t, void **, fjc_position_t));
int (fjc_deque_push)    __P ((fjc_deque_t, const void *, fjc_position_t));
int (fjc_deque_size)    __P ((fjc_deque_t, size_t *));

FJC_ENDDECLS
#endif /* FJC_DEQUE_H */
