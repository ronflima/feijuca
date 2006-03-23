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
 $Id: list_reverse.c,v 1.10 2006-03-23 10:33:56 harq_al_ada Exp $
*/
#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid[] =
  "@(#) $Id: list_reverse.c,v 1.10 2006-03-23 10:33:56 harq_al_ada Exp $";

int
list_reverse (list_t list)
{
  int rc = 0x0;

  assert (list != NULL);
  if (! list_is_valid_ (list))
    {
      rc = EGAINVAL;
    }
  else
    {
      /* Check if the list is empty or have enough information to reverse */
      if (list->size_ < 0x2u)               
        {
          rc = EOF;
        }
      else
        {           
          list_element_t first;	/* First item of the window */
          list_element_t middle;	/* Middle item of the window */

          first       = list->tail_;
          list->tail_ = list->head_;
          list->head_ = first;

          /* Initializes the window. At this point we had already
             reversed the head and tail positions. The tail has the
             old head and since no relinking was done, the links still
             the same. */
          first = list->tail_;
          if ((rc = list_element_get_next_ (list->tail_, &middle)) == 0x0)
            {
              do
                {
                  list_element_t last;	/* Last item of the window */

                  /* Sets the last item of the window */
                  if ((rc = list_element_get_next_ (middle, &last)) != 0x0)
                    {
                      break;
                    }
                  /* Relinks the item, reversing its position */
                  if ((rc = list_element_set_next_ (middle, first)) != 0x0)
                    {
                      break;
                    }
                  /* Moves the window */
                  first = middle;
                  middle = last;
                }
              while (middle != NULL);

              /* Adjusts the tail of the list */
              rc = list_element_set_next_ (list->tail_, NULL);
            }
        }
    }

  return rc;
}
