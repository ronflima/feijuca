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

 Description: Allocates and initializes the infinite vector

 CVS Information
 $Author: ron_lima $
 $Id: ivector_init.c,v 1.2 2005-06-15 11:03:17 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gacommon.h"
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_init.c,v 1.2 2005-06-15 11:03:17 ron_lima Exp $";

int
ivector_init (ivector_t * vector, compare_t * comp, deallocator_t * dealloc,
              size_t datalen)
{
  /* Assertives for debugging purposes */
  assert (vector != NULL);
  assert (comp != NULL);
  assert (datalen != 0);

  /* Sanity tests */
  if (!datalen)
    {
      return EGAINVAL;
    }

  /* Initializes each vector descriptor field */
  vector->size_ = 0x0;
  vector->datalen_ = datalen;
  vector->comp_ = comp;
  vector->dealloc_ = dealloc;
  vector->data_ = (void *) NULL;
  vector->signature_ = GA_IVECTOR_SIGNATURE;

  return 0x0;
}