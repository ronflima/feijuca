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

 Description: Puts a new data element in an existing slot in the vector

 CVS Information
 $Author: daniel_csoares $
 $Id: ivector_put.c,v 1.5 2004-10-07 19:26:38 daniel_csoares Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "gacommon.h"
#include "ivector.h"

int
ivector_put(ivector_t * vector, size_t idx, const void *data)
{
  void *i;			/* Indexer for the vector */
  /* Assertives for debugging purposes */
  assert(vector != NULL);
  assert(data != NULL);
  /* Sanity tests */
  if (idx >= vector->size_)
  {
    return EGAINVAL;
  }
  if (!data)
  {
    return EGAINVAL;
  }
  /* Calculates the place where we want to overwrite data */
  i = (void *)((char *)vector->data_ + idx * vector->datalen_);
  /* Overwrite data */
  memcpy(i, data, vector->datalen_);
  return 0x0;
}
