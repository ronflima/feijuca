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

 Description: Checks if the clist descriptor is valid or not

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_is_valid_.c,v 1.1 2006-05-17 11:05:18 harq_al_ada Exp $
*/
#include <assert.h>
#include "list.h"
#include "clist.h"
#include "clist_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_is_valid_.c,v 1.1 2006-05-17 11:05:18 harq_al_ada Exp $";

int
clist_is_valid_ (clist_t clist)
{
  int rc = 0x1;

  if (clist == NULL)
    {
      rc = 0x0;
    }
  else if (clist->signature_ != GA_CLIST_SIGNATURE)
    {
      rc = 0x0;
    }
  return rc;
}
