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

 Description: Deletes the next element pointed by element

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_del.c,v 1.17 2007-02-25 12:59:30 harq_al_ada Exp $
*/
#include <stdio.h>
#include <assert.h>
#include "clist.h"
#include "clist_.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_del.c,v 1.17 2007-02-25 12:59:30 harq_al_ada Exp $";

/*
 * Rebuilds the circular condition of the circular list. Since clist
 * uses list routines, the deletion may lead the list to become linear
 * again. Also, the list may become invalid, when the curr is pointing
 * to the tail and it is requested to delete the next
 * element. Therefore, it is necessary to rebuild the "circularity" of
 * the list.
 *
 * Parameters:
 * - clist - Circular list descriptor
 * - whence - Position where the deletion operation took place
 *
 * Returns:
 * - EGAEOF - Reached the end of the list
 * - EGAINVAL - invalid whence or the circular descriptor is invalid
 */
static GAERROR
rebuild_circular_condition_ __P((clist_t, position_t));

GAERROR
clist_del (clist_t clist, void **data, position_t whence)
{
  GAERROR rc = EGAOK;

  assert (clist != NULL);
  if (! clist_is_valid_(clist))
    {
      rc = EGAINVAL;
    }
  else 
    {
      size_t size;                  /* Size of the list */

      if ((rc = clist_get_size (clist, &size)) == EGAOK)
        {
          if (size == 0x0)
            {
              rc = EGAEOF;
            }
          else
            {
              list_t list;      /* Inner descriptor list */

              if ((rc = clist_get_list_ (clist, &list)) == EGAOK)
                {
                  if ((rc = list_del (list, data, whence)) == EGAOK)
                    {
                      rc = rebuild_circular_condition_ (clist, whence);
                    }
                }
            }
        }
    }
  return rc;
}

static GAERROR
rebuild_circular_condition_ (clist_t clist, position_t whence)
{
  size_t size;
  GAERROR rc = EGAOK;

  if ((rc = clist_get_size (clist, &size)) == EGAOK)
    {
      if (size != 0x0)
        {
          list_t list;

          if((rc = clist_get_list_ (clist, &list)) == EGAOK)
            {
              list_element_t tail; /* List tail */
              list_element_t head; /* List head */
              list_element_t next; /* Next element (from tail) */

              head=tail=next=NULL;
              rc = list_get_tail_(list, &tail);
              if (rc == EGAOK)
                {
                  rc = list_get_head_ (list, &head);
                }
              if (rc == EGAOK)
                {
                  rc = list_element_get_next_ (tail, &next);
                }
              if (whence == POS_HEAD)
                {
                  if (rc == EGAOK)
                    {
                      if (next != head)
                        {
                          /* Updates the tail->next pointer, making
                           * the list circular again. */
                          rc = list_element_set_next_ (tail, head);
                        }
                    }
                }
              else if (whence == POS_NEXT)
                {
                  if (next == NULL)
                    {
                      /* List became linear. Make it circular
                       * again. */
                      rc = list_element_set_next_ (tail, head);
                    }
                  else if (next != head)
                    {
                      /* Head became invalid. We need to set it to a
                       valid value. */
                      rc = list_set_head_(list, next);
                    }
                }
            }
        }
    }
  return rc;
}
