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
 $Id: dlist_insert.c,v 1.13 2005-01-28 00:11:44 ron_lima Exp $
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "dlist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist_insert.c,v 1.13 2005-01-28 00:11:44 ron_lima Exp $";

/*
 * Local prototypes
 */
static int relink_list (dlist_t *, dlist_element_t *, position_t);

/*
 * Exported functions
 */
int
dlist_insert (dlist_t * list, const void *data, position_t whence)
{
  dlist_element_t *element;	/* New element to be inserted */

  /* Assertives for debugging purposes */
  assert (list != NULL);
  assert (data != NULL);

  /* Allocates memory for the new element */
  element = (dlist_element_t *) malloc (sizeof (dlist_element_t));
  assert (element != NULL);
  if (!element)
    {
      return EGANOMEM;
    }
  /* Initializes all inner data of the descriptor */
  element->data_ = (void *) data;
  element->next_ = (dlist_element_t *) NULL;
  element->prev_ = (dlist_element_t *) NULL;

  /* Check the size of the list */
  if (!list->size_)
    {
      /* This is the head of the list */
      list->head_ = element;
      list->tail_ = element;
    }
  else
    {
      int rc;			/* General error handling variable */

      /* Relinks the list based on whence parameter */
      rc = relink_list (list, element, whence);
      if (rc)
        {
          free (element);
          return rc;
        }
    }
  list->curr_ = element;
  list->size_++;
  return 0x0;
}

/*
 * Local functions
 */

/* Helper function: will relink the list based on the selected
   insertions position */
static int
relink_list (dlist_t * list, dlist_element_t * element, position_t whence)
{
  switch (whence)
    {
    case NEXT:			/* Inserts the new element after the current
        			   pointer */
      assert (list->curr_ != NULL);
      if (list->curr_)
        {
          element->next_ = list->curr_->next_;
          element->prev_ = list->curr_;
          list->curr_->next_ = element;
          list->tail_ = element;
        }
      else
        {
          return EGABADC;
        }
      break;
    case PREV:			/* Inserts the new element before the current
        			   pointer */
      assert (list->curr_ != NULL);
      if (list->curr_)
        {
          element->next_ = list->curr_;
          element->prev_ = list->curr_->prev_;
          list->curr_->prev_ = element;
        }
      else
        {
          return EGABADC;
        }
      break;
    case HEAD:			/* Inserts the new element in the head of the
        			   list */
      element->next_ = list->head_->next_;
      list->head_->prev_ = element;
      list->head_ = element;
      break;
    case TAIL:			/* Inserts the new element in the tail of the
        			   list */
      element->prev_ = list->tail_;
      list->tail_->next_ = element;
      list->tail_ = element;
      break;
    default:			/* Invalid parameter provided */
      return EGAINVAL;
    }
  return 0x0;
}
