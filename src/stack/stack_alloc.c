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

 Description: Allocates and initializes a stack

 CVS Information
 $Author: daniel_csoares $
 $Id: stack_alloc.c,v 1.5 2004-10-07 19:47:43 daniel_csoares Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "list.h"

int
stack_alloc(stack_t ** stack, deallocator_t * dealloc)
{
  /* Assertives for debugging purposes */
  assert(stack != NULL);
  assert(dealloc != NULL);
  return list_alloc((list_t **) stack, dealloc);
}
