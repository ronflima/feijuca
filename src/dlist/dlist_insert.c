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
 $Id: dlist_insert.c,v 1.2 2004-03-01 00:05:16 ron_lima Exp $
*/
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"
/*
 * Local prototypes
 */
static int 
relink_list (DLIST *list, DLIST_ELEMENT *element, int whence);

/*
 * Exported functions
 */
int 
dlist_insert (DLIST * list, const void *data, int whence)
{
  DLIST_ELEMENT * element;      /* New element to be inserted */
  /* Allocates memory for the new element */
  element = (DLIST_ELEMENT *) malloc (sizeof( DLIST_ELEMENT ));
  if (! element)
    {
      errno = ENOMEM;
      return -1;
    }
  element->data_ = (void *) data;
  element->next_ = (DLIST_ELEMENT *) NULL;
  element->prev_ = (DLIST_ELEMENT *) NULL;
  /* Check the size of the list */
  if (! list->size_)
    {
      /* This is the head of the list */
      list->head_ = element;
      list->tail_ = element;
    }
  else
    {
      /* Relinks the list based on whence parameter */
      if (relink_list (list, element, whence))
        {
          free (element);
          return -1;
        }
    }
  list->curr_ = element;
  list->size_++;
  return 0;
}

/*
 * Local functions
 */

/* Helper function: will relink the list based on the selected
   insertions position */
static int 
relink_list (DLIST *list, DLIST_ELEMENT *element, int whence)
{
  switch (whence)
    {
    case NEXT:                  /* Inserts the new element after the
                                   current pointer */
      if (list->curr_)
        {
          element->next_ = list->curr_->next_;
          element->prev_ = list->curr_;
          list->curr_->next_ = element;
        }
      else
        {
          errno = EFAULT;
          return -1;
        }
      break;
    case PREV:                  /* Inserts the new element before the
                                   current pointer */
      if (list->curr_)
        {
          element->next_ = list->curr_;
          element->prev_ = list->curr_->prev_;
          list->curr_->prev_ = element;
        }
      else 
        {
          errno = EFAULT;
          return -1;
        }
      break;
    case HEAD:                  /* Inserts the new element in the head
                                   of the list */
      element->next_ = list->head_->next_;
      list->head_->prev_ = element;
      list->head_ = element;
      break;
    case TAIL:                  /* Inserts the new element in the tail
                                   of the list */
      element->prev_ = list->tail_;
      list->tail_->next_ = element;
      list->tail_ = element;
      break;
    default:                    /* Invalid parameter provided */
      errno = EINVAL;
      return -1;
    }
  return 0;
}
