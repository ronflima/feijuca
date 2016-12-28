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
fjc_error_t (fjc_ivector_init)     __P ((fjc_ivector_t *, fjc_compare_t *, size_t));
fjc_error_t (fjc_ivector_destroy)  __P ((fjc_ivector_t));
fjc_error_t (fjc_ivector_get)      __P ((fjc_ivector_t, size_t, void **));
fjc_error_t (fjc_ivector_put)      __P ((fjc_ivector_t, size_t, const void *));
fjc_error_t (fjc_ivector_add)      __P ((fjc_ivector_t, const void *));
fjc_error_t (fjc_ivector_qsort)    __P ((fjc_ivector_t));
fjc_error_t (fjc_ivector_bsearch)  __P ((fjc_ivector_t, void **, const void *));
fjc_error_t (fjc_ivector_del)      __P ((fjc_ivector_t, size_t));
fjc_error_t (fjc_ivector_get_size) __P ((fjc_ivector_t, size_t *));

FJC_ENDDECLS

#endif /* FJC_IVECTOR_H */
