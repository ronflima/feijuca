/* -*-c-*-
   Copyright (c) 2016 Ronaldo Faria Lima
   
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
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
