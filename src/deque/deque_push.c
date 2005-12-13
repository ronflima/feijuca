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

 System: G.A. Lib

 Description: Pushes a new element into the deque giving a valid position
 (HEAD or TAIL)

 CVS Information
 $Author: ron_lima $
 $Id: deque_push.c,v 1.6 2005-12-13 10:18:52 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gacommon.h"
#include "deque.h"
#include "dlist.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: deque_push.c,v 1.6 2005-12-13 10:18:52 ron_lima Exp $";

int
deque_push (deque_t * deque, const void *data, position_t whence)
{
  assert (deque != NULL);

  CHECK_SIGNATURE (deque, GA_DEQUE_SIGNATURE);
  if ((whence != POS_HEAD) && (whence != POS_TAIL))
    {
      return EGAINVAL;
    }

  /* Calls the dlist insert function */
  return dlist_insert (&deque->list_, data, whence);
}
