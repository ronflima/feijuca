/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of G.A. Lib.

 G.A. Lib is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 G.A. Lib is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with G.A. Lib; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: G.A. Lib

 Description: Inserts a new element in the list

 CVS Information
 $Author: ron_lima $
 $Id: list_insert.c,v 1.3 2004-02-29 23:59:04 ron_lima Exp $
*/
#include <errno.h>
#include <stdio.h>
#include "list.h"

int 
list_insert (LIST * list, const void *data)
{
  LIST_ELEMENT * element;

  /* Allocates memory for the new element */
  element = (LIST_ELEMENT *) malloc (sizeof( LIST_ELEMENT ));
  if (! element)
    {
      errno = ENOMEM;
      return -1;
    }
  element->data_ = (void *) data;
  element->next_ = (LIST_ELEMENT *) NULL;
  /* Check the size of the list */
  if (! list->size_)
    {
      /* This is the head of the list */
      list->head_ = element;
      list->tail_ = element;
    }
  else
    {
      /* Insert at the end */
      list->tail_->next_ = element;
      list->tail_        = element;
    }
  list->curr_ = element;
  list->size_++;
  return 0;
}
