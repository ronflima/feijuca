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
 along with G.A. Lib; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  System: G.A. Lib

  Description: Sets the tail of the list. Internal function.

 CVS Information $Author: harq_al_ada $ $Id: list_del.c,v 1.7 2004/07/19 00:53:45
 ron_lima Exp $
 */
#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_set_tail_.c,v 1.2 2006-05-14 18:27:08 harq_al_ada Exp $";

GAERROR 
list_set_tail_ (list_t list, list_element_t tail)
{
  GAERROR rc = EGAOK;

  assert (list != NULL);
  if (! list_is_valid_ (list))
    {
      rc = EGAINVAL;
    }
  else
    {
      list->tail_ = tail;
    }
  return rc;
}
