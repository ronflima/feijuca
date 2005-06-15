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
 $Id: ivector.h,v 1.16 2005-06-15 11:03:17 ron_lima Exp $
*/

#ifndef IVECTOR_H
#define IVECTOR_H

#include <stdio.h>
#include "gacommon.h"

GABEGINDECLS
/*
 * Macros
 */
#define GA_IVECTOR_SIGNATURE (ga_magic_t)0xFADEBAD4
/*
 * Datatypes
 */
/* Infinite vector descriptor */
typedef struct ivector_t
{
  void *data_;			/* Vector data */
  size_t size_;			/* Vector size */
  size_t datalen_;		/* Size of each vector element */
  compare_t *comp_;		/* Comparison function */
  deallocator_t *dealloc_;	/* Deallocation function */
  ga_magic_t signature_;        /* Signature of the descriptor */
}
ivector_t;

/*
 * Prototypes
 */
int (ivector_init) __P ((ivector_t *, compare_t *, deallocator_t *, size_t));
int (ivector_destroy) __P ((ivector_t *));
int (ivector_get) __P ((ivector_t *, void **, size_t));
int (ivector_put) __P ((ivector_t *, size_t, const void *));
int (ivector_add) __P ((ivector_t *, const void *));
int (ivector_qsort) __P ((ivector_t *));
int (ivector_bsearch) __P ((ivector_t *, void **, const void *));
int (ivector_del) __P ((ivector_t *, size_t));

GAENDDECLS

#endif /* IVECTOR_H */
