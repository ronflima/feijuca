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

 Description: Gets the current element of the list and iterates to the
 next one
*/
#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id$"; 

const void *
list_get (list_t list, position_t whence)
{
  list_element_t element = NULL;

  assert (list != NULL);
  switch (whence)
    {
    case POS_HEAD:
      element = list->head_;
      break;
    case POS_TAIL:
      element = list->tail_;
      break;
    case POS_NEXT:
      if (list->curr_ != NULL) 
	{
	  element = list->curr_->next_;
	}
      break;
    case POS_CURR:
      element = list->curr_;
      break;
    default:
      return NULL;
    }
  if (element == NULL)
    {
      return NULL;
    }
  return element->data_;
}
