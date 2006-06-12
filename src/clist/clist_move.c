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

 Description: Moves the curr_ pointer depending on the parameter of
 the list

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_move.c,v 1.11 2006-06-12 10:03:51 harq_al_ada Exp $
*/
#include <assert.h>
#include "list.h"
#include "clist.h"
#include "clist_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_move.c,v 1.11 2006-06-12 10:03:51 harq_al_ada Exp $";

int
clist_move (clist_t clist, position_t whence)
{
  GAERROR rc = EGAOK;           /* Error handling */

  assert (clist != NULL);
  if (! clist_is_valid_ (clist))
    {
      rc = EGAINVAL;
    }
  else
    {
      list_t list;                  /* Internal list */
      
      if ((rc = clist_get_list_ (clist, &list)) == EGAOK)
        {
          rc = list_move (list, whence);
        }
    }
  return rc;
}
