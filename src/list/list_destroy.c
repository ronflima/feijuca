/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of Feijuca Library.

 Feijuca Library is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by the Free
 Software Foundation; either version 2 of the License, or (at your option) any
 later version.

 Feijuca Library is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with
 Feijuca Library; if not, write to the Free Software Foundation, Inc., 59 Temple
 Place, Suite 330, Boston, MA 02111-1307 USA

 System: Feijuca Library

 Description: Finishes a list. This routine will delete the whole list
 from memory
*/
#include <assert.h>
#include <string.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id$";

void
list_destroy (list_t list)
{
  assert (list != NULL);  
  while (list_del (list, NULL, POS_HEAD) == 0x0)
    ;
  memset(list, 0x0, sizeof(struct list_t));
  free (list);
}
