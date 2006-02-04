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
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_del.c,v 1.22 2006-02-04 21:25:16 harq_al_ada Exp $";

int
list_del (list_t list, void **data, position_t whence)
{
  void *extracted_data;		/* Data extracted from the list */
  int rc = 0x0;                 /* General error handling variable */

  assert (list != NULL);
  if (list == NULL)
    {
      rc = EGAINVAL;
    }
  else 
    {
      CHECK_SIGNATURE (list, GA_LIST_SIGNATURE);      
      if (data != NULL)
        {
          *data = (void *) NULL;
        }
      if (list->size_ == 0x0u)
        {
          rc = EOF;
        }
      else if ((data == NULL) && (list->deallocator_ == NULL))
        {
          rc = EGAINVAL;
        }
      else 
        {
          list_element_t * element = NULL; /* Element to be deleted */

          /* Extracts the element from the list and delete it. There
           * are two valid positions: the head and the next after the
           * current. Any other position cannot be operated since the
           * list have not enough information to do so. */
          if (whence == POS_HEAD)
            {
              element = list->head_;
              list->head_ = element->next_;
              /* Notifies the current position. If it is pointing to
               * the old head, updates it to the new head position in
               * order to avoid inconsistencies  */
              if ((list->curr_ != NULL)  && (list->curr_ == element))
                {
                  list->curr_ = list->head_;
                }
              /* If the head became NULL, means that the list was
               * emptied. Therefore, makes the tail point to nowhere
               * also. */
              if (list->head_ == NULL)
                {
                  list->tail_ = NULL;
                }
            }
          else if (whence == POS_NEXT)
            {
              if (list->curr_ != NULL) 
                {
                  if ((element = list->curr_->next_) == NULL)
                    {
                      rc = EOF;
                    }
                  else if (element == list->tail_)
                    {
                      /* If the element to delete is the tail, updates
                       * the tail to the current, since we are
                       * deleting the next element. */
                      list->tail_ = list->curr_;
                      list->tail_->next_ = NULL;
                    }
                  else
                    {
                      /* Relinks the list, extracting out the element
                       * we selected to delete. */
                      list->curr_->next_ = element->next_;
                    }
                }
            }
          if (element != NULL)
            {
              if (data != NULL)
                {
                  *data = element->data_;
                }
              else if (list->deallocator_ != NULL)
                {
                  list->deallocator_ (element->data_);
                }
              free (element);
              --(list->size_);
            }
          else
            {
              /* No element to operate on. This is caused by an
               * invalid situation. Therefore, informs the caller that
               * something went wrong within the deletion request. */
              rc = EGAINVAL;
            }
        }
    }
  return rc;
}
