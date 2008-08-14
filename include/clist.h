/* -*-c-*-
 Feijuca Library - A generic algorithms and data structures library
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

 System: Feijuca Lib

 Description: Interfaces and datatypes for single linked circular lists
*/
#ifndef CLIST_H
#define CLIST_H

#include <stddef.h>
#include "list.h"
#include "gacommon.h"

GABEGINDECLS

/*
 * Datatypes
 */
/*
 * Abstraction for the list descriptor 
 */
typedef list_t clist_t;

/*
 * Prototypes
 */
clist_t (clist_init) __P ((deallocator_t *));
void (clist_destroy) __P ((clist_t));
GAERROR (clist_del) __P ((clist_t, void **, position_t));
GAERROR (clist_get) __P ((clist_t, void **, position_t));
GAERROR (clist_move) __P ((clist_t, position_t));
GAERROR (clist_insert) __P ((clist_t, const void *, position_t));
size_t (clist_get_size) __P ((clist_t));
position_t (clist_get_pos) __P((clist_t));

GAENDDECLS
#endif /* CLIST_H */
