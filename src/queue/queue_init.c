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

 Description: Allocates and initializes a queue

 CVS Information
 $Author: harq_al_ada $
 $Id: queue_init.c,v 1.8 2006-05-14 00:49:29 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "queue.h"
#include "queue_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: queue_init.c,v 1.8 2006-05-14 00:49:29 harq_al_ada Exp $";

int
queue_init (queue_t * queue, deallocator_t * dealloc)
{
  int rc = 0x0;
  
  assert (queue != NULL);
  assert (dealloc != NULL);
  if (queue == NULL || dealloc == NULL)
    {
      rc =  EGAINVAL;
    }
  else if ((*queue = (queue_t) malloc (sizeof (struct queue_t))) == NULL)
    {
      rc = EGANOMEM;
    }
  else
    {
      list_t list = NULL;
      (*queue)->signature_ = GA_QUEUE_SIGNATURE;
      if ((rc = list_init (&list, dealloc)) != 0x0)
        {
          free (*queue);
        }
      else 
        {
          queue_set_list_(*queue, list);
        }
    }
  return rc;
}
