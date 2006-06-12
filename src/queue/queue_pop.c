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

 Description: Pops an element from the queue

 CVS Information
 $Author: harq_al_ada $
 $Id: queue_pop.c,v 1.18 2006-06-12 10:05:29 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdio.h>
#include "list.h"
#include "queue.h"
#include "queue_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: queue_pop.c,v 1.18 2006-06-12 10:05:29 harq_al_ada Exp $";

int
queue_pop (queue_t queue, void **data)
{
  int rc = 0x0;
  list_t list = NULL;
  
  assert (queue != NULL);
  if (! queue_is_valid_(queue))
    {
      rc = EGAINVAL;
    }
  else 
    {
      queue_get_list_ (queue, &list);
      rc = list_del (list, data, POS_HEAD);
    }
  return rc;
}
