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

#ifndef FJC_LIST__H
#define FJC_LIST__H

#include <stddef.h>
#include "fjc_common.h"
#include "fjc_list.h"

FJC_BEGINDECLS

/*
 * Datatypes
 */
/* Abstraction for a single list element */
struct fjc_list_element_t
{
  struct fjc_list_element_t *next_; /* Pointer to the next element of the list */
  const void *data_;                /* Encapsulated data inside the list element */
};
typedef struct fjc_list_element_t * fjc_list_element_t;

/* Abstraction for the list descriptor */
struct fjc_list_t
{
  size_t size_;                     /* List size */
  fjc_list_element_t curr_;         /* Current navigation point */
  fjc_list_element_t head_;         /* List head */
  fjc_list_element_t tail_;         /* List tail */
  fjc_deallocator_t  *deallocator_; /* Deallocator function */
};

FJC_ENDDECLS
#endif /* FJC_LIST_H */
