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

 Description: Finishes the queue. This routine will delete the stack
 from the memory

 CVS Information
 $Author: ron_lima $
 $Id: queue_destroy.c,v 1.1 2005-02-19 16:47:32 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: queue_destroy.c,v 1.1 2005-02-19 16:47:32 ron_lima Exp $";

int
queue_destroy (queue_t * queue)
{
  /* Assertives for debugging purposes */
  assert (queue != NULL);
  return list_destroy ((list_t *) queue);
}
