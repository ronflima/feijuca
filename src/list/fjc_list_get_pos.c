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

   Description: Deletes the next element pointed by element
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fjc_list.h"
#include "fjc_list_.h"

fjc_error_t
fjc_list_get_pos (fjc_list_t list, fjc_position_t *pos)
{
  assert (list != NULL);
  assert (pos != NULL);
  if (list == NULL || pos == NULL)
    {
      return E_FJC_INVAL;
    }
  if ((list->curr_ == NULL) || (list->size_ == 0x0))
    {
      *pos = POS_FJC_NONE;
    }
  else if (list->curr_ == list->head_) 
    {
      *pos = POS_FJC_HEAD;
    }
  else if (list->curr_ == list->tail_)
    {
      *pos = POS_FJC_TAIL;
    }
  else
    {
      *pos = POS_FJC_MID;
    }
  return E_FJC_OK;
}
