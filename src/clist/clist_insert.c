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
 $Id: clist_insert.c,v 1.5 2004-10-05 10:29:27 ron_lima Exp $
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "clist.h"

int
clist_insert(clist_t * clist, const void *data)
{
  clist_element_t *element;

  /* Assertives for debugging purposes */
  assert(clist != NULL);
  /* Allocates memory for the new element */
  element = (clist_element_t *) malloc(sizeof(clist_element_t));
  assert(element != NULL);
  if (!element)
  {
    errno = ENOMEM;
    return -1;
  }
  element->data_ = (void *)data;
  element->next_ = (clist_element_t *) NULL;
  /* Check the size of the list */
  if (!clist->size_)
  {
    /* This is the head of the list */
    clist->head_ = element;
    clist->tail_ = element;
  }
  else
  {
    /* Insert at the end */
    clist->tail_->next_ = element;
    clist->tail_ = element;
  }
  /* Makes the circular link in the list */
  clist->tail_->next_ = clist->head_;
  clist->curr_ = element;
  clist->size_++;
  return 0;
}
