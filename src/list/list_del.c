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
 along with G.A. Lib; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  System: G.A. Lib

  Description: Deletes the next element pointed by element

 CVS Information $Author: harq_al_ada $ $Id: list_del.c,v 1.7 2004/07/19 00:53:45
 ron_lima Exp $
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gacommon.h"
#include "gainternal_.h"
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_del.c,v 1.20 2006-01-26 10:18:13 harq_al_ada Exp $";

int
list_del (list_t * list, void **data)
{
  list_element_t *currelem;	/* Current element being processed */
  void *extracted_data;		/* Data extracted from the list */

  assert (list != NULL);
  CHECK_SIGNATURE (list, GA_LIST_SIGNATURE);      
  currelem = (list_element_t *) NULL;
  
  /* Initializations */
  if (data)
    {
      *data = (void *) NULL;
    }
  /* Sanity check: Will not delete an element if the list is empty */
  if (list->size_ == 0x0u)
    {
      return EOF;
    }
  /* Sanity check: check if the data storage and the deallocator were
     provided. If not, there is a problem in the list initialization */
  if (!data && !list->deallocator_)
    {
      return EGAINVAL;
    }
  /* Check if the current element points to the head of the list or if the
     curr_ points to nowhere */
  if (list->curr_ == list->head_ || !list->curr_)
    {
      /* Deletes from the head of the list */
      currelem = list->head_;
      extracted_data = list->head_->data_;
      list->head_ = currelem->next_;
      list->curr_ = list->head_;
    }
  else
    {
      /* Delete the next item, if the curr_ points to somewhere */
      if (list->curr_->next_)
        {
          currelem = list->curr_->next_;
          extracted_data = currelem->data_;
          list->curr_->next_ = currelem->next_;
        }
      else
        {
          /* Sorry. I can delete only the next element. */
          return EOF;
        }
    }
  /* Adjusts the tail of the list */
  if (currelem == list->tail_ && list->curr_)
    {
      /* We are about to delete the tail. At this point, if the curr_ points to
         somewhere, it will be the new tail. If curr_ points to nowhere, we are
         deleting the head and the tail will be adjusted later only if the list
         get empty. */
      list->tail_ = list->curr_;
    }
  /* Free resources and updates the list descriptor */
  free (currelem);
  --(list->size_);

  /* Adjusts the tail if the list got empty */
  if (!list->size_)
    {
      list->tail_ = (list_element_t *) 0x0;
    }
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
