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
 $Id: dlist_move.c,v 1.2 2004-03-07 20:53:29 ron_lima Exp $
*/
#include <errno.h>
#include <stdio.h>
#include "dlist.h"

int
dlist_move (DLIST * list, LIST_POSITION whence)
{
  switch (whence)
    {
    case HEAD:                  /* Moves to the head of the list */
      list->curr_ = list->head_;
      break;
    case TAIL:                  /* Moves to the tail of the list */
      list->curr_ = list->tail_;
      break;
    case NEXT:                  /* Moves to the next element */
      if (list->curr_)
        {
          list->curr_ = list->curr_->next_;
        }
      break;
    case PREV:                  /* Moves to the previous element */
      if (list->curr_)
        {
          list->curr_ = list->curr_->prev_;
        }
      break;
    default:                    /* Invalid parameter provided */
      errno = EINVAL;
      return -1;
    }
  /* Last resort check: check if the curr_ pointer is valid */
  if (! list->curr_)
    {
      return EOF;
    }
  return 0;
}