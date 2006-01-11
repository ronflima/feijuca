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

 Description: Interfaces and datatypes for double-linked circular lists.
 
 CVS Information
 $Author: harq_al_ada $
 $Id: dclist.h,v 1.4 2006-01-11 10:05:53 harq_al_ada Exp $
*/

#ifndef DCLIST_H
#define DCLIST_H

#include <stddef.h>
#include "gacommon.h"
#include "dlist.h"

GABEGINDECLS
/*
 * Constants
 */
enum 
{
  GA_DCLIST_SIGNATURE = 0x5EEDDEAFu
};

/*
 * Datatypes
 */
typedef struct dclist_t
{
  ga_magic_t signature_;
  dlist_t list_;
}dclist_t;

/*
 * Prototypes
 */
int (dclist_init) __P ((dclist_t *, deallocator_t *));
int (dclist_destroy) __P ((dclist_t *));
int (dclist_get) __P ((dclist_t *, void **, position_t));
int (dclist_insert) __P ((dclist_t *, const void *, position_t));
int (dclist_move) __P ((dclist_t *, position_t));
int (dclist_del) __P ((dclist_t *, void **, position_t));
int (dclist_size) __P ((dclist_t *, size_t *));

GAENDDECLS
#endif /* DCLIST_H */
