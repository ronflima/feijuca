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

 Description: Deallocates the list descriptor

 CVS Information
 $Author: ron_lima $
 $Id: ivector_destroy.c,v 1.2 2005-06-15 11:03:17 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_destroy.c,v 1.2 2005-06-15 11:03:17 ron_lima Exp $";

int
ivector_destroy (ivector_t * vector)
{
  /* Assertives for debugging purposes */
  assert (vector != NULL);

  if (vector->signature_ != GA_IVECTOR_SIGNATURE)
    {
      return EGAINVAL;
    }
  
  /* Checks if the deallocator is a valid one */
  if (vector->dealloc_)
    {
      void *item;		/* Item of the vector list */

      /* Deallocates each vector element */
      item = vector->data_;

      while ((char *) item - (char *) vector->data_ < vector->size_)
        {
          vector->dealloc_ (item);
          item = (void *) ((char *) item + vector->datalen_);
        }
    }
  
  /* Just frees whatever was allocated */
  free (vector->data_);
  vector->signature_ = (ga_magic_t) 0x0;
  
  return 0x0;
}
