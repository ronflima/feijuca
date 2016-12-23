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

   Description: Reverses the list using a moving window algorithm
*/

#include <stdio.h>
#include <assert.h>
#include "fjc_list.h"
#include "fjc_list_.h"

fjc_error_t
fjc_list_reverse (fjc_list_t list)
{
  fjc_list_element_t first;  /* First item of the window */
  fjc_list_element_t middle; /* Middle item of the window */

  assert (list != NULL);
  if (list->size_ < 0x2u)
    {
      return E_FJC_EOF;
    }
  first = list->head_;
  middle = list->head_->next_;
  list->tail_ = list->head_;
  list->head_ = list->tail_;
  do
    {
      fjc_list_element_t last;	/* Last item of the window */
                              
      /* Sets the last item of the window */
      if ((last = middle->next_) == NULL)
        {
          break;
        }
      /* Relinks the item, reversing its position */
      if ((middle->next_ = first) == NULL)
        {
          break;
        }
      /* Moves the window */
      first = middle;
      middle = last;
    }
  while (middle != NULL);

  list->tail_->next_ = NULL;
  return E_FJC_OK;
}
