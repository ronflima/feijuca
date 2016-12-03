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
*/

#ifndef FJC_DCLIST_H
#define FJC_DCLIST_H

#include <stddef.h>
#include "fjc_common.h"
#include "fjc_dlist.h"

FJC_BEGINDECLS

/*
 * Data types
 */
typedef struct fjc_dclist_t * fjc_dclist_t;

/*
 * Prototypes
 */
fjc_error_t (fjc_dclist_init)    __P ((fjc_dclist_t *, fjc_deallocator_t *));
fjc_error_t (fjc_dclist_destroy) __P ((fjc_dclist_t));
fjc_error_t (fjc_dclist_get)     __P ((fjc_dclist_t, void **, fjc_position_t));
fjc_error_t (fjc_dclist_insert)  __P ((fjc_dclist_t, const void *, fjc_position_t));
fjc_error_t (fjc_dclist_move)    __P ((fjc_dclist_t, fjc_position_t));
fjc_error_t (fjc_dclist_del)     __P ((fjc_dclist_t, void **, fjc_position_t));
fjc_error_t (fjc_dclist_size)    __P ((fjc_dclist_t, size_t *));

FJC_ENDDECLS

#endif /* FJC_DCLIST_H */
