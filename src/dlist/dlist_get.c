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
*/
#include <stdio.h>
#include <assert.h>
#include "dlist.h"
#include "dlist_.h"

/* Version info */
static char const rcsid[] = "@(#) $Id$";

const void *
dlist_get (dlist_t list, position_t whence)
{
  void *data = NULL;

  assert (list != NULL);

  /* Checks if the current pointer points to somewhere */
  if (list->curr_ == NULL)
    {
      return data;
    }
  /* Gets the data from the current pointer */
  data = list->curr_->data_;

  /* Decides how to navigate the list */
  switch (whence)
    {
    case POS_NEXT:		/* Moves to the next element */
    case POS_PREV:		/* Moves to the previous element */
      dlist_move (list, whence);
    default:			/* Invalid parameter provided */
      break;
    }
  return data;
}
