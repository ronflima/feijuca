/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

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

 Description: Finishes a list. This routine will delete the whole list
 from memory
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#include "dlist_.h"

/* Version info */
static char const rcsid[] = "@(#) $Id$";

void
dlist_destroy (dlist_t list)
{
  assert (list != NULL);

  /* Proceeds with the deletion - Deletes the list from the head, always */
  while (dlist_del (list, NULL, POS_HEAD) == EGAOK)
    ;

  free (list);
}
