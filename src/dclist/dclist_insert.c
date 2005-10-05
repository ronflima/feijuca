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

 Description: Inserts a new element in the dclist given a position

 CVS Information
 $Author: daniel_csoares $
 $Id: dclist_insert.c,v 1.1 2005-10-05 12:19:19 daniel_csoares Exp $
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "dlist.h"
#include "dclist.h"
#include "gacommon.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_insert.c,v 1.1 2005-10-05 12:19:19 daniel_csoares Exp $";

int
dclist_insert (dclist_t * list, const void *data, position_t whence)
{
  int rc;
  assert (list != NULL);

  /* Insert a element at a given position */
  rc = dlist_insert ((dlist_t *) list, data, whence);
  if (rc)
    {
      return rc;
    }

  /* Make list circular if insertion was done one head or tail */
  if (list->head_->prev_ != list->tail_)
    {
      list->head_->prev_ = list->tail_;
    }
  if (list->tail_->next_ != list->head_)
    {
      list->tail_->next_ = list->head_;
    }

  return 0x0;
}
