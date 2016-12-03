/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of Feijuca Library.

 Feijuca Library is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 Feijuca Library is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURFJC_POSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Feijuca Library; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: Feijuca Library

 Description: Inserts a new element in the list

*/
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fjc_list.h"
#include "fjc_list_.h"

fjc_error_t
fjc_list_insert (fjc_list_t list, const void *data, fjc_position_t whence)
{
  fjc_list_element_t element;

  assert (list != NULL);
  assert (data != NULL);
  element = (fjc_list_element_t) malloc (sizeof (struct fjc_list_element_t));
  if (element == NULL)
    {
      return E_FJC_NOMEM;
    }
  memset (element, 0x0, sizeof (struct fjc_list_element_t));
  element->data_ = data;
  if (list->size_ == 0x0)
    {
      list->head_ = list->tail_ = element;
    }
  else
    {
      switch (whence)
        {
        case POS_FJC_HEAD:
          element->next_ = list->head_;
          list->head_ = element;
          break;
        case POS_FJC_TAIL:
          list->tail_->next_ = element;
          list->tail_ = element;
          break;
        case POS_FJC_NEXT:
          if (list->curr_ == NULL)
            {
              free (element);
              return E_FJC_BADC;
            }
          element->next_ = list->curr_->next_;
          list->curr_->next_ = element;
          break;
        default:
          free (element);
          return E_FJC_INVAL;
        }
    }
  ++ (list->size_);
  return E_FJC_OK;
}
