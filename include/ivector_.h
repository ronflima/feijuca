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
 $Id: ivector_.h,v 1.1 2006-01-30 10:18:08 harq_al_ada Exp $
*/

#ifndef IVECTOR__H
#define IVECTOR__H

#include <stddef.h>
#include "gacommon.h"
#include "gainternal_.h"

GABEGINDECLS
/*
 * Constants
 */
enum
{ 
  GA_IVECTOR_SIGNATURE = (ga_magic_t) 0xFADEBAD4u, /* Signature */
  IVECTOR_CHUNKSIZE    = (size_t) 10 /* Default chunk size = 10 elements */
};

/*
 * Datatypes
 */
/* Infinite vector descriptor */
struct ivector_t
{
  void *data_;			/* Vector data */
  size_t size_;			/* Vector size */
  size_t datalen_;		/* Size of each vector element */
  size_t chunksize_;            /* Size of memory chunk to allocate */
  size_t chunksused_;           /* Chunks used */
  size_t elemused_;             /* Elements used in chunk */
  compare_t *comp_;		/* Comparison function */
  ga_magic_t signature_;        /* Signature of the descriptor */
};

GAENDDECLS

#endif /* IVECTOR__H */
