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
 $Author: ron_lima $
 $Id: dlist_get.c,v 1.16 2005-12-13 10:18:52 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist_get.c,v 1.16 2005-12-13 10:18:52 ron_lima Exp $";

int
dlist_get (dlist_t * list, void **data, position_t whence)
{
  assert (list != NULL);
  assert (data != NULL);
  CHECK_SIGNATURE (list, GA_DLIST_SIGNATURE);
  
/* Checks if the current pointer points to somewhere */
  if (!list->curr_)
    {
      return EOF;
    }
  /* Gets the data from the current pointer */
  *data = list->curr_->data_;
  /* Decides how to navigate the list */
  switch (whence)
    {
    case POS_NONE:              /* Used only for parameter checking */
    case POS_CURR:              
      break;
    case POS_NEXT:			/* Moves to the next element */
    case POS_PREV:			/* Moves to the previous element */
      return dlist_move (list, whence);
      break;
    default:			/* Invalid parameter provided */
      return EGAINVAL;
    }
  return 0x0;
}
