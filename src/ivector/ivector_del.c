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

 Description: Deletes an element from the vector and resizes it to
 accomodate solely the elements that are mean to be accessible

 CVS Information
 $Author: harq_al_ada $
 $Id: ivector_del.c,v 1.16 2006-01-26 10:18:13 harq_al_ada Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "ivector.h"
#include "gacommon.h"
#include "gainternal_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_del.c,v 1.16 2006-01-26 10:18:13 harq_al_ada Exp $";

int
ivector_del (ivector_t * vector, size_t idx)
{
  void *dest;			/* Destination address */
  void *orig;			/* Origin address */

  assert (vector != NULL);
  CHECK_SIGNATURE (vector, GA_IVECTOR_SIGNATURE);

  if (vector->size_ == 0x0)
    {
      return EOF;
    }
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
  return 0x0;
}
