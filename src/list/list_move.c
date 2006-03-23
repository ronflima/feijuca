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
 $Author: harq_al_ada $
 $Id: list_move.c,v 1.22 2006-03-23 10:33:56 harq_al_ada Exp $
*/
#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_move.c,v 1.22 2006-03-23 10:33:56 harq_al_ada Exp $"; 

int
list_move (list_t list, position_t whence)
{
  int rc = 0x0;
  assert (list != NULL);
  if (! list_is_valid_ (list))
    {
      rc = EGAINVAL;
    }
  else
    {
      if (whence == POS_HEAD)
        {
          list->curr_ = list->head_;
        }
      else if (whence == POS_TAIL)
        {
          list->curr_ = list->tail_;
        }
      else if (whence == POS_NEXT)
        {
          if (list->curr_ != NULL)
            {
              rc = list_element_get_next_ (list->curr_, &list->curr_);
            }
          else
            {
              rc = EOF;
            }
        }
      else
        {
          rc = EGAINVAL;
        }
    }
  return rc;
}
