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

 Description: Inserts a new element in the list
*/
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "fjc_clist.h"
#include "fjc_list_.h"

fjc_error_t
fjc_clist_insert (fjc_clist_t clist, const void *data, fjc_position_t whence)
{
  fjc_list_element_t element;

  assert (clist != NULL);
  assert (data != NULL);
  if ((element = (fjc_list_element_t) malloc (sizeof (struct fjc_list_element_t))) == NULL)
    {
      return E_FJC_NOMEM;
    }
  memset (element, 0x0, sizeof (struct fjc_list_element_t));
  element->data_ = data;
  if (clist->size_ == 0x0)
    {
      clist->head_ = clist->tail_ = element;
    }
  else
    {
      switch (whence)
        {
        case POS_FJC_HEAD:
          element->next_ = clist->head_;
          clist->head_ = element;
          break;
        case POS_FJC_TAIL:
          clist->tail_->next_ = element;
          clist->tail_ = element;
          break;
        case POS_FJC_NEXT:
          if (clist->curr_ == NULL)
            {
              free (element);
              return E_FJC_BADC;
            }
          element->next_ = clist->curr_->next_;
          clist->curr_->next_ = element;
          if (clist->curr_ == clist->tail_)
            {
              clist->head_ = element;
            }
          break;
        default:
          free (element);
          return E_FJC_INVAL;
        }
    }
  clist->tail_->next_ = clist->head_;
  ++ (clist->size_);
  return E_FJC_OK;
}
