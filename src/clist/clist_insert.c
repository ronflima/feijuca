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
 $Author: harq_al_ada $
 $Id: clist_insert.c,v 1.14 2006-01-29 12:37:02 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdlib.h>
#include "clist.h"
#include "clist_.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_insert.c,v 1.14 2006-01-29 12:37:02 harq_al_ada Exp $";

int
clist_insert (clist_t clist, const void *data)
{
  list_element_t *element;

  assert (clist != NULL);
  if (clist == NULL)
    {
      return EGAINVAL;
    }
  CHECK_SIGNATURE (clist, GA_CLIST_SIGNATURE);

  /* Allocates memory for the new element */
  if ((element = (list_element_t *) malloc (sizeof (list_element_t))) == NULL)
    {
      return EGANOMEM;
    }
  element->data_ = (void *) data;
  element->next_ = (list_element_t *) NULL;
  /* Check the size of the list */
  if (clist->list_->size_ == 0x0)
    {
      /* This is the head of the list */
      clist->list_->head_ = element;
      clist->list_->tail_ = element;
    }
  else
    {
      /* Insert at the end */
      clist->list_->tail_->next_ = element;
      clist->list_->tail_ = element;
    }
  /* Makes the circular link in the list */
  clist->list_->tail_->next_ = clist->list_->head_;
  clist->list_->curr_ = element;
  ++(clist->list_->size_);

  return 0x0;
}
