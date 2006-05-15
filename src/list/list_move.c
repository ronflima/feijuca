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

 Description: Moves the curr_ pointer depending on the parameter of
 the list

 CVS Information
 $Author: harq_al_ada $
 $Id: list_move.c,v 1.24 2006-05-15 23:19:25 harq_al_ada Exp $
*/
#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_move.c,v 1.24 2006-05-15 23:19:25 harq_al_ada Exp $"; 

GAERROR
list_move (list_t list, position_t whence)
{
  GAERROR rc = EGAOK;
  assert (list != NULL);
  if (! list_is_valid_ (list))
    {
      rc = EGAINVAL;
    }
  else
    {
      list_element_t element = NULL;

      if (whence == POS_HEAD)
        {
          rc = list_get_head_(list, &element);
        }
      else if (whence == POS_TAIL)
        {
          rc = list_get_tail_(list, &element);
        }
      else if (whence == POS_NEXT)
        {
          if((rc = list_get_curr_(list, &element)) == EGAOK)
            {
              if (element != NULL)
                {
                  rc = list_element_get_next_ (element, &element);
                }
              else
                {
                  rc = EGAEOF;
                }
            }
        }
      else
        {
          rc = EGAINVAL;
        }
      if (element != NULL && rc == EGAOK)
        {
          rc = list_set_curr_(list, element);
        }
    }
  return rc;
}
