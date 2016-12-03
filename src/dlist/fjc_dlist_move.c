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
*/
#include <stdio.h>
#include <assert.h>
#include "fjc_dlist.h"
#include "fjc_dlist_.h"

fjc_error_t
fjc_dlist_move (fjc_dlist_t list, fjc_position_t whence)
{
  assert (list != NULL);

  /* Decides how to navigate in the list */
  switch (whence)
    {
    case POS_FJC_HEAD:		/* Moves to the head of the list */
      list->curr_ = list->head_;
      break;
    case POS_FJC_TAIL:		/* Moves to the tail of the list */
      list->curr_ = list->tail_;
      break;
    case POS_FJC_NEXT:		/* Moves to the next element */
      if (list->curr_)
        {
          list->curr_ = list->curr_->next_;
        }
      else
        {
          return E_FJC_EOF;
        }
      break;
    case POS_FJC_PREV:		/* Moves to the previous element */
      if (list->curr_)
        {
          list->curr_ = list->curr_->prev_;
        }
      else
        {
          return E_FJC_EOF;
        }
      break;
    case POS_FJC_NONE:		/* Does nothing: ignored */
      break;
    default:			/* Invalid parameter provided */
      return E_FJC_INVAL;
    }
  return E_FJC_OK;
}
