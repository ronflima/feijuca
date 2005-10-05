/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br

 This file is part of G.A. Library.

 G.A. Library is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or (at
 your option) any later version.

 G.A. Library is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with G.A. Library; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 USA

 System: G.A. Lib

 Description: Allocates and initializes the dclist (Double-linked
 circular list)

 CVS Information
 $Author: daniel_csoares $
 $Id: dclist_init.c,v 1.1 2005-10-05 12:19:19 daniel_csoares Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dclist.h"
#include "dlist.h"
#include "gacommon.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist_init.c,v 1.1 2005-10-05 12:19:19 daniel_csoares Exp $";

int
dclist_init (dclist_t * list, deallocator_t * dealloc)
{
  /* Assertives for debugging purposes */
  assert (list != NULL);
  assert (dealloc != NULL);

  return dlist_init ((dlist_t *) list, dealloc);
}
