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

   Description: Deletes and element from the list. This element can be the head
   or the next element from the current pointer. It is possible to delete other
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
