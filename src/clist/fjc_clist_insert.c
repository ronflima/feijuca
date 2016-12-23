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

   Description: Inserts a new element in the list
*/
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "fjc_clist.h"
#include "fjc_list_.h"

fjc_error_t
fjc_clist_insert (fjc_clist_t clist, const void *data, fjc_position_t whence)
{
  fjc_list_element_t element;

  assert (clist != NULL);
  assert (data != NULL);
  if ((element = (fjc_list_element_t) malloc (sizeof (struct fjc_list_element_t))) == NULL)
    {
      return E_FJC_NOMEM;
    }
  memset (element, 0x0, sizeof (struct fjc_list_element_t));
  element->data_ = data;
  if (clist->size_ == 0x0)
    {
      clist->head_ = clist->tail_ = element;
    }
  else
    {
      switch (whence)
        {
        case POS_FJC_HEAD:
          element->next_ = clist->head_;
          clist->head_ = element;
          break;
        case POS_FJC_TAIL:
          clist->tail_->next_ = element;
          clist->tail_ = element;
          break;
        case POS_FJC_NEXT:
          if (clist->curr_ == NULL)
            {
              free (element);
              return E_FJC_BADC;
            }
          element->next_ = clist->curr_->next_;
          clist->curr_->next_ = element;
          if (clist->curr_ == clist->tail_)
            {
              clist->head_ = element;
            }
          break;
        default:
          free (element);
          return E_FJC_INVAL;
        }
    }
  clist->tail_->next_ = clist->head_;
  ++ (clist->size_);
  return E_FJC_OK;
}
