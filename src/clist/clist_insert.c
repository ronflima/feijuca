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
#include "clist.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id$";

GAERROR
clist_insert (clist_t clist, const void *data, position_t whence)
{
  list_element_t element;

  assert (clist != NULL);
  assert (data != NULL);
  if ((element = (list_element_t) malloc (sizeof (struct list_element_t))) == NULL)
    {
      return EGANOMEM;
    }
  memset (element, 0x0, sizeof (struct list_element_t));
  element->data_ = data;
  if (clist->size_ == 0x0)
    {
      clist->head_ = clist->tail_ = element;
    }
  else
    {
      switch (whence)
	{
	case POS_HEAD:
	  element->next_ = clist->head_;
	  clist->head_ = element;
	  break;
	case POS_TAIL:
	  clist->tail_->next_ = element;
	  clist->tail_ = element;
	  break;
	case POS_NEXT:
	  if (clist->curr_ == NULL)
	    {
	      free (element);
	      return EGABADC;
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
	  return EGAINVAL;
	}
    }
  clist->tail_->next_ = clist->head_;
  ++ (clist->size_);
  return EGAOK;
}
