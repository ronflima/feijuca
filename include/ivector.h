/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of G.A. Lib.

 G.A. Lib is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 G.A. Lib is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with G.A. Lib; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: G.A. Lib

 Description: Interfaces and datatypes for infinite vectors

 CVS Information
 $Author: ron_lima $
 $Id: ivector.h,v 1.3 2004-04-11 12:03:33 ron_lima Exp $
*/
 
#ifndef IVECTOR_H
#define IVECTOR_H

#include <stdio.h>
#include "gacommon.h"

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Datatypes
 */
/* Infinite vector descriptor */
typedef struct ivector_
{
    void * data_;               /* Vector data */
    size_t size_;               /* Size of the vector */
    size_t datalen_;            /* Size of each vector element */
    compare_t comp_;            /* Comparison function */
} ivector_t;

/* 
 * Prototypes 
 */
extern int
(ivector_alloc) (ivector_t ** vector, compare_t comp, size_t datalen);
extern void
(ivector_free) (ivector_t * vector);
extern void *
(ivector_get) (ivector_t * vector, size_t idx);
extern int
(ivector_put) (ivector_t * vector, size_t idx, const void * data);
extern int 
(ivector_add) (ivector_t * vector, const void * data);
extern int
(ivector_qsort) (ivector_t * vector);
extern void *
(ivector_bsearch) (ivector_t * vector, const void * data);
extern int
(ivector_del) (ivector_t * vector, size_t idx);

#ifdef __cplusplus
}
#endif

#endif /* IVECTOR_H */
