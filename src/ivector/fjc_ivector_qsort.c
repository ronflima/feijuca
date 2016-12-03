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
*/

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "fjc_ivector.h"
#include "fjc_ivector_.h"

fjc_error_t
fjc_ivector_qsort (fjc_ivector_t vector)
{
  assert (vector != NULL);
  if (vector == NULL)
    {
      return E_FJC_INVAL;
    }
  CHECK_SIGNATURE (vector, FJC_IVECTOR_SIGNATURE);
  if (vector->comp_ == NULL)
    {
      return E_FJC_INVAL;
    }
  /* Do not try to sort a vector with only one element. It coredumps! */
  if (vector->size_ > 1)
    {
      qsort (vector->data_, vector->size_, vector->datalen_, vector->comp_);
    }
  return E_FJC_OK;
}
