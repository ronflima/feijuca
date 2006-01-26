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
 $Id: clist_destroy.c,v 1.5 2006-01-26 10:18:13 harq_al_ada Exp $
*/
#include <assert.h>
#include "list.h"
#include "clist.h"
#include "gainternal_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_destroy.c,v 1.5 2006-01-26 10:18:13 harq_al_ada Exp $";

int
clist_destroy (clist_t * clist)
{
  assert (clist != NULL);

  CHECK_SIGNATURE (clist, GA_CLIST_SIGNATURE);
  return list_destroy (&clist->list_);
}
