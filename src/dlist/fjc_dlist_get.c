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

   Description: Gets the current element of the list and iterates to the next
   one
*/

#include <stdio.h>
#include <assert.h>
#include "fjc_dlist.h"
#include "fjc_dlist_.h"

const void *
fjc_dlist_get (fjc_dlist_t list, fjc_position_t whence)
{
  fjc_dlist_element_t element = NULL;
  assert (list != NULL);
  switch (whence)
    {
    case POS_FJC_HEAD:
      element = list->head_;
      break;
    case POS_FJC_TAIL:
      element = list->tail_;
      break;
    case POS_FJC_CURR:
      element = list->curr_;
      break;
    case POS_FJC_NEXT:		/* Moves to the next element */
      if (list->curr_ != NULL)
        {
          element = list->curr_->next_;
        }
      break;
    case POS_FJC_PREV:		/* Moves to the previous element */
      if (list->curr_ != NULL)
        {
          element = list->curr_->prev_;
        }
      break;
    default:			/* Invalid parameter provided */
      break;
    }
  if (element == NULL)
    {
      return NULL;
    }
  return element->data_;
}
