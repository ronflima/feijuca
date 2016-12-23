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

   Description: Deletes an element given a position
*/

#include <assert.h>
#include "fjc_dclist.h"
#include "fjc_dclist_.h"
#include "fjc_dlist_.h"

fjc_error_t
fjc_dclist_del (fjc_dclist_t dclist, void **data, fjc_position_t whence)
{
  fjc_error_t rc = E_FJC_OK;
  assert (dclist != NULL);
  if (dclist == NULL)
    {
      return E_FJC_INVAL;
    }
  if (dclist->signature_ != FJC_DCLIST_SIGNATURE)
    {
      return E_FJC_INVAL;
    }
  if (dclist->list_->size_ > 0x0)
    {
      dclist->list_->head_->prev_ = NULL;
      dclist->list_->tail_->next_ = NULL;
    }
  if ((rc = fjc_dlist_del (dclist->list_, data, whence)) == E_FJC_OK)
    {
      fjc_dclist_make_circular_ (dclist);
    }
  return rc;
}
