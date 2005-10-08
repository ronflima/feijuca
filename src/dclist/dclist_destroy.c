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

 Description: Finishes a dclist. This routine will delete the whole dclist
 from memory

 CVS Information
 $Author: ron_lima $
 $Id: dclist_destroy.c,v 1.3 2005-10-08 20:25:00 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"
#include "dclist.h"
#include "gacommon.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_destroy.c,v 1.3 2005-10-08 20:25:00 ron_lima Exp $";

int
dclist_destroy (dclist_t * dclist)
{
  assert (dclist != NULL);
  CHECK_SIGNATURE (dclist, GA_DCLIST_SIGNATURE);
  
  /* Redefine last pointer to work with dlist_destroy algorithm */
  if (descriptor_size (&dclist->list_))
    {
      dclist->list_.tail_->next_ = NULL;
    }

  return dlist_destroy (&dclist->list_);
}
