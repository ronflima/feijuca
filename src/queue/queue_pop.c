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
 along with G.A. Lib; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: G.A. Lib

 Description: Pops an element from the queue

 CVS Information
 $Author: daniel_csoares $
 $Id: queue_pop.c,v 1.4 2004-10-07 19:40:05 daniel_csoares Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "list.h"

int
queue_pop(queue_t * queue, void **data)
{
  int rc = 0x0;
  
  /* Assertives for debugging purposes */
  assert(queue != NULL);
  /* Moves to the beginning of the list. We need to extract the first element
     entered into the queue */
  rc = list_move((list_t *) queue, HEAD);
  /* Check if there was an error */
  if (rc) {
    return rc;
  }
  return list_del((list_t *) queue, data);
}
