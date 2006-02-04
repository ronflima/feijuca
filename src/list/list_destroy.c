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
 $Author: harq_al_ada $
 $Id: list_destroy.c,v 1.7 2006-02-04 21:25:49 harq_al_ada Exp $
*/
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_destroy.c,v 1.7 2006-02-04 21:25:49 harq_al_ada Exp $";

int
list_destroy (list_t list)
{
  assert (list != NULL);
  if (list == NULL) 
    {
      return EGAINVAL;
    }
  CHECK_SIGNATURE (list, GA_LIST_SIGNATURE);
  
  /* Deletes each single member of the list */
  while (list_del (list, NULL, POS_HEAD) == 0x0)
    ;
  list->signature_ = (ga_magic_t)0x0;
  free (list);
  
  return 0x0;
}
