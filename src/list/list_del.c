/* -*-c-*-

 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved

 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of Feijuca Library.

 Feijuca Library is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by the Free
 Software Foundation; either version 2 of the License, or (at your option) any
 later version.

 Feijuca Library is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with
 Feijuca Library; if not, write to the Free Software Foundation, Inc., 59 Temple
 Place, Suite 330, Boston, MA 02111-1307 USA

  System: Feijuca Library

  Description: Deletes the next element pointed by element
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id$";

/* Local prototypes */

/*  
 * Deletes an element from the head of the list. This function
 * guarantees that the list is correctly linked after the extraction
 * of the head element.
 * Return values:
 * - pointer to the head if the element could be deleted.
 * - NULL if the element could not be deleted
 */
static list_element_t 
extract_element_from_head_ __P((list_t));

/*
 * This function extracts the next element from the list. It
 * guarantees that the list will be correctly linked after the
 * operation completes. It is expected that the current element
 * is valid.
 * Return values:
 * - A pointer to the element extracted from the list
 * - NULL if the element could not be extracted
 */
static list_element_t 
extract_element_from_next_ __P((list_t));

/* Exported function definitions */

GAERROR
list_del (list_t list, void **data, position_t whence)
{
  list_element_t element = NULL; /* Element to be deleted */

  assert (list != NULL);
  if (list->size_ == 0x0)
    {
      return EGAEOF;
    }
  switch (whence) 
    {
    case POS_HEAD:
      element = extract_element_from_head_ (list);
      break;
    case POS_NEXT:
      if (list->size_ > 1)
	{
	  /* Deleting the next element makes sense only when the list has more
	     than a single element. */
	  element = extract_element_from_next_ (list);
	}
      break;
    default:
      return EGAINVAL;
    }
  if (element == NULL) 
    {
      return EGAEOF;
    }
  if (data != NULL)
    {
      *data = (void *)element->data_;
    }
  else 
    {
      list->deallocator_ ((void *)element->data_);
    }
  free (element);
  --(list->size_);
  return EGAOK;
}

/* Local function definitions */
static list_element_t 
extract_element_from_head_ (list_t list)
{
  list_element_t element;	/* Element to be deleted */

  assert (list != NULL);
  element = list->head_;
  if (list->head_ == list->tail_)
    {
      list->tail_ = NULL;
    }
  if (list->head_ == list->curr_) 
    {
      list->curr_ = NULL; 
    }
  if (list->head_ != NULL)
    {
      list->head_ = list->head_->next_;
    }
  return element;
}

static list_element_t 
extract_element_from_next_ (list_t list)
{
  list_element_t element = NULL;	/* Element to be deleted */

  assert (list != NULL);
  if (list->curr_ != NULL)
    {
      if ((element = list->curr_->next_) != NULL)
	{
	  if (list->curr_->next_ == list->tail_)
	    {
	      list->tail_ = list->curr_;
	    }
	  list->curr_->next_ = list->curr_->next_->next_;
	}
    }
  return element;
}
