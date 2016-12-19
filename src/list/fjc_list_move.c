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

 Description: Moves the curr_ pointer depending on the parameter of
 the list
*/
#include <stdio.h>
#include <assert.h>
#include "fjc_list.h"
#include "fjc_list_.h"

fjc_error_t
fjc_list_move (fjc_list_t list, fjc_position_t whence)
{
  assert (list != NULL);
  switch (whence)
    {
    case POS_FJC_HEAD:
      list->curr_ = list->head_;
      break;
    case POS_FJC_TAIL:
      list->curr_ = list->tail_;
      break;
    case POS_FJC_NEXT:
      if (list->curr_ == NULL || list->curr_->next_ == NULL)
        {
          return E_FJC_EOF;
        }
      list->curr_ = list->curr_->next_;
      break;
    default:
      return E_FJC_INVAL;
      break;
    }
  return E_FJC_OK;
}
