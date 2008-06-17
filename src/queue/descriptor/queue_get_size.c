/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
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

 System: G.A. Lib

 Description: Returns the size of a queue

 CVS Information
 $Author: harq_al_ada $
 $Id: queue_get_size.c,v 1.3 2006-06-12 10:05:29 harq_al_ada Exp $
*/
#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include "list.h"
#include "queue.h"
#include "queue_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: queue_get_size.c,v 1.3 2006-06-12 10:05:29 harq_al_ada Exp $";

int
queue_get_size (queue_t queue, size_t * size)
{
  list_t list = NULL;

  assert (queue != NULL);
  if (! queue_is_valid_ (queue) || size == NULL)
    {
      return EGAINVAL;
    }
  queue_get_list_(queue, &list);
  *size = list_get_size (list);
  return EGAOK;
}
