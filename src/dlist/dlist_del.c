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

 Description: Deletes the next element pointed by element

 CVS Information
 $Author: ron_lima $
 $Id: dlist_del.c,v 1.10 2004-10-13 00:30:23 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"

/*
 * Local prototypes
 */
static void
relink_list (dlist_t *, dlist_element_t *);

static dlist_element_t *
delete_head (dlist_t *);

static dlist_element_t *
delete_tail (dlist_t *);

static dlist_element_t *
delete_current (dlist_t *);

static dlist_element_t *
delete_next (dlist_t *);

static dlist_element_t *
delete_prev (dlist_t *);

/*
 * Exported functions
 */
int
dlist_del (dlist_t * list, void ** data, position_t whence)
{
  dlist_element_t * currelem;       /* Current element being processed */
  void *            extracted_data; /* Data extracted from the list */

  /* Assertives for debugging purposes */
  assert (list != NULL);

  /* Initializations */
  currelem = (dlist_element_t *) NULL;
  if (data)
  {
    *data = (void *) NULL;
  }
  /* Sanity check: Will not delete an element if the list is empty */
  if (! list->size_)
  {
    return EOF;
  }
  /* Sanity check: check if the data storage and the deallocator were
     provided. If not, there is a problem in the list initialization */
  if (!data && !list->deallocator_)
  {
    return EGAINVAL;
  }
  /* Deletes the correct element based on the whence parameter, relinking the
     list elements */
  switch (whence)
  {
  case HEAD:			/* Deletes from the head of the list */
    currelem = delete_head (list);
    break;
  case TAIL:			/* Deletes from the tail of the list */
    currelem = delete_tail (list);
    break;
  case CURR:			/* Deletes the current element  */
    currelem = delete_current (list);
    break;
  case NEXT:			/* Deletes the next element */
    currelem = delete_next (list);
    break;
  case PREV:			/* Deletes the previous element */
    currelem = delete_prev (list);
    break;
  default:			/* Error: wrong parameter provided */
    return EGAINVAL;
  }
  /* The current element to be deleted was not determined. It means that the
     function have reached the end of the list or the operation was not
     possible */
  if (! currelem)
  {
    return EOF;
  }
  /* Free resources and updates the list descriptor */
  extracted_data = currelem->data_;
  free(currelem);
  list->size_--;
  /* If data storage is provided, puts the extracted data in there */
  if (data)
  {
    *data = extracted_data;
  }
  else
  {
    /* Data storage was not provided. Deletes the data */
    list->deallocator_ (extracted_data);
  }
  return 0x0;
}

/*
 * Internal functions definitions
 */
/* Relinks the list popping the element out from the list */
static void
relink_list (dlist_t * list, dlist_element_t * element)
{
  /* If the element is not valid, simply return. Nothing to do */
  if (! element)
  {
    return;
  }
  /* Rebuilds the list links based on the popped element */
  if (element->prev_)
  {
    element->prev_->next_ = element->next_;
  }
  else
  {
    /* Element is the head */
    list->head_ = element->next_;
  }
  if (element->next_)
  {
    element->next_->prev_ = element->prev_;
  }
  else
  {
    /* Element is the tail */
    list->tail_ = element->prev_;
  }
}

/* Deletes the head of the list */
static dlist_element_t *
delete_head (dlist_t * list)
{
  dlist_element_t * element;	/* Element to be popped out from the list */
  
  element = list->head_;
  relink_list (list, element);
  return element;
}

/* Deletes the tail of the list */
static dlist_element_t *
delete_tail (dlist_t * list)
{
  dlist_element_t * element;	/* Element to be popped out from the list */
  element = list->tail_;
  relink_list (list, element);
  return element;
}

/* Deletes the current element of the list by rebuilding the list
   links based on the current element */
static dlist_element_t *
delete_current (dlist_t * list)
{
  dlist_element_t * element;	/* Element deleted from the list */
  element = list->curr_;
  relink_list (list, element);
  list->curr_ = (dlist_element_t *) NULL;
  return element;
}

/* Deletes the next element of the list by rebuilding the list links
   based on current element */
static dlist_element_t *
delete_next (dlist_t * list)
{
  dlist_element_t * element; /* Element to be popped from the list */
  /* curr_ pointer will be dereferenced later. This check avoids
   * coredumps :) */
  if (! list->curr_)
  {
    return (dlist_element_t *) NULL;
  }
  /* Pops the element to be deleted */
  element = list->curr_->next_;
  /* Relinks the list, deleting the selected element */
  relink_list (list, element);
  return element;
}

/* Deletes the previous element based on the current pointer of the
   list descriptor */
static dlist_element_t *
delete_prev (dlist_t * list)
{
  dlist_element_t * element; /* Element to be popped from the list */
  /* curr_ pointer will be dereferenced later. This check avoids
   * coredumps :) */
  if (!list->curr_)
  {
    return (dlist_element_t *) NULL;
  }
  element = list->curr_->prev_;
  /* Relinks the list, deleting the selected element */
  relink_list (list, element);
  return element;
}
