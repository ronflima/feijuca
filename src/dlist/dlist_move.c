/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of G.A. Lib.

 G.A. Lib is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 G.A. Lib is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with G.A. Lib; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: G.A. Lib

 Description: Moves the curr_ pointer depending on the parameter of
 the list

 CVS Information
 $Author: ron_lima $
 $Id: dlist_move.c,v 1.14 2005-01-30 11:28:17 ron_lima Exp $
*/
#include <stdio.h>
#include <assert.h>
#include "dlist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist_move.c,v 1.14 2005-01-30 11:28:17 ron_lima Exp $";

int
dlist_move (dlist_t * list, position_t whence)
{
  /* Assertives for debugging purposes */
  assert (list != NULL);
  /* Decides how to navigate in the list */
  switch (whence)
    {
    case POS_HEAD:			/* Moves to the head of the list */
      list->curr_ = list->head_;
      break;
    case POS_TAIL:			/* Moves to the tail of the list */
      list->curr_ = list->tail_;
      break;
    case POS_NEXT:			/* Moves to the next element */
      if (list->curr_)
        {
          list->curr_ = list->curr_->next_;
        }
      else
        {
          return EOF;
        }
      break;
    case POS_PREV:			/* Moves to the previous element */
      if (list->curr_)
        {
          list->curr_ = list->curr_->prev_;
        }
      else
        {
          return EOF;
        }
      break;
    case POS_NONE:              /* Does nothing: ignored */
      break;
    default:			/* Invalid parameter provided */
      return EGAINVAL;
    }
  return 0x0;
}
