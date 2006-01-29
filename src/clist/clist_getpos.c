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

 Description: Gets the current element of the list and iterates to the
 next one

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_getpos.c,v 1.1 2006-01-29 12:37:02 harq_al_ada Exp $
*/
#include <assert.h>
#include "list.h"
#include "clist.h"
#include "clist_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_getpos.c,v 1.1 2006-01-29 12:37:02 harq_al_ada Exp $";

int 
clist_getpos (clist_t clist, position_t * whence)
{
  int rc = 0x0;
  assert (clist != NULL);
  if (clist == NULL)
    {
      rc =  EGAINVAL;
    }
  else
    {
      CHECK_SIGNATURE (clist, GA_CLIST_SIGNATURE);
      rc = list_getpos (clist->list_, whence);
    }
  return rc;
}
