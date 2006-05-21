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

 Description: Finishes a list. This routine will delete the whole list
 from memory

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_destroy.c,v 1.7 2006-05-21 23:15:55 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdlib.h>
#include "list.h"
#include "clist.h"
#include "clist_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_destroy.c,v 1.7 2006-05-21 23:15:55 harq_al_ada Exp $";

GAERROR
clist_destroy (clist_t clist)
{
  GAERROR rc = EGAOK;

  assert (clist != NULL);
  if (!clist_is_valid(clist))
    {
      rc =  EGAINVAL;
    }
  else
    {
      rc = list_destroy (clist->list_);
      free (clist);
    }
  return rc;
}
