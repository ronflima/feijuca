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
#include <stdio.h>
#include <assert.h>
#include "fjc_ivector.h"
#include "fjc_ivector_.h"

fjc_error_t
fjc_ivector_bsearch (fjc_ivector_t vector, void **found, const void *data)
{
  assert (vector != NULL);
  assert (data != NULL);
  if (vector == NULL || data == NULL)
    {
      return E_FJC_INVAL;
    }
  if (vector->signature_ != FJC_IVECTOR_SIGNATURE)
    {
      return E_FJC_INVAL;
    }
  *found = (void *) NULL;
  if (vector->comp_ == NULL)
    {
      return E_FJC_INVAL;
    }
  if (vector->size_ != 0x0)
    {
      *found = bsearch (data, vector->data_, vector->size_, vector->datalen_, vector->comp_);
      if (*found == NULL) 
        {
          return EOF;
        }
    }
  return E_FJC_OK;
}
