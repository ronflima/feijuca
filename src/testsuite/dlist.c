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

 Description: Test suite routines for lists. This test suite is also an
              example on how to use the lists routines

 CVS Information
 $Author: ron_lima $
 $Id: dlist.c,v 1.11 2005-02-07 21:45:09 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "dlist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist.c,v 1.11 2005-02-07 21:45:09 ron_lima Exp $";

/*
 * Local macros
 */
#define TEST "DLIST"

/*
 * Local prototypes
 */
static int load_list (dlist_t *, size_t);
static int check_contents (dlist_t *, size_t);
static int check_deletion (dlist_t *, size_t);

int
test_dlist (size_t maxelements)
{
  dlist_t *list;		/* List descriptor */
  int rc;			/* Error handling variable */
  int test_status;		/* Test status variable */

  /* Initializations */
  test_status = 0x0;

  /* Allocates the list. We are using the free as the deallocator since this
     test will involve only simple allocated data */
  rc = dlist_alloc (&list, free);
  if (rc)
    {
      ERROR (TEST, "dlist_alloc", rc);
      test_status = EFAILED;
    }
  else
    {
      /* Performs the load test */
      rc = load_list (list, maxelements);
      if (!rc)
        {
          /* Performs the navigation test */
          rc = check_contents (list, maxelements);
          if (rc)
            {
              ERROR (TEST, "check_contents", rc);
              test_status = EFAILED;
            }
          /* Performs the deletion test */
          rc = check_deletion (list, maxelements);
          if (rc)
            {
              ERROR (TEST, "check_deletion", rc);
              test_status = EFAILED;
            }
        }
      else
        {
          ERROR (TEST, "dload_list", rc);
          test_status = EFAILED;
        }

      /* Frees the list only if it was already allocated */
      rc = dlist_free (&list);
      if (rc)
        {
          ERROR (TEST, "dlist_free", rc);
          test_status = EFAILED;
        }
    }

  return test_status;
}

/*
 * Loads data into the list
 */
static int
load_list (dlist_t * list, size_t elements)
{
  register int i;		/* General purpose iterator */

  /* Loads the list */
  for (i = 0x0; (i < elements); ++i)
    {
      int *item;		/* Item to insert */
      int rc;			/* General purpose error handling variable */

      /* Allocates memory for a single item */
      item = (int *) malloc (sizeof (int));
      if (!item)
        {
          ERROR (TEST, "malloc", ECKFAIL);
          return ENOMEM;
        }
      /* Builds the item data */
      *item = i + 1;

      /* Inserts the item in the list */
      rc = dlist_insert (list, item, POS_TAIL);
      if (rc)
        {
          ERROR (TEST, "dlist_insert", rc);
          return EFAILED;
        }
    }
  return 0x0;
}

/*
 * Check lists contents
 */
static int
check_contents (dlist_t * list, size_t elements)
{
  int *item;			/* Item to grab from the list */
  int rc;			/* General error checking variable */
  register int i;		/* General iterator */

  /* Gets the data from the list, iterating it and checking the contents */
  rc = dlist_move (list, POS_HEAD);
  if (rc)
    {
      ERROR (TEST, "dlist_move", rc);
      return EFAILED;
    }
  i = 0x0;
  while (!rc)
    {
      /* Gets the current item of the list and goes to the next */
      rc = dlist_get (list, (void **) &item, POS_NEXT);
      if (rc > 0x0)
        {
          ERROR (TEST, "dlist_get", rc);
          return EFAILED;
        }
      if (rc < 0x0)
        {
          /* EOF */
          break;
        }
      if (*item != (i + 1))
        {
          ERROR (TEST, "Data mismatch", ECKFAIL);
          return EFAILED;
        }
      ++i;
    }
  if (i != elements)
    {
      ERROR (TEST, "Number of elements mismatch", ECKFAIL);
      return EFAILED;
    }
  return 0x0;
}

/*
 * Checks the deletion of items of the list
 */
static int
check_deletion (dlist_t * list, size_t elements)
{
  int deleted;			/* Number of elements deleted */
  int *item;			/* Item deleted from the list */
  int rc;			/* General error handling variable */
  register int i;		/* A simple iterator */

  /* Initializations */
  deleted = 0x0;
  i = 0x0;

  /* Deletes the head of the list */
  rc = dlist_move (list, POS_HEAD);
  if (rc)
    {
      ERROR (TEST, "dlist_move", rc);
      return EFAILED;
    }
  rc = dlist_del (list, (void **) &item, POS_CURR);
  if (rc)
    {
      ERROR (TEST, "dlist_del", rc);
      return EFAILED;
    }
  ++deleted;
  /* Moves to the head of the list */
  rc = dlist_move (list, POS_HEAD);
  if (rc)
    {
      ERROR (TEST, "dlist_move", rc);
      return EFAILED;
    }
  /* Moves to somewhere in the middle of the list */
  for (i = 0; i < elements / 2; ++i)
    {
      rc = dlist_move (list, POS_NEXT);
      if (rc)
        {
          ERROR (TEST, "dlist_move", rc);
          return EFAILED;
        }
    }
  /* Deletes an item at somewhere in the middle of the list */
  rc = dlist_del (list, (void **) &item, POS_NEXT);
  if (rc)
    {
      ERROR (TEST, "dlist_del", rc);
      return EFAILED;
    }
  ++deleted;
  /* Deletes the tail of the list */
  rc = dlist_move (list, POS_TAIL);
  if (rc)
    {
      ERROR (TEST, "dlist_move", rc);
      return EFAILED;
    }
  rc = dlist_del (list, (void **) NULL, POS_CURR);
  if (rc)
    {
      ERROR (TEST, "dlist_del", rc);
      return EFAILED;
    }
  ++deleted;
  /* Check for inconsistencies */
  if (elements - deleted != descriptor_size (list))
    {
      ERROR (TEST, "Number of elements mismatch for deletion", ECKFAIL);
      return EFAILED;
    }
  return 0x0;
}
