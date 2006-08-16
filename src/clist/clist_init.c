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

 Description: Allocates and initializes the circular list

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_init.c,v 1.8 2006-08-16 10:17:18 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdlib.h>
#include "list.h"
#include "clist.h"
#include "clist_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist_init.c,v 1.8 2006-08-16 10:17:18 harq_al_ada Exp $";

GAERROR
clist_init (clist_t * clist, deallocator_t * dealloc)
{
  GAERROR rc = EGAOK;

  assert (clist != NULL);
  assert (dealloc != NULL);
  if (clist == NULL)
    {
      rc = EGAINVAL;
    }
  else if ((*clist = (clist_t) malloc (sizeof (struct clist_t))) == NULL)
    {
      rc = EGANOMEM;
    }
  else
    {
      list_t list;

      if ((rc = clist_set_signature_ (*clist)) == EGAOK)
        {
          if ((rc = list_init (&list, dealloc)) == EGAOK)
            {
              rc = clist_set_list_ (*clist, list);
            }
        }
      if (rc != EGAOK)
        {
          if ((rc = clist_get_list_ (*clist, &list)) == EGAOK)
            {
              rc = list_destroy (list);
            }
          memset (*clist, 0x0, sizeof(struct clist_t));
          free (*clist);
        }
    }
  return rc;
}
