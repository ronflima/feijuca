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

   Description: Makes the dclist circular again by linking the head to the tail
   and the tail to the head. This is an internal function that is used by the
   circular lists routine. Notice that several checkings that are usually done
   for exported routines are ommitted here in order to make the function as
   simple as possible.
*/

#include <assert.h>
#include "fjc_dclist.h"
#include "fjc_dclist_.h"
#include "fjc_dlist_.h"

fjc_error_t
fjc_dclist_make_circular_ (fjc_dclist_t dclist)
{
  assert (dclist != NULL);
  if (dclist == NULL)
    {
      return E_FJC_INVAL;
    }
  if ((dclist->head_ != NULL) && (dclist->head_->prev_ == NULL))
    {
      dclist->head_->prev_ = dclist->tail_;
    }
  if ((dclist->tail_ != NULL) && (dclist->tail_->next_ == NULL))
    {
      dclist->tail_->next_ = dclist->head_;
    }
  return E_FJC_OK;
}
