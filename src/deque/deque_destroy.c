/* -*-c-*-
 Copyright Daniel Costa Soares (C) 2005 - All rights reserved
 Feel free to contact the author in <daniel_csoares@yahoo.com.br>

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

 Description: Finishes the deque. This routine will delete the deque
 from the memory

 CVS Information
 $Author $
 $Id $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"
#include "dlist.h"

/* Version info */
static char const rcsid[] = "@(#) $Id $";

int
deque_destroy (deque_t * deque)
{
  assert (deque != NULL);

  return dlist_destroy ((dlist_t *) deque);
}
