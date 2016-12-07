/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This library is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as
 published by the Free Software Foundation; either version 2.1 of the
 License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
 USA

 System: G.A. Lib

 Description: Adds a new element at the end of the vector

 CVS Information
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
