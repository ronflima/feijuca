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

   Description: Allocates and initializes a deque
*/
#include <assert.h>
#include <stdlib.h>
#include "fjc_deque.h"
#include "fjc_deque_.h"

fjc_error_t
fjc_deque_init (fjc_deque_t * deque, fjc_deallocator_t * dealloc)
{
  fjc_error_t rc = E_FJC_OK;
  assert (deque != NULL);
  assert (dealloc != NULL);
  if (deque == NULL || dealloc == NULL)
    {
      rc = E_FJC_INVAL;
    }
  else
    {
      if ((*deque = (fjc_deque_t) malloc (sizeof (struct fjc_deque_t))) == NULL)
        {
          rc = E_FJC_NOMEM;
        }
      else
        {
          (*deque)->signature_ = FJC_DEQUE_SIGNATURE;
          if (((*deque)->list_ = fjc_dlist_init (dealloc)) == NULL)
            {
              (*deque)->signature_ = 0x0;
              free (*deque);
            }
        }
    }
  return rc;
}
