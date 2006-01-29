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

 Description: Finishes a list. This routine will delete the whole list
 from memory

 CVS Information
 $Author: harq_al_ada $
 $Id: dlist_destroy.c,v 1.7 2006-01-29 19:24:13 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"
#include "dlist_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist_destroy.c,v 1.7 2006-01-29 19:24:13 harq_al_ada Exp $";

int
dlist_destroy (dlist_t list)
{
  int rc = 0x0;
  assert (list != NULL);
  if (list == NULL)
    {
      rc = EGAINVAL;
    }
  else 
    {
      CHECK_SIGNATURE (list, GA_DLIST_SIGNATURE);
  
      /* Proceeds with the deletion - Deletes the list from the head, always */
      while ((rc = dlist_del (list, NULL, POS_HEAD)) == 0x0)
        ;
      /* EOF is not an error. Resets rc if it is EOF */
      if (rc == EOF)
        {
          rc = 0x0;
        }
      free (list);
    }
  
  return rc;
}
