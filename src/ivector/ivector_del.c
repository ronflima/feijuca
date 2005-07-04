/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of G.A. Lib.

 G.A. Lib is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 G.A. Lib is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with G.A. Lib; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: G.A. Lib

 Description: Deletes an element from the vector and resizes it to
 accomodate solely the elements that are mean to be accessible

 CVS Information
 $Author: ron_lima $
 $Id: ivector_del.c,v 1.13 2005-07-04 00:31:34 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "gacommon.h"
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_del.c,v 1.13 2005-07-04 00:31:34 ron_lima Exp $";

int
ivector_del (ivector_t * vector, size_t idx)
{
  void *dest;			/* Destination address */
  void *orig;			/* Origin address */
  void *newplace;		/* New reallocated place for vector->data_ */
  size_t newsize;		/* New size of the vector in bytes */

  assert (vector != NULL);
  CHECK_SIGNATURE (vector, GA_IVECTOR_SIGNATURE);
  
  /* Sanity tests */
  if (idx > vector->size_)
    {
      return EGAINVAL;
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

      /* Overwrites the element pointed to by idx, moving all other elements
         one element to the right within the vector */
      block_size = (vector->size_ - idx - 1) * vector->datalen_;
      memcpy (dest, orig, block_size);
    }
  /* Calculates, in bytes, the new size of the vector */
  newsize = (vector->size_ - 1) * vector->datalen_;
  /* Deletes the last element of the vector and resizes it accordingly */
  newplace = realloc (vector->data_, newsize);
  /* Updates the vector descriptor accordingly */
  if (newplace != vector->data_ && newplace)
    {
      vector->data_ = newplace;
    }
  vector->size_--;

  return 0x0;
}
