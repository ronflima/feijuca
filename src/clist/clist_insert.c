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

 Description: Inserts a new element in the list

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_insert.c,v 1.18 2006-10-12 16:40:16 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdlib.h>
#include "clist.h"
#include "clist_.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_insert.c,v 1.18 2006-10-12 16:40:16 harq_al_ada Exp $";

GAERROR
clist_insert (clist_t clist, const void *data, position_t whence)
{
  GAERROR rc = EGAOK;

  assert (clist != NULL);
  if (! clist_is_valid_ (clist))
    {
      rc = EGAINVAL;
    }
  else
    {
      list_t list;          /* Inner linked list */

      if ((rc = clist_get_list_ (clist, &list)) == EGAOK)
        {
          if ((rc = list_insert (list, data, whence)) == EGAOK)
            {
              list_element_t tail;
          
              if ((rc = list_get_tail_ (list, &tail)) == EGAOK)
                {
                  list_element_t head; /* Next element from tail */
              
                  /* Enforces the linking to the head, even if the
                   * head has not changed. */
                  if ((rc = list_get_head_ (list, &head)) == EGAOK)
                    {
                      rc = list_element_set_next_ (tail, head);
                    }
                }
            }
        }
    }
  return rc;
}
