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

   Description: Deletes an element from the vector and resizes it to accomodate
   solely the elements that are mean to be accessible
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fjc_ivector.h"
#include "fjc_ivector_.h"

fjc_error_t
fjc_ivector_del (fjc_ivector_t vector, size_t idx)
{
  void *dest;			/* Destination address */
  void *orig;			/* Origin address */
  assert (vector != NULL);
  if (vector == NULL)
    {
      return E_FJC_INVAL;
    }
  if (vector->signature_ != FJC_IVECTOR_SIGNATURE)
    {
      return E_FJC_INVAL;
    }
  if (vector->size_ == 0x0)
    {
      return E_FJC_EOF;
    }
  if (idx > vector->size_)
    {
      return E_FJC_INVAL;
    }
  if ((idx + 1) < vector->size_)
    {
      size_t dest_index;
      size_t orig_index;
      size_t block_size;

      /* Calculates the origin and the destiny in order to overwrite the
         element of the vector that is placed in idx */
      dest_index = idx * vector->datalen_;
      orig_index = (idx + 1) * vector->datalen_;
      dest = (void *) (((char *) vector->data_) + dest_index);
      orig = (void *) (((char *) vector->data_) + orig_index);
      block_size = (vector->size_ - idx - 1) * vector->datalen_;
      memcpy (dest, orig, block_size);
    }
  vector->size_--;
  vector->elemused_--;
  if (vector->elemused_ == 0x0)
    {
      vector->elemused_ = vector->chunksize_;
      vector->chunksused_--;
    }
  return E_FJC_OK;
}
