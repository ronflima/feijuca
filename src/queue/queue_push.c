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

 Description: Pushes a new element into the queue

 CVS Information
 $Author: daniel_csoares $
 $Id: queue_push.c,v 1.15 2006-04-24 12:36:33 daniel_csoares Exp $
*/
#include <assert.h>
#include "list.h"
#include "queue.h"
#include "queue_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: queue_push.c,v 1.15 2006-04-24 12:36:33 daniel_csoares Exp $";

int
queue_push (queue_t queue, const void *data)
{
  list_t * list = 0x0;
    
  assert (queue != NULL);
  if (! queue_is_valid(queue))
    {
      return EGAINVAL;
    }

  queue_get_list_(queue,list);

  return list_insert (*list, data, POS_TAIL);
}
