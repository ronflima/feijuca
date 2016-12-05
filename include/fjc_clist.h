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
#ifndef FJC_CLIST_H
#define FJC_CLIST_H

#include <stddef.h>
#include "fjc_list.h"
#include "fjc_common.h"

FJC_BEGINDECLS

/*
 * Datatypes
 */
/*
 * Abstraction for the list descriptor 
 */
typedef fjc_list_t fjc_clist_t;

/*
 * Prototypes
 */
fjc_error_t    (fjc_clist_init)     __P ((fjc_clist_t *, fjc_deallocator_t *));
fjc_error_t    (fjc_clist_destroy)  __P ((fjc_clist_t));
fjc_error_t    (fjc_clist_del)      __P ((fjc_clist_t, const void **, fjc_position_t));
fjc_error_t    (fjc_clist_get)      __P ((fjc_clist_t, const void **, fjc_position_t));
fjc_error_t    (fjc_clist_move)     __P ((fjc_clist_t, fjc_position_t));
fjc_error_t    (fjc_clist_insert)   __P ((fjc_clist_t, const void *, fjc_position_t));
fjc_error_t    (fjc_clist_get_size) __P ((fjc_clist_t, size_t *));
fjc_error_t    (fjc_clist_get_pos)  __P ((fjc_clist_t, fjc_position_t *));

FJC_ENDDECLS
#endif /* FJC_CLIST_H */
