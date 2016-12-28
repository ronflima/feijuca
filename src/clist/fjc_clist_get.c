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

   Description: Gets a given element from the list. Which element to get is
   provided as a function parameter.
*/

#include <assert.h>
#include "fjc_clist.h"
#include "fjc_list_.h"

fjc_error_t
fjc_clist_get (fjc_clist_t clist, fjc_position_t whence, void **data)
{
  fjc_list_element_t element = NULL;

  assert (clist != NULL);
  switch (whence)
    {
    case POS_FJC_HEAD:
      if (clist->head_ != NULL)
        {
          element = clist->head_;
        }
      break;
    case POS_FJC_TAIL:
      if (clist->tail_ != NULL)
        {
          element = clist->tail_;
        }
      break;
    case POS_FJC_CURR:
      if (clist->curr_ != NULL)
        {
          element = clist->curr_;
        }
      break;
    case POS_FJC_NEXT:
      if (clist->curr_ != NULL)
        {
          element = clist->curr_->next_;
        }
    default:
      return E_FJC_INVAL;
    }
  if (element == NULL)
    {
      return E_FJC_EOF;
    }
  *data = (void *)element->data_;
  return E_FJC_OK;
}
