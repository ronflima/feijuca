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
 $Id: list_del.c,v 1.2 2004-02-29 22:15:04 ron_lima Exp $
*/
#include <stdio.h>
#include <errno.h>
#include "list.h"

int
list_del (LIST * list, void **data)
{
  LIST_ELEMENT * currelem; /* Current element being processed */
  void * extracted_data;   /* Data extracted from the list */

  /* Initializations */
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
  if (! data && ! list->deallocator_)
    {
      errno = EINVAL;
      return -1;
    }
  /* Check if the current element points to the head of the list or if
     the curr_ points to nowhere */
  if (list->curr_ == list->head_ || ! list->curr_)
    {
      /* Deletes from the head of the list */
      currelem = list->head_;
      extracted_data = list->head_->data_ ;
      list->head_ = currelem->next_;
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
    }
  /* Free resources and updates the list descriptor */
  free (currelem);
  list->size_--;
  /* If data storage is provided, puts the extracted data in
     there */
  if (data)
    {
      * data = extracted_data;
    }
  else 
    { 
      /* Data storage was not provided. Deletes the data */
      list->deallocator_ (extracted_data);
    }   
  return 0;
}
