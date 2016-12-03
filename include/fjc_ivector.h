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

#ifndef FJC_IVECTOR_H
#define FJC_IVECTOR_H

#include <stddef.h>
#include "fjc_common.h"

FJC_BEGINDECLS
/*
 * Datatypes
 */
/* Infinite vector descriptor */
typedef struct fjc_ivector_t * fjc_ivector_t;

/*
 * Prototypes
 */
fjc_error_t (fjc_ivector_init)    __P ((fjc_ivector_t *, fjc_compare_t *, size_t));
fjc_error_t (fjc_ivector_destroy) __P ((fjc_ivector_t));
fjc_error_t (fjc_ivector_get)     __P ((fjc_ivector_t, void **, size_t));
fjc_error_t (fjc_ivector_put)     __P ((fjc_ivector_t, size_t, const void *));
fjc_error_t (fjc_ivector_add)     __P ((fjc_ivector_t, const void *));
fjc_error_t (fjc_ivector_qsort)   __P ((fjc_ivector_t));
fjc_error_t (fjc_ivector_bsearch) __P ((fjc_ivector_t, void **, const void *));
fjc_error_t (fjc_ivector_del)     __P ((fjc_ivector_t, size_t));
fjc_error_t (fjc_ivector_size)    __P ((fjc_ivector_t, size_t *));

FJC_ENDDECLS

#endif /* FJC_IVECTOR_H */
