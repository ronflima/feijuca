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
 $Id: clist_insert.c,v 1.11 2005-10-08 20:25:00 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "clist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_insert.c,v 1.11 2005-10-08 20:25:00 ron_lima Exp $";

int
clist_insert (clist_t * clist, const void *data)
{
  list_element_t *element;

  assert (clist != NULL);
  CHECK_SIGNATURE (clist, GA_CLIST_SIGNATURE);

  /* Allocates memory for the new element */
  element = (list_element_t *) malloc (sizeof (list_element_t));
  assert (element != NULL);
  if (element == NULL)
    {
      return EGANOMEM;
    }
  element->data_ = (void *) data;
  element->next_ = (list_element_t *) NULL;
  /* Check the size of the list */
  if (clist->list_.size_ == 0x0)
    {
      /* This is the head of the list */
      clist->list_.head_ = element;
      clist->list_.tail_ = element;
    }
  else
    {
      /* Insert at the end */
      clist->list_.tail_->next_ = element;
      clist->list_.tail_ = element;
    }
  /* Makes the circular link in the list */
  clist->list_.tail_->next_ = clist->list_.head_;
  clist->list_.curr_ = element;
  clist->list_.size_++;

  return 0x0;
}
