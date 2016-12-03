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
#include "fjc_dlist.h"
#include "fjc_dlist_.h"

const void *
fjc_dlist_get (fjc_dlist_t list, fjc_position_t whence)
{
  fjc_dlist_element_t element = NULL;
  assert (list != NULL);
  switch (whence)
    {
    case POS_FJC_HEAD:
      element = list->head_;
      break;
    case POS_FJC_TAIL:
      element = list->tail_;
      break;
    case POS_FJC_CURR:
      element = list->curr_;
      break;
    case POS_FJC_NEXT:		/* Moves to the next element */
      if (list->curr_ != NULL)
        {
          element = list->curr_->next_;
        }
      break;
    case POS_FJC_PREV:		/* Moves to the previous element */
      if (list->curr_ != NULL)
        {
          element = list->curr_->prev_;
        }
      break;
    default:			/* Invalid parameter provided */
      break;
    }
  if (element == NULL)
    {
      return NULL;
    }
  return element->data_;
}
