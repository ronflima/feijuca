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

 Description: Reverses the list using a moving window algorithm

 CVS Information
 $Author: harq_al_ada $
 $Id: list_reverse.c,v 1.7 2006-02-12 23:38:44 harq_al_ada Exp $
*/
#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid[] =
  "@(#) $Id: list_reverse.c,v 1.7 2006-02-12 23:38:44 harq_al_ada Exp $";

int
list_reverse (list_t list)
{
  int rc = 0x0;

  assert (list != NULL);
  if (list == NULL)
    {
      rc = EGAINVAL;
    }
  else
    {
      CHECK_SIGNATURE (list, GA_LIST_SIGNATURE);
  
      /* Check if the list is empty or have enough information to reverse */
      if (list->size_ < 0x2u)               
        {
          rc = EOF;
        }
      else
        {           
          list_element_t *first;	/* First item of the window */
          list_element_t *middle;	/* Middle item of the window */

          first       = list->tail_;
          list->tail_ = list->head_;
          list->head_ = first;

          /* Initializes the window. At this point we had already
             reversed the head and tail positions. The tail has the
             old head and since no relinking was done, the links still
             the same. */
          first = list->tail_;
          middle = list->tail_->next_;
          do
            {
              list_element_t *last;	/* Last item of the window */

              /* Sets the last item of the window */
              last = middle->next_;
              /* Relinks the item, reversing its position */
              middle->next_ = first;
              /* Moves the window */
              first = middle;
              middle = last;
            }
          while (middle != NULL);

          /* Adjusts the tail of the list */
          list->tail_->next_ = NULL;
        }
    }

  return rc;
}
