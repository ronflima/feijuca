/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This is contributed code by Daniel Costa Soares
 <daniel_csoares@yahoo.com.br>

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

 Description: Finishes a dclist. This routine will delete the whole dclist
 from memory

 CVS Information
 $Author: harq_al_ada $
 $Id: dclist_destroy.c,v 1.5 2006-01-11 10:16:50 harq_al_ada Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"
#include "dclist.h"
#include "gacommon.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_destroy.c,v 1.5 2006-01-11 10:16:50 harq_al_ada Exp $";

int
dclist_destroy (dclist_t * dclist)
{
  assert (dclist != NULL);
  if (dclist == NULL)
    {
      return EGAINVAL;
    }
  CHECK_SIGNATURE (dclist, GA_DCLIST_SIGNATURE);
  
  /* Redefine last pointer to work with dlist_destroy algorithm */
  if (dclist->list_.tail_ != NULL)
    {
      dclist->list_.tail_->next_ = NULL;
    }

  return dlist_destroy (&dclist->list_);
}
