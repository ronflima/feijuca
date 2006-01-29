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

 Description: Interfaces and datatypes for infinite vectors

 CVS Information
 $Author: harq_al_ada $
 $Id: ivector.h,v 1.22 2006-01-29 20:03:12 harq_al_ada Exp $
*/

#ifndef IVECTOR_H
#define IVECTOR_H

#include <stddef.h>
#include "gacommon.h"

GABEGINDECLS
/*
 * Datatypes
 */
/* Infinite vector descriptor */
typedef struct ivector_t * ivector_t;

/*
 * Prototypes
 */
int (ivector_init) __P ((ivector_t *, compare_t *, size_t));
int (ivector_destroy) __P ((ivector_t));
int (ivector_get) __P ((ivector_t, void **, size_t));
int (ivector_put) __P ((ivector_t, size_t, const void *));
int (ivector_add) __P ((ivector_t, const void *));
int (ivector_qsort) __P ((ivector_t));
int (ivector_bsearch) __P ((ivector_t, void **, const void *));
int (ivector_del) __P ((ivector_t, size_t));
int (ivector_size) __P ((ivector_t, size_t *));

GAENDDECLS

#endif /* IVECTOR_H */
