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

#ifndef FJC_LIST_H
#define FJC_LIST_H

#include <stddef.h>
#include "fjc_common.h"

FJC_BEGINDECLS

/*
 * Datatypes
 */
typedef struct fjc_list_t * fjc_list_t;

/*
 * Prototypes
 */
fjc_error_t    (fjc_list_init)     __P ((fjc_list_t *, fjc_deallocator_t *));
fjc_error_t    (fjc_list_destroy)  __P ((fjc_list_t));
fjc_error_t    (fjc_list_get)      __P ((fjc_list_t, fjc_position_t, void **));
fjc_error_t    (fjc_list_insert)   __P ((fjc_list_t, fjc_position_t, const void *));
fjc_error_t    (fjc_list_move)     __P ((fjc_list_t, fjc_position_t));
fjc_error_t    (fjc_list_del)      __P ((fjc_list_t, fjc_position_t, void **));
fjc_error_t    (fjc_list_reverse)  __P ((fjc_list_t));
fjc_error_t    (fjc_list_get_size) __P ((fjc_list_t, size_t *));

FJC_ENDDECLS
#endif /* FJC_LIST_H */
