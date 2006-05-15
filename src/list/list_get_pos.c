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

  Description: Deletes the next element pointed by element

 CVS Information $Author: harq_al_ada $ $Id: list_del.c,v 1.7 2004/07/19 00:53:45
 ron_lima Exp $
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_get_pos.c,v 1.3 2006-05-15 23:19:25 harq_al_ada Exp $";

GAERROR 
list_get_pos (list_t list, position_t * whence)
{
  GAERROR rc = EGAOK;

  if (! list_is_valid_ (list))
    {
      rc = EGAINVAL;
    }
  else 
    {
      size_t size;

      if((rc = list_get_size(list, &size)) == EGAOK)
        {
          list_element_t curr;
          list_element_t head;
          list_element_t tail;

          rc = list_get_curr_(list, &curr);
          if(rc == EGAOK)
            {
              rc = list_get_head_(list, &head);
            }
          if (rc == EGAOK)
            {
              rc = list_get_tail_(list, &tail);
            }
          if (rc == EGAOK)
            {
              rc = list_get_curr_(list, &curr);
            }
          if (rc == EGAOK)
            {
              if (curr == NULL || size == 0x0)
                {
                  *whence = POS_NONE;
                }
              else if (curr == head)
                {
                  *whence = POS_HEAD;
                }
              else if (curr == tail)
                {
                  *whence = POS_TAIL;
                }
              else
                {
                  *whence = POS_MID;
                }
            }
        }
    }
  return rc;
}
