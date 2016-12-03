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
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fjc_dlist.h"
#include "fjc_dlist_.h"

/*
 * Local prototypes
 */

/*
 * This function relinks the list extracting the element pointed by
 * the parameter element from the list. This function guarantees that
 * the list will be linked correctly after the operation.
 */
static void relink_list_ __P ((fjc_dlist_t, fjc_dlist_element_t));

/*
 * This function relinks the list head when it was required to delete it.
 */
static void relink_list_head_ __P ((fjc_dlist_t));

/*
 * This function relinks the list tail when it was required to delete it.
 */
static void relink_list_tail_ __P ((fjc_dlist_t));


/*
 * Exported functions
 */
fjc_error_t
dlist_del (fjc_dlist_t list, void **data, fjc_position_t whence)
{
  fjc_dlist_element_t element = NULL;	/* Current element being processed */

  assert (list != NULL);
  assert (data != NULL);

  if (data != NULL)
    {
      *data = (void *) NULL;
    }

  if (list->size_ == 0x0u)
    {
      return E_FJC_EOF;
    }
  else
    {
      if (whence == POS_FJC_HEAD)
        {
          element = list->head_;
          relink_list_head_ (list);
        }
      else if (whence == POS_FJC_TAIL)
        {
          element = list->tail_;
          relink_list_tail_ (list);
        }
      else
        {
          if (list->curr_ == NULL)
            {
              return E_FJC_BADC;
            }
          else
            {
              if (whence == POS_FJC_CURR)
                {
                  element = list->curr_;
                  list->curr_ = NULL;
                }
              else if (whence == POS_FJC_NEXT)
                {
                  element = list->curr_->next_;
                }
              else if (whence == POS_FJC_PREV)
                {
                  element = list->curr_->prev_;
                }
              else
                {
                  return E_FJC_INVAL;
                }
              /* Redo list pointers */
              relink_list_ (list, element);
            }
        }
    }
  if (element)
    {
      if (data != NULL)
        {
          *data = element->data_;
        }
      else
        {
          list->deallocator_ (element->data_);
        }
      free (element);
      --(list->size_);
    }
  return E_FJC_OK;
}


/*
 * This function relinks the list head when it was required to delete it.
 */
static void
relink_list_head_ (fjc_dlist_t list)
{
  list->head_ = list->head_->next_;
  if (list->head_)
    {
      list->head_->prev_ = NULL;
    }
}

/*
 * This function relinks the list tail when it was required to delete it.
 */
static void
relink_list_tail_ (fjc_dlist_t list)
{
  list->tail_ = list->tail_->prev_;
  if (list->tail_)
    {
      list->tail_->next_ = NULL;
    }
}

/*
 * Internal functions definitions
 */
static void
relink_list_ (fjc_dlist_t list, fjc_dlist_element_t element)
{
  if (element == NULL)
    {
      return;
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
      relink_list_head_ (list);
    }
  if (element == list->tail_)
    {
      relink_list_tail_ (list);
    }
}
