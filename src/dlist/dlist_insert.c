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

 Description: Inserts a new element in the list

 CVS Information
 $Author: ron_lima $
 $Id: dlist_insert.c,v 1.23 2005-12-13 10:18:52 ron_lima Exp $
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "dlist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist_insert.c,v 1.23 2005-12-13 10:18:52 ron_lima Exp $";

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

  assert (list != NULL);
  assert (data != NULL);
  CHECK_SIGNATURE (list, GA_DLIST_SIGNATURE);
  
  element = (dlist_element_t *) malloc (sizeof (dlist_element_t));
  assert (element != NULL);
  if (element == NULL)
    {
      return EGANOMEM;
    }
  element->data_ =  (void *)data;
  element->next_ =  NULL;
  element->prev_ =  NULL;

  if (list->size_ == 0x0)
    {
      list->head_ = element;
      list->tail_ = element;
    }
  else
    {
      int rc;                   /* General error handling variable */

      /* Effectively inserts the new element into the list */
      if ((rc = relink_list (list, element, whence)) != 0x0)
        {
          free (element);
          return rc;
        }
    }
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
  if (whence == POS_CURR || whence == POS_NONE || whence == POS_PREV) 
    {
      /* It was conventioned that all of these positions have the same
       * behavior */
      if (list->curr_ != NULL)  
        {       
          element->next_ = list->curr_;
          element->prev_ = list->curr_->prev_;
          if (list->curr_ != list->head_)
            {
              list->curr_->prev_->next_ = element;
            }
          else
            {
              list->head_ = element;
            }
          list->curr_->prev_ = element;     
        }
      else
        {
          return EGABADC;
        }
    }
  else if (whence == POS_NEXT) 
    {
      if (list->curr_ != NULL)
        {
          element->next_ = list->curr_->next_;
          element->prev_ = list->curr_;
          if (list->curr_ != list->tail_)
            {
              element->next_->prev_ = element;
            }
          else
            {
              list->tail_ = element;
            }
          list->curr_->next_ = element;
        }
      else
        {
          return EGABADC;
        }
    }
  else if (whence == POS_HEAD)
    {
      element->next_     = list->head_;
      element->prev_     = list->head_->prev_;
      list->head_->prev_ = element;
      list->head_        = element;
    }
  else if (whence == POS_TAIL)
    {
      element->prev_     = list->tail_;
      element->next_     = list->tail_->next_;
      list->tail_->next_ = element;
      list->tail_        = element;
    }
  else 
    {
      return EGAINVAL;
    }
  return 0x0;
}
