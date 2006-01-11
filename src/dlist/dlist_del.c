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

 Description: Deletes the next element pointed by element

 CVS Information
 $Author: harq_al_ada $
 $Id: dlist_del.c,v 1.24 2006-01-11 10:20:25 harq_al_ada Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist_del.c,v 1.24 2006-01-11 10:20:25 harq_al_ada Exp $";

/*
 * Local prototypes
 */
static int relink_list __P((dlist_t *, dlist_element_t *));

/*
 * Exported functions
 */
int
dlist_del (dlist_t * list, void **data, position_t whence)
{
  dlist_element_t *element;	/* Current element being processed */
  int rc;
  
  assert (list != NULL);
  CHECK_SIGNATURE (list, GA_DLIST_SIGNATURE);

  if (list == NULL)
    {
      return EGAINVAL;
    }

  element = (dlist_element_t *) NULL;
  if (data)
    {
      *data = (void *) NULL;
    }
  if (list->size_ == 0x0u)
    {
      return EOF;
    }
  if ((data == NULL) && (list->deallocator_ == NULL))
    {
      return EGAINVAL;
    }
  if (whence == POS_HEAD)
    {
      element = list->head_;
    }
  else if (whence == POS_TAIL)
    {
      element = list->tail_;
    }
  else if ((whence == POS_CURR) || (whence == POS_NONE))
    {
      element = list->curr_;
      list->curr_ = NULL;
    }
  else if (whence == POS_NEXT)
    {
      if (list->curr_ != NULL)
        {
          element = list->curr_->next_;
        }
    }
  else if (whence == POS_PREV)
    {
      if (list->curr_ != NULL)
        { 
          element = list->curr_->prev_;
        }
    }
  else
    {
      return EGAINVAL;
    }
  if ((rc = relink_list (list, element)) != 0x0)
    {
      return rc;
    }
  /* If data storage is provided, puts the extracted data in there */
  if (data != NULL)
    {
      *data = element->data_;
    }
  else
    {
      /* Data storage was not provided. Deletes the data */
      list->deallocator_ (element->data_);
    }
  free (element);
  list->size_--;
  return 0x0;
}

/*
 * Internal functions definitions
 */
/* Relinks the list popping the element out from the list */
static int
relink_list (dlist_t * list, dlist_element_t * element)
{
  if (element == NULL)
    {
      return EOF;
    }
  if (element->prev_ != NULL)
    {
      element->prev_->next_ = element->next_;
    }
  if (element->next_ != NULL)
    {
      element->next_->prev_ = element->prev_;
    }
  /* Checks if element is the head of the tail. This is needed for
   * operations on curr_ where it points to the head or tail */
  if (element == list->head_)
    {
      list->head_ = element->next_;
      if (list->head_ != NULL)
        {
          list->head_->prev_ = NULL;
        }
    }
  if (element == list->tail_)
    {
      list->tail_ = element->prev_;
      if (list->tail_ != NULL)
        {
          list->tail_->next_ = NULL;
        }
    }
  return 0x0;
}
