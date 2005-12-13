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
 $Author: ron_lima $
 $Id: deque.h,v 1.3 2005-12-13 10:18:50 ron_lima Exp $
*/

#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include "gacommon.h"
#include "dlist.h"

GABEGINDECLS
/*
 * Constants
 */
enum 
{
  GA_DEQUE_SIGNATURE = 0xD00DBEEFu
};

/*
 * Datatypes
 */
typedef struct deque_t 
{ 
  ga_magic_t signature_;
  dlist_t list_;
} deque_t;

/*
 * Prototypes
 */
int (deque_init) __P ((deque_t *, deallocator_t *));
int (deque_destroy) __P ((deque_t *));
int (deque_pop) __P ((deque_t *, void **, position_t));
int (deque_push) __P ((deque_t *, const void *, position_t));

GAENDDECLS
#endif /* DEQUE_H */
