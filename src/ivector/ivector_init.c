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
 $Id: ivector_init.c,v 1.4 2005-10-14 09:58:23 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gacommon.h"
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_init.c,v 1.4 2005-10-14 09:58:23 ron_lima Exp $";

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
