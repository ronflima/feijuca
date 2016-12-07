/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This is contributed code by Daniel Costa Soares
 <daniel_csoares@yahoo.com.br>

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

 System: Feijuca Library

 Description: Pushes a new element into the deque giving a valid position
 (HEAD or TAIL)
*/

#include <assert.h>
#include "fjc_dlist.h"
#include "fjc_deque.h"
#include "fjc_deque_.h"

fjc_error_t
fjc_deque_push (fjc_deque_t deque, const void *data, fjc_position_t whence)
{
  assert (deque != NULL);
  if (deque == NULL)
    {
      return E_FJC_INVAL;
    }
  if (deque->signature_ != FJC_DEQUE_SIGNATURE)
    {
      return E_FJC_INVAL;
    }
  if ((whence != POS_FJC_HEAD) && (whence != POS_FJC_TAIL))
    {
      return E_FJC_INVAL;
    }
  /* Calls the dlist insert function */
  return fjc_dlist_insert (deque->list_, data, whence);
}
