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

 Description: Allocates and initializes the circular list

 CVS Information
 $Author: ron_lima $
 $Id: clist_alloc.c,v 1.4 2004-10-13 10:23:44 ron_lima Exp $
*/
#include <assert.h>
#include "list.h"
#include "clist.h"

int
clist_alloc (clist_t ** clist, deallocator_t * dealloc)
{
  /* Assertives for debugging purposes */
  assert (clist != NULL);
  assert (dealloc != NULL);
  /* Just calls the list allocation function */
  return list_alloc ((list_t **) clist, dealloc);
}
