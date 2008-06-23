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
*/
#include <stdlib.h>
#include <assert.h>
#include "dlist.h"
#include "dlist_.h"

/* Version info */
static char const rcsid[] = "@(#) $Id$";

/*
 * Local prototypes
 */

/*
 * This function relinks list after insertion of new element.
 */
static GAERROR relink_list_ __P ((dlist_t, dlist_element_t, position_t));

/*
 * Exported functions
 */
GAERROR
dlist_insert (dlist_t list, const void *data, position_t whence)
{
  GAERROR rc = EGAOK;
  dlist_element_t element = NULL;

  assert (list != NULL);
  assert (data != NULL);

  if ((element =
       (dlist_element_t) malloc (sizeof (struct dlist_element_t))) == NULL)
    {
      rc = EGANOMEM;
    }
  else
    {
      element->data_ = (void *) data;
      element->next_ = NULL;
      element->prev_ = NULL;

      if (list->size_ == 0x0)
        {
          list->head_ = element;
          list->tail_ = element;
        }
      else
        {
          /* Effectively inserts the new element into the list */
          if ((rc = relink_list_ (list, element, whence)) != EGAOK)
            {
              free (element);
            }
        }
      if (rc == EGAOK)
        {
          list->size_++;
        }
    }

  return rc;
}

/*
 * Local functions
 */

/*
 * This function relinks list after insertion of new element.
 */
static GAERROR
relink_list_ (dlist_t list, dlist_element_t element, position_t whence)
{
  if (whence == POS_HEAD)
    {
      element->next_ = list->head_;
      element->prev_ = NULL;
      list->head_->prev_ = element;
      list->head_ = element;
    }
  else if (whence == POS_TAIL)
    {
      element->prev_ = list->tail_;
      element->next_ = NULL;
      list->tail_->next_ = element;
      list->tail_ = element;
    }
  else
    {
      if (list->curr_ == NULL)
        {
          return EGABADC;
        }
      else
        {
          if (whence == POS_PREV)
            {
              element->next_ = list->curr_;
              element->prev_ = list->curr_->prev_;
              if (element->prev_ != NULL)
        	{
        	  element->prev_->next_ = element;
        	}
              list->curr_->prev_ = element;
              if (list->curr_ == list->head_)
        	{
        	  list->head_ = element;
        	}
            }
          else if (whence == POS_NEXT)
            {
              element->next_ = list->curr_->next_;
              element->prev_ = list->curr_;
              if (element->next_ != NULL)
        	{
        	  element->next_->prev_ = element;
        	}
              list->curr_->next_ = element;
              if (list->curr_ == list->tail_)
        	{
        	  list->tail_ = element;
        	}
            }
          else
            {
              return EGAINVAL;
            }
        }
    }
  return EGAOK;
}
