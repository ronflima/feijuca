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

   Description: Finishes the deque. This routine will delete the deque from the
   memory
*/

#include <assert.h>
#include <stdlib.h>
#include "fjc_dlist.h"
#include "fjc_deque.h"
#include "fjc_deque_.h"

fjc_error_t
fjc_deque_destroy (fjc_deque_t deque)
{
  assert (deque != NULL);
  if (deque == NULL)
    {
      return E_FJC_INVAL;
    }
  if (deque->signature_ != FJC_DEQUE_SIGNATURE)
    {
      return E_FJC_INVAL;
    }
  fjc_dlist_destroy (deque->list_);
  free (deque);
  return E_FJC_OK;
}
