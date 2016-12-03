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
 along with Feijuca Library; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  System: Feijuca Library

  Description: Deletes the next element pointed by element
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fjc_list.h"
#include "fjc_list_.h"

fjc_position_t
fjc_list_get_pos (fjc_list_t list)
{
  assert (list != NULL);

  if ((list->curr_ == NULL) || (list->size_ == 0x0))
    {
      return POS_FJC_NONE;
    }
  if (list->curr_ == list->head_) 
    {
      return POS_FJC_HEAD;
    }
  if (list->curr_ == list->tail_)
    {
      return POS_FJC_TAIL;
    }
  return POS_FJC_MID;
}
