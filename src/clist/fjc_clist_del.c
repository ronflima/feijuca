/* -*-c-*-
 Feijuca Library - A generic algorithms and data structures library
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

 System: Feijuca Lib

 Description: Deletes and element from the list. This element can be the head or
 the next element from the current pointer. It is possible to delete other
 positions but the computational cost is too high.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fjc_clist.h"
#include "fjc_list_.h"

/* Local prototypes */
static fjc_list_element_t extract_head_ (fjc_clist_t);
static fjc_list_element_t extract_next_ (fjc_clist_t);

fjc_error_t
fjc_clist_del (fjc_clist_t clist, const void **data, fjc_position_t whence)
{
  fjc_list_element_t element = NULL;	/* Element to be deleted */

  assert (clist != NULL);
  if (clist->size_ == 0x0)
    {
      return E_FJC_EOF;
    }
  switch (whence)
    {
    case POS_FJC_HEAD:
      element = extract_head_ (clist);
      break;
    case POS_FJC_NEXT:
      if (clist->curr_ == NULL) 
        {
          return E_FJC_BADC;
        }
      element = extract_next_ (clist);
      break;
    default:
      return E_FJC_INVAL;
    }
  if (element == NULL)
    {
      return E_FJC_EOF;
    }
  if (data != NULL)
    {
      *data = element->data_;
    }
  else
    {
      clist->deallocator_ (data);
    }
  free (element);
  -- (clist->size_);
  return E_FJC_OK;
}

/* 
 * This function extracts the head element of the list, updating all necessary
 * pointers in order to maintain the list structural integrity.
 */
static fjc_list_element_t
extract_head_ (fjc_clist_t clist)
{
  fjc_list_element_t element = NULL;

  assert (clist != NULL);
  element = clist->head_;
  if (clist->head_ == clist->tail_)
    {
      clist->head_ = NULL;
      clist->tail_ = NULL;
    }
  else
    {
      clist->head_ = clist->head_->next_;
    }
  if (clist->tail_ != NULL)
    {
      clist->tail_->next_ = clist->head_;
    }
  return element;
}

/* 
 * This function extracts the next element from the current position, updating
 * all necessary pointers in order to maintain the list structural integrity. 
 */
static fjc_list_element_t
extract_next_ (fjc_clist_t clist)
{
  fjc_list_element_t element = NULL;

  assert (clist != NULL);
  assert (clist->curr_ != NULL);
  element = clist->curr_->next_;
  if (clist->curr_->next_ != NULL)
    {
      if (clist->curr_->next_ == clist->curr_)
        {
          /* 
           * A single element in the list points to itself. Therefore, the next
           * element from the current is the current itself. Also, it is the
           * head and tail of the list. 
           */
          clist->head_ = NULL;
          clist->tail_ = NULL;
          clist->curr_ = NULL;
        }
      else
        {
          if (clist->curr_->next_ == clist->head_) 
            {
              /* We are about to delete the head. Update it. */
              clist->head_ = clist->head_->next_;
            }
          if (clist->curr_->next_ == clist->tail_)
            {
              /* We are about to update the tail. Update it. */
              clist->tail_ = clist->curr_;
            }
          clist->curr_->next_ = clist->curr_->next_->next_;
        }
    }
  return element;
}
