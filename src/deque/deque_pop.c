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

 Description: Pops an element from the deque giving a valid position (HEAD or TAIL)

 CVS Information
 $Author: daniel_csoares $
 $Id: deque_pop.c,v 1.4 2005-08-23 12:58:36 daniel_csoares Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "gacommon.h"
#include "deque.h"
#include "dlist.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: deque_pop.c,v 1.4 2005-08-23 12:58:36 daniel_csoares Exp $";

int
deque_pop (deque_t * deque, void **data, position_t whence)
{

  assert (deque != NULL);

  /* Check if giving a valid position (HEAD or TAIL) */
  if ((whence != POS_HEAD) && (whence != POS_TAIL))
    {
      return EGAINVAL;
    }

  return dlist_del ((dlist_t *) deque, data, whence);
}
