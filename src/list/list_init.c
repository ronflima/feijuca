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

 Description: Allocates and initializes the list

 CVS Information
 $Author: harq_al_ada $
 $Id: list_init.c,v 1.12 2007-02-14 22:47:20 harq_al_ada Exp $
*/
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_init.c,v 1.12 2007-02-14 22:47:20 harq_al_ada Exp $";

GAERROR
list_init (list_t * list, deallocator_t * dealloc)
{
  GAERROR rc; /* Error handling */

  assert (list != NULL);
  assert (dealloc != NULL);

  rc=EGAOK;
  if (list == NULL || dealloc == NULL)
    {
      rc = EGAINVAL;
    }
  else if ((*list = (list_t) malloc (sizeof (struct list_t))) == NULL)
    {
      rc = EGANOMEM;
    }
  else 
    {
      memset(*list, 0x0, sizeof(struct list_t));
      list_set_signature_(*list);
      list_set_head_(*list, NULL);
      list_set_tail_(*list, NULL);
      list_set_curr_(*list, NULL);
      list_set_deallocator_(*list, dealloc);
    }
  return rc;
}
