/* -*-c-*-
 Feijuca Library - A generic algorithms and data structures library
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

 System: Feijuca Lib

 Description: Gets a given element from the list. Which element to get is
 provided as a function parameter.
*/
#include <assert.h>
#include "clist.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id$";

GAERROR
clist_get (clist_t clist, void **data, position_t whence)
{
  list_element_t element = NULL;

  assert (clist != NULL);
  switch (whence)
    {
    case POS_HEAD:
      if (clist->head_ != NULL)
	{
	  element = clist->head_;
	}
      break;
    case POS_TAIL:
      if (clist->tail_ != NULL)
	{
	  element = clist->tail_;
	}
      break;
    case POS_CURR:
      if (clist->curr_ != NULL)
	{
	  element = clist->curr_;
	}
      break;
    case POS_NEXT:
      if (clist->curr_ != NULL)
	{
	  element = clist->curr_->next_;
	}
    default:
      return EGAINVAL;
    }
  if (element == NULL)
    {
      return EGAEOF;
    }
  *data = (void *)element->data_;
  return EGAOK;
}
