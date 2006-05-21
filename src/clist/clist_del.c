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
 $Id: clist_del.c,v 1.14 2006-05-21 23:15:18 harq_al_ada Exp $
*/
#include <stdio.h>
#include <assert.h>
#include "clist.h"
#include "clist_.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_del.c,v 1.14 2006-05-21 23:15:18 harq_al_ada Exp $";

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
              if ((rc = list_del (clist->list_, data, whence)) == 0x0)
                {
                  rc = rebuild_circular_condition_ (clist, whence);
                }
            }
        }
    }
  return rc;
}

/* Internal function. Evaluates the inner linked list in order to make
 * it circular again. */
static GAERROR
rebuild_circular_condition_ (clist_t clist, position_t whence)
{
  size_t size;
  GAERROR rc = EGAOK;

  if ((rc = clist_get_size (clist, &size)) == 0x0)
    {
      if (size != 0x0)
        {
          list_t list = clist->list_;
          
          if (whence == POS_HEAD)
            {
              if (list->tail_->next_ != list->head_)
                {
                  list->tail_->next_ = list->head_;
                }
            }
          else if (whence == POS_NEXT)
            {
              if (list->tail_->next_ == NULL)
                {
                  list->tail_->next_ = list->head_;
                }
              else if (list->tail_->next_ != list->head_)
                {
                  list->head_ = list->tail_->next_;
                }
            }
        }
    }
  return rc;
}
