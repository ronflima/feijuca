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
 $Author: harq_al_ada $
 $Id: ivector_bsearch.c,v 1.17 2006-01-29 20:03:12 harq_al_ada Exp $
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ivector.h"
#include "ivector_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_bsearch.c,v 1.17 2006-01-29 20:03:12 harq_al_ada Exp $";

int
ivector_bsearch (ivector_t vector, void **found, const void *data)
{
  /* Assertives for debugging purposes */
  assert (vector != NULL);
  assert (data != NULL);
  if (vector == NULL || data == NULL)
    {
      return EGAINVAL;
    }
  CHECK_SIGNATURE (vector, GA_IVECTOR_SIGNATURE);
  
  *found = (void *) NULL;

  if (vector->comp_ == NULL)
    {
      return EGAINVAL;
    }
  if (vector->size_ != 0x0)
    {
      *found = bsearch (data, vector->data_, vector->size_,
        		vector->datalen_, vector->comp_);
      if (*found == NULL) 
	{
	  return EOF;
	}
    }

  return 0x0;
}
