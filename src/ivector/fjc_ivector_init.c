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

 Description: Allocates and initializes the infinite vector

 CVS Information
 $Author: harq_al_ada $
 $Id: fjc_ivector_init.c,v 1.7 2006-01-29 20:03:12 harq_al_ada Exp $
*/
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "fjc_ivector.h"
#include "fjc_ivector_.h"

fjc_error_t
fjc_ivector_init (fjc_ivector_t * vector, fjc_compare_t * comp, size_t datalen)
{
  fjc_error_t rc = E_FJC_OK;

  assert (vector != NULL);
  assert (datalen > 0);
  if (datalen == 0x0 || vector == NULL)
    {
      rc = E_FJC_INVAL;
    }
  else if ((*vector = (fjc_ivector_t) malloc (sizeof (struct fjc_ivector_t))) != NULL)
    {
      (*vector)->size_       = 0x0;
      (*vector)->datalen_    = datalen;
      (*vector)->chunksize_  = FJC_IVECTOR_CHUNKSIZE;
      (*vector)->elemused_   = 0x0;
      (*vector)->chunksused_ = 0x0;
      (*vector)->comp_       = comp;
      (*vector)->data_       = (void *) NULL;
      (*vector)->signature_  = FJC_IVECTOR_SIGNATURE;
    }
  else
    {
      rc = E_FJC_NOMEM;
    }
  return rc;
}
