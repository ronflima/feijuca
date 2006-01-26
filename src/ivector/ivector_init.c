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
 $Id: ivector_init.c,v 1.6 2006-01-26 10:18:13 harq_al_ada Exp $
*/
#include <stddef.h>
#include <assert.h>
#include "gacommon.h"
#include "gainternal_.h"
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_init.c,v 1.6 2006-01-26 10:18:13 harq_al_ada Exp $";

int
ivector_init (ivector_t * vector, compare_t * comp, size_t datalen)
{
  assert (vector != NULL);
  assert (comp != NULL);
  assert (datalen != 0);

  if (datalen == 0x0)
    {
      return EGAINVAL;
    }
  vector->size_       = 0x0;
  vector->datalen_    = datalen;
  vector->chunksize_  = IVECTOR_CHUNKSIZE;
  vector->elemused_   = 0x0;
  vector->chunksused_ = 0x0;
  vector->comp_       = comp;
  vector->data_       = (void *) NULL;
  vector->signature_  = GA_IVECTOR_SIGNATURE;

  return 0x0;
}
