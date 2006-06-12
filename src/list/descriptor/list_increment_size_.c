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

 Description: Increments the list size by a given value

 CVS Information
 $Author: harq_al_ada $
 $Id: list_increment_size_.c,v 1.2 2006-06-12 10:05:29 harq_al_ada Exp $
*/
#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_increment_size_.c,v 1.2 2006-06-12 10:05:29 harq_al_ada Exp $";

GAERROR
list_increment_size_ (list_t list, int increment)
{
  assert (list != NULL);
  if (list_is_valid_ (list))
    {
      list->size_ += increment;
    }
  else 
    {
      return EGAINVAL;
    }
  return EGAOK;
}
