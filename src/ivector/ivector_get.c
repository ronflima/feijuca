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

 Description: Gets an item from the list

 CVS Information
 $Author: ron_lima $
 $Id: ivector_get.c,v 1.11 2005-07-04 00:31:34 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gacommon.h"
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_get.c,v 1.11 2005-07-04 00:31:34 ron_lima Exp $";

int
ivector_get (ivector_t * vector, void **data, size_t idx)
{
  assert (vector != NULL);
  CHECK_SIGNATURE (vector, GA_IVECTOR_SIGNATURE);  
  
  /* Sanity tests */
  if ((idx < 0x0u) || (idx >= vector->size_))
    {
      *data = NULL;
      return EGAINVAL;
    }
  /* Shifts the address idx times the data structure */
  *data = (void *) ((char *) vector->data_ + idx * vector->datalen_);

  return 0x0;
}
