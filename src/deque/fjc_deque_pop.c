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

   Description: Pops an element from the deque giving a valid position (HEAD or
   TAIL)
*/
#include <assert.h>
#include "fjc_dlist.h"
#include "fjc_deque.h"
#include "fjc_deque_.h"

fjc_error_t
fjc_deque_pop (fjc_deque_t deque, fjc_position_t whence, void **data)
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
  if ((whence != POS_FJC_HEAD) && (whence != POS_FJC_TAIL))
    {
      return E_FJC_INVAL;
    }
  return fjc_dlist_del (deque->list_, whence, data);
}
