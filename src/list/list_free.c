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

 Description: Finishes a list. This routine will delete the whole list
 from memory

 CVS Information
 $Author: ron_lima $
 $Id: list_free.c,v 1.1 2004-02-29 10:30:55 ron_lima Exp $
*/
#include <stdlib.h>
#include <stdlib.h>
#include "list.h"

int
list_free (LIST ** list)
{
  /* Makes the current pointer pointing to nowhere. It will force
     list_del to delete always from the head of the list */
  (*list)->curr_ = NULL;
  /* Proceeds with the deletion */
  while ((*list)->size_)
    {
      list_del (*list, NULL);
    }
  /* Deletes the list descriptor from memory */
  free (*list);
  *list = (LIST *) 0x0;
  return 0x0;
}
 
