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
 $Author: ron_lima $
 $Id: list_insert.c,v 1.14 2005-01-30 11:28:17 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_insert.c,v 1.14 2005-01-30 11:28:17 ron_lima Exp $"; 

int
list_insert (list_t * list, const void *data, position_t whence)
{
  list_element_t *element;

  /* Several assertives for debugging purposes */
  assert (list != NULL);
  assert (data != NULL);

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
  if (!list->size_)
    {
      /* This is the head of the list */
      list->head_ = element;
      list->tail_ = element;
    }
  else
    {
      /* Check if the current element is valid */
      if (list->curr_)
        {
          /* Adds the new item after the current element */
          element->next_ = list->curr_->next_;
          list->curr_->next_ = element;
        }
      else
        {
          /* Insert at the end - the current element is not valid. */
          list->tail_->next_ = element;
          list->tail_ = element;
        }
    }
  if (list->curr_ && whence == POS_NEXT)
    {
      /* Updates the current element only if the current element is
         valid and the selected position is next */
      list->curr_ = element;
    }
  /* Updates the list size */
  ++(list->size_);

  return 0x0;
}
