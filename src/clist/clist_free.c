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
 $Id: clist_free.c,v 1.5 2005-01-28 00:11:43 ron_lima Exp $
*/
#include <assert.h>
#include "list.h"
#include "clist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_free.c,v 1.5 2005-01-28 00:11:43 ron_lima Exp $";

int
clist_free (clist_t ** clist)
{
  /* Assertives for debugging purposes */
  assert (clist != NULL);
  assert (*clist != NULL);
  /* Just calls the list free function */
  return list_free ((list_t **) clist);
}
