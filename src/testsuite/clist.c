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

 Description: Test suite routines for circular lists. This test suite is also
              an example on how to use the lists routines

 CVS Information
 $Author: ron_lima $
 $Id: clist.c,v 1.3 2005-01-16 11:47:14 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "clist.h"

/*
 * Local macros
 */
#define TEST "CLIST"

/*
 * Local prototypes
 */
static int load_data (clist_t *, size_t);
static int check_navigation (clist_t *);
static int check_deletion (clist_t *);

/*
 * Exported functions
 */
int
test_clist (void)
{
  clist_t *clist;		/* Circular list descriptor */
  int rc;			/* General error handle variable */

  /* Check the list allocation */
  rc = clist_alloc (&clist, free);
  if (rc)
    {
      ERROR (TEST, "clist_alloc", rc);
      return EFAILED;
    }

  /* Loads data into the list */
  rc = load_data (clist, MAX_ELEMENTS);
  if (rc)
    {
      ERROR (TEST, "load_clist", rc);
      return EFAILED;
    }

  /* Checks the navigation and data retrieval from the list */
  rc = check_navigation (clist);
  if (rc)
    {
      ERROR (TEST, "check_navigation", rc);
      return EFAILED;
    }

  /* Checks the deletion of elements */
  rc = check_deletion (clist);
  if (rc)
    {
      ERROR (TEST, "check_deletion", rc);
      return EFAILED;
    }

  /* Frees the list */
  rc = clist_free (&clist);
  if (rc)
    {
      ERROR (TEST, "clist_free", rc);
      return EFAILED;
    }

  return 0x0;
}

/* Loads data into the circular list */
static int
load_data (clist_t * clist, size_t elements)
{
  register int i;		/* General purpose iterator */
  int test_status;		/* Test status variable  */
  int rc;			/* General purpose error handling variable */

  /* Initializations */
  test_status = 0x0;

  /* Loads the list */
  for (i = 0x0; (i < elements); ++i)
    {
      int *item;		/* Item to insert */

      /* Allocates memory for a single item */
      item = (int *) malloc (sizeof (int));
      if (!item)
        {
          ERROR (TEST, "malloc", 0);
          test_status = ENOMEM;
          break;
        }
      /* Builds the item data */
      *item = i + 1;
      /* Inserts the item in the list */
      rc = clist_insert (clist, item);
      if (rc)
        {
          ERROR (TEST, "clist_insert", rc);
          test_status = EFAILED;
          break;
        }
    }

  return test_status;
}

/* Checks the navigation and data retrieval from the list */
static int
check_navigation (clist_t * clist)
{
  int rc;			/* General error handling variable */
  register int i;		/* General purpose iterator */
  register int j;		/* General purpose iterator */

  /* Try to go to the first element of the list */
  rc = clist_move (clist, HEAD);
  if (rc)
    {
      ERROR (TEST, "clist_move", rc);
      return EFAILED;
    }

  /* Try to go to the last element of the list */
  rc = clist_move (clist, TAIL);
  if (rc)
    {
      ERROR (TEST, "clist_move", rc);
      return EFAILED;
    }

  /* Runs the list 3 times to check the circularity */
  for (i = 0x0; i < descriptor_size (clist) * 3; ++i)
    {
      rc = clist_move (clist, NEXT);
      if (rc)
        {
          ERROR (TEST, "clist_move", rc);
          return EFAILED;
        }
    }

  /* Moves to the beginning of the list again */
  rc = clist_move (clist, HEAD);
  if (rc)
    {
      ERROR (TEST, "clist_move", rc);
      return EFAILED;
    }

  /* Executes a loop for 3 times again, but now getting data */
  for (j = 0x0; j < 3; ++j)
    {
      for (i = 0x0; i < descriptor_size (clist); ++i)
        {
          int *buffer;		/* Buffer data  */

          rc = clist_get (clist, (void *) &buffer, NEXT);
          if (rc)
            {
              ERROR (TEST, "clist_move", rc);
              return EFAILED;
            }
          if (*buffer != i + 1)
            {
              ERROR (TEST, "Data mismatch in clist_get", ECKFAIL);
              return EFAILED;
            }
        }
    }

  return 0x0;
}

/* Checks deletion */
static int
check_deletion (clist_t * clist)
{
  int rc;			/* General purpose error handling variable */
  int *buffer;			/* Buffer to save data */

  /* Goes to the beginning of the list */
  rc = clist_move (clist, HEAD);
  if (rc)
    {
      ERROR (TEST, "clist_move", rc);
      return EFAILED;
    }

  /* Deletes the HEAD of the list */
  rc = clist_del (clist, NULL);
  if (rc)
    {
      ERROR (TEST, "clist_del", rc);
      return EFAILED;
    }

  /* Move to the tail */
  rc = clist_move (clist, TAIL);
  if (rc)
    {
      ERROR (TEST, "clist_move", rc);
      return EFAILED;
    }

  /* Deletes the TAIL of the list */
  rc = clist_del (clist, (void **) &buffer);
  if (rc)
    {
      ERROR (TEST, "clist_del", rc);
      return EFAILED;
    }

  /* Frees the buffer */
  free (buffer);

  return 0x0;
}
