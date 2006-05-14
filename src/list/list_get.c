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

 Description: Gets the current element of the list and iterates to the
 next one

 CVS Information
 $Author: harq_al_ada $
 $Id: list_get.c,v 1.23 2006-05-14 18:27:07 harq_al_ada Exp $
*/
#include <stdio.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_get.c,v 1.23 2006-05-14 18:27:07 harq_al_ada Exp $"; 

GAERROR
list_get (list_t list, void **data, position_t whence)
{
  GAERROR rc = EGAOK;

  assert (list != NULL);
  assert (data != NULL);
  if (! list_is_valid_(list) || (data == NULL))
    {
      rc = EGAINVAL;
    }
  else
    {
      if (whence == POS_HEAD)
        {
          rc = list_element_get_data_ (list->head_, data);
        }
      else if (whence == POS_TAIL)
        {
          rc = list_element_get_data_ (list->tail_, data);
        }
      else if (whence == POS_NEXT)
        {
          if (list->curr_ != NULL)
            {
              list_element_t next;
              if ((rc = list_element_get_next_ (list->curr_, &next)) == 0x0)
                {
                  rc = list_element_get_data_ (next, data);
                }
            }
        }
      else if (whence == POS_CURR)
        {
          rc = list_element_get_data_ (list->curr_, data);
        }
      else
        {
          rc = EGAINVAL;
        }
    }
  return rc;
}
