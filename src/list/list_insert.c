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

 Description: Inserts a new element in the list

 CVS Information
 $Author: harq_al_ada $
 $Id: list_insert.c,v 1.18 2006-01-11 10:21:39 harq_al_ada Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_insert.c,v 1.18 2006-01-11 10:21:39 harq_al_ada Exp $"; 

int
list_insert (list_t * list, const void *data, position_t whence)
{
  list_element_t *element;

  assert (list != NULL);
  assert (data != NULL);
  CHECK_SIGNATURE (list, GA_LIST_SIGNATURE);
  
  /* Simple sanity check */
  if (list == NULL)
    {
      return EGAINVAL;
    }
  /* Check if the whence argument is acceptable */
  if (whence != POS_HEAD && whence != POS_CURR && whence != POS_TAIL)
    {
      /* Invalid argument provided */
      return EGAINVAL;
    }

  /* Allocates memory for the new element */
  element = (list_element_t *) malloc (sizeof (list_element_t));
  assert (element != NULL);
  if (!element)
    {
      return EGANOMEM;
    }
  element->data_ = (void *) data;
  element->next_ = (list_element_t *) NULL;
  /* Check the size of the list */
  if (list->size_ == 0x0u)
    {
      /* The list is empty. Sets the head and tail to point to the
         element */
      list->head_ = element;
      list->tail_ = element;
    }
  else
    {
      switch (whence)
        {
        case POS_HEAD: /* Insert at the head */
          element->next_ = list->head_;
          list->head_ = element;
          break;
        case POS_NEXT: /* Insert at the current position */
          if (list->curr_ != NULL)
            {
              /* Adds the new item after the current element */
              element->next_ = list->curr_->next_;
              list->curr_->next_ = element;
            }
          else
            {
              /* There is no valid current elemen. We cannot just
                 insert anything into the list */
              free (element);
              return EGABADC;
            }
          break;
        case POS_TAIL:          /* Insert at the end */
          list->tail_->next_ = element;
          list->tail_ = element;
          break;
        }
    }
  /* Updates the list size */
  ++(list->size_);

  return 0x0;
}
