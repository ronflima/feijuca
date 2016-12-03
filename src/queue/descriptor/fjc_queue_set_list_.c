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
 along with G.A. Lib; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  System: G.A. Lib

  Description: Gets the head of the list. Internal function.
 */
#include <stdio.h>
#include <assert.h>
#include "fjc_list.h"
#include "fjc_queue.h"
#include "fjc_queue_.h"

fjc_error_t 
fjc_queue_set_list_ (fjc_queue_t queue, fjc_list_t list)
{
  fjc_error_t rc = E_FJC_OK;

  assert (queue != NULL);
  if (! fjc_queue_is_valid_ (queue))
    {
      rc = E_FJC_INVAL;
    }
  else
    {
      queue->list_ = list;
    }
  return rc;
}
