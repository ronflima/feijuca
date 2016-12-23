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

   Description: Allocates and initializes the list
*/

#include <assert.h>
#include <stdlib.h>
#include "fjc_dlist.h"
#include "fjc_dlist_.h"

fjc_dlist_t
fjc_dlist_init (fjc_deallocator_t * dealloc)
{
  fjc_dlist_t list = NULL;
  assert (dealloc != NULL);
  if ((list = (fjc_dlist_t) malloc (sizeof (struct fjc_dlist_t))) == NULL)
    {
      list = NULL;
    }
  else
    {
      /* Initializes each data member of the list descriptor */
      list->size_ = 0x0;
      list->head_ = (fjc_dlist_element_t) NULL;
      list->tail_ = (fjc_dlist_element_t) NULL;
      list->curr_ = (fjc_dlist_element_t) NULL;
      list->deallocator_ = dealloc;
    }
  return list;
}
