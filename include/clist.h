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

 Description: Interfaces and datatypes for single linked circular lists

 CVS Information
 $Author: harq_al_ada $
 $Id: clist.h,v 1.17 2006-06-12 09:51:15 harq_al_ada Exp $
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
typedef struct clist_t * clist_t;

/*
 * Prototypes
 */
GAERROR (clist_init) __P ((clist_t *, deallocator_t *));
GAERROR (clist_destroy) __P ((clist_t));
GAERROR (clist_del) __P ((clist_t, void **, position_t));
GAERROR (clist_get) __P ((clist_t, void **, position_t));
int (clist_move) __P ((clist_t, position_t));
int (clist_insert) __P ((clist_t, const void *, position_t));
int (clist_size) __P ((clist_t, size_t *));
int (clist_get_pos) __P((clist_t, position_t *));

GAENDDECLS
#endif /* CLIST_H */
