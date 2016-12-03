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
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Feijuca Library; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: Feijuca Library

 Description: Reverses the list using a moving window algorithm
*/
#include <stdio.h>
#include <assert.h>
#include "fjc_list.h"
#include "fjc_list_.h"

fjc_error_t
list_reverse (fjc_list_t list)
{
  fjc_list_element_t first;  /* First item of the window */
  fjc_list_element_t middle; /* Middle item of the window */

  assert (list != NULL);
  if (list->size_ < 0x2u)
    {
      return E_FJC_EOF;
    }
  first = list->head_;
  middle = list->head_->next_;
  list->tail_ = list->head_;
  list->head_ = list->tail_;
  do
    {
      fjc_list_element_t last;	/* Last item of the window */
                              
      /* Sets the last item of the window */
      if ((last = middle->next_) == NULL)
        {
          break;
        }
      /* Relinks the item, reversing its position */
      if ((middle->next_ = first) == NULL)
        {
          break;
        }
      /* Moves the window */
      first = middle;
      middle = last;
    }
  while (middle != NULL);

  list->tail_->next_ = NULL;
  return E_FJC_OK;
}
