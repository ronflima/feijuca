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

 Description: Finishes the stack. This routine will delete the stack
 from the memory

 CVS Information
 $Author: ron_lima $
 $Id: stack_free.c,v 1.5 2005-01-28 00:11:45 ron_lima Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: stack_free.c,v 1.5 2005-01-28 00:11:45 ron_lima Exp $";

int
stack_free (stack_t ** stack)
{
  /* Assertives for debugging purposes */
  assert (stack != NULL);
  assert (*stack != NULL);
  return list_free ((list_t **) stack);
}
