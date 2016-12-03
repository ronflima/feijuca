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
 $Id: fjc_ivector_.h,v 1.2 2007-06-24 23:57:17 harq_al_ada Exp $
*/

#ifndef FJC_IVECTOR__H
#define FJC_IVECTOR__H

#include <stddef.h>
#include "fjc_common.h"

FJC_BEGINDECLS
/*
 * Constants
 */
enum
{ 
  FJC_IVECTOR_SIGNATURE = (fjc_magic_t) 0xFADEBAD4u, /* Signature */
  FJC_IVECTOR_CHUNKSIZE = (size_t) 10 /* Default chunk size = 10 elements */
};

/*
 * Datatypes
 */
/* Infinite vector descriptor */
struct fjc_ivector_t
{
  void *data_;			/* Vector data */
  size_t size_;			/* Vector size */
  size_t datalen_;		/* Size of each vector element */
  size_t chunksize_;            /* Size of memory chunk to allocate */
  size_t chunksused_;           /* Chunks used */
  size_t elemused_;             /* Elements used in chunk */
  fjc_compare_t *comp_;		/* Comparison function */
  fjc_magic_t signature_;        /* Signature of the descriptor */
};

FJC_ENDDECLS

#endif /* FJC_IVECTOR__H */
