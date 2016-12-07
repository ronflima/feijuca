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

 Description: Gets an item from the list

 CVS Information
 $Author: harq_al_ada $
 $Id: fjc_ivector_get.c,v 1.16 2006-01-29 20:03:12 harq_al_ada Exp $
*/
#include <stddef.h>
#include <assert.h>
#include "fjc_ivector.h"
#include "fjc_ivector_.h"

fjc_error_t
fjc_ivector_get (fjc_ivector_t vector, void **data, size_t idx)
{
  assert (vector != NULL);
  if (vector == NULL || data == NULL)
    {
      return E_FJC_INVAL;
    }
  if (vector->signature_ != FJC_IVECTOR_SIGNATURE)
    {
      return E_FJC_INVAL;
    }
  if (idx >= vector->size_)
    {
      *data = NULL;
      return E_FJC_INVAL;
    }
  *data = (void *) ((char *) vector->data_ + idx * vector->datalen_);
  return E_FJC_OK;
}
