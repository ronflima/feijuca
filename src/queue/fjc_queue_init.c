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

*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "fjc_list.h"
#include "fjc_queue.h"
#include "fjc_queue_.h"

fjc_error_t
fjc_queue_init (fjc_queue_t * queue, fjc_deallocator_t * dealloc)
{
  fjc_error_t rc = E_FJC_OK;
  
  assert (queue != NULL);
  assert (dealloc != NULL);
  if (queue == NULL || dealloc == NULL)
    {
      rc =  E_FJC_INVAL;
    }
  else if ((*queue = (fjc_queue_t) malloc (sizeof (struct fjc_queue_t))) == NULL)
    {
      rc = E_FJC_NOMEM;
    }
  else
    {
      fjc_list_t list = NULL;
      (*queue)->signature_ = FJC_QUEUE_SIGNATURE;
      if ((rc = fjc_list_init (&list, dealloc)) != E_FJC_OK)
        {
          free (*queue);
        }
      else 
        {
          fjc_queue_set_list_(*queue, list);
        }
    }
  return rc;
}
