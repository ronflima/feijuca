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

 Description: Adds a new element at the end of the vector

 CVS Information
 $Author: ron_lima $
 $Id: ivector_add.c,v 1.14 2005-10-14 09:54:07 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "gacommon.h"
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_add.c,v 1.14 2005-10-14 09:54:07 ron_lima Exp $";

int
ivector_add (ivector_t * vector, const void *data)
{
  void *v;			/* New redimensioned vector */

  assert (vector != NULL);
  CHECK_SIGNATURE (vector, GA_IVECTOR_SIGNATURE);
  
  if ((vector->elemused_ == vector->chunksize_) || (vector->size_ == 0x0))
    {
      /* If this chunk is fully used, allocates a new one */
      v = realloc (vector->data_, vector->datalen_ 
                   * (vector->size_  + vector->chunksize_));
      assert (v != NULL);
      if (v == NULL)
        {
          return EGANOMEM;
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

  return 0x0;
}
