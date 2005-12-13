/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This is contributed code by Daniel Costa Soares
 <daniel_csoares@yahoo.com.br>

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

 System: G.A. Lib

 Description: Inserts a new element in the dclist given a position

 CVS Information
 $Author: ron_lima $
 $Id: dclist_insert.c,v 1.3 2005-12-13 10:18:52 ron_lima Exp $
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "dlist.h"
#include "dclist.h"
#include "gacommon.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_insert.c,v 1.3 2005-12-13 10:18:52 ron_lima Exp $";

int
dclist_insert (dclist_t * dclist, const void *data, position_t whence)
{
  int rc;
  assert (dclist != NULL);

  /* Insert a element at a given position */
  if ((rc = dlist_insert (&dclist->list_, data, whence)) != 0x0)
    {
      return rc;
    }

  /* Make list circular if insertion was done one head or tail */
  if (dclist->list_.head_->prev_ != dclist->list_.tail_)
    {
      dclist->list_.head_->prev_ = dclist->list_.tail_;
    }
  if (dclist->list_.tail_->next_ != dclist->list_.head_)
    {
      dclist->list_.tail_->next_ = dclist->list_.head_;
    }

  return 0x0;
}
