/* -*-c-*-
   Copyright (c) 2016 Ronaldo Faria Lima
   
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.

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
static void
relink_list_ __P ((fjc_dlist_t, fjc_dlist_element_t));

/*
 * This function relinks the list head when it was required to delete it.
 */
static void
relink_list_head_ __P ((fjc_dlist_t));

/*
 * This function relinks the list tail when it was required to delete it.
 */
static void
relink_list_tail_ __P ((fjc_dlist_t));


/*
 * Exported functions
 */
fjc_error_t
fjc_dlist_del (fjc_dlist_t list, fjc_position_t whence, void **data)
{
  fjc_dlist_element_t element = NULL;	/* Current element being processed */

  assert (list != NULL);
  if (list->size_ == 0x0u)
    {
      return E_FJC_EOF;
    }
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
    }
  if (element == NULL)
    {
      /* No data for current settings */
      return E_FJC_EOF;
    }
  if (data != NULL)
    {
      *data = (void *)element->data_;
    }
  else 
    {
      list->deallocator_ (element->data_);
    }
  relink_list_ (list, element);
  free (element);
  --(list->size_);
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
