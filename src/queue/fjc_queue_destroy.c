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

 Description: Finishes the queue. This routine will delete the stack
 from the memory

 CVS Information
 $Author: harq_al_ada $
 $Id: queue_destroy.c,v 1.9 2006-06-12 10:05:29 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fjc_list.h"
#include "fjc_queue.h"
#include "fjc_queue_.h"

fjc_error_t
fjc_queue_destroy (fjc_queue_t queue)
{
  fjc_error_t rc = E_FJC_OK;
  fjc_list_t list = NULL;
  
  assert (queue != NULL);
  if (! fjc_queue_is_valid_ (queue))
    {
      rc = E_FJC_INVAL;
    }
  else 
    {
      fjc_queue_get_list_(queue, &list);
      fjc_list_destroy (list);
      memset (queue, 0x0, sizeof (struct fjc_queue_t));
      free (queue);
    }
  return rc;
}
