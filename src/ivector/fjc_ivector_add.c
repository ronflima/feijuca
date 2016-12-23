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

   Description: Adds a new element at the end of the vector
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fjc_ivector.h"
#include "fjc_ivector_.h"

fjc_error_t
fjc_ivector_add (fjc_ivector_t vector, const void *data)
{
  void *v;			/* New redimensioned vector */
  assert (vector != NULL);
  if (vector == NULL)
    {
      return E_FJC_INVAL;
    }
  if (vector->signature_ != FJC_IVECTOR_SIGNATURE)
    {
      return E_FJC_INVAL;
    }
  if ((vector->elemused_ == vector->chunksize_) || (vector->size_ == 0x0))
    {
      /* If this chunk is fully used, allocates a new one */
      v = realloc (vector->data_, vector->datalen_ * (vector->size_  + vector->chunksize_));
      assert (v != NULL);
      if (v == NULL)
        {
          return E_FJC_NOMEM;
        }
      vector->elemused_ = 0x1;
      vector->chunksused_++;
      vector->data_ = v;
    }
  else
    {
      v = vector->data_;
      vector->elemused_++;
    }
  vector->size_++;
  v = (void *) ((char *)(v + vector->size_ * vector->datalen_));
  memcpy (v, data, vector->datalen_);
  return E_FJC_OK;
}
