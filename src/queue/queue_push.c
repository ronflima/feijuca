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
 $Author: ron_lima $
 $Id: queue_push.c,v 1.12 2005-12-13 10:18:52 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: queue_push.c,v 1.12 2005-12-13 10:18:52 ron_lima Exp $";

int
queue_push (queue_t * queue, const void *data)
{
  assert (queue != NULL);
  CHECK_SIGNATURE (queue, GA_QUEUE_SIGNATURE);

  return list_insert (&queue->list_, data, POS_TAIL);
}
