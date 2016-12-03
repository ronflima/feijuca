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

*/
#include <assert.h>
#include <stdio.h>
#include "fjc_list.h"
#include "fjc_queue.h"
#include "fjc_queue_.h"

fjc_error_t
fjc_queue_pop (fjc_queue_t queue, void **data)
{
  fjc_error_t rc = E_FJC_OK;
  fjc_list_t list = NULL;
  
  assert (queue != NULL);
  if (! fjc_queue_is_valid_(queue))
    {
      rc = E_FJC_INVAL;
    }
  else 
    {
      fjc_queue_get_list_ (queue, &list);
      rc = fjc_list_del (list, data, POS_FJC_HEAD);
    }
  return rc;
}
