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

 Description: Returns the inner list inside the clist descriptor

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_set_signature_.c,v 1.1 2006-08-16 10:17:38 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdio.h>
#include "list.h"
#include "clist.h"
#include "clist_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_set_signature_.c,v 1.1 2006-08-16 10:17:38 harq_al_ada Exp $";

GAERROR
clist_set_signature_ (clist_t clist)
{
  GAERROR rc = EGAOK;
  
  /* It is not possible to use the clist_is_valid_ here because this
   * function will make the structure valid. The descriptor, at this
   * point, is expected to be invalid. */
  if (clist == NULL) 
    {
      rc = EGAINVAL;
    }
  else
    {
      clist->signature_ = GA_CLIST_SIGNATURE;
    }
  return rc;
}