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

   Description: Moves the curr_ pointer depending on the parameter of the list
*/

#include <stdio.h>
#include <assert.h>
#include "fjc_list.h"
#include "fjc_list_.h"

fjc_error_t
fjc_list_move (fjc_list_t list, fjc_position_t whence)
{
  assert (list != NULL);
  switch (whence)
    {
    case POS_FJC_HEAD:
      list->curr_ = list->head_;
      break;
    case POS_FJC_TAIL:
      list->curr_ = list->tail_;
      break;
    case POS_FJC_NEXT:
      if (list->curr_ == NULL || list->curr_->next_ == NULL)
        {
          return E_FJC_EOF;
        }
      list->curr_ = list->curr_->next_;
      break;
    default:
      return E_FJC_INVAL;
      break;
    }
  return E_FJC_OK;
}
