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
 $Id: list.c,v 1.7 2005-01-08 23:25:56 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "list.h"

/*
 * Local macros
 */
#define TEST "LIST"

/*
 * Local prototypes
 */
static int
  load_list (list_t * list, size_t elements);
static int
  check_contents (list_t * list, size_t elements);
static int
  check_deletion (list_t * list, size_t elements);

int
test_list (void)
{
  list_t *list;			/* List descriptor */
  int rc;			/* Error handling variable */
  int test_status;              /* Test status control variable  */

  /* Initializations */
  test_status = 0x0;

  /* Allocates the list. We are using the free as the deallocator
     since this test will involve only simple allocated data */
  rc = list_alloc (&list, free);
  if (rc)
  {
    ERROR (TEST, "list_alloc", rc);
    return EFAILED;
  }
  /* Performs the load test */
  rc = load_list (list, MAX_ELEMENTS);
  if (! rc)
  {
    /* Performs the navigation test */
    rc = check_contents (list, MAX_ELEMENTS);
    if (rc)
    {
      ERROR (TEST, "check_contents", rc);
      test_status = EFAILED;
    }
    /* Performs the deletion test */
    rc = check_deletion (list, MAX_ELEMENTS);
    if (rc)
    {
      ERROR (TEST, "check_deletion", rc);
      test_status = EFAILED;
    }
  }
  else
  {
    ERROR (TEST, "load_list", rc);
    test_status = EFAILED;
  }
  /* Frees the list only if it was already allocated */
  rc = list_free (&list);
  if (rc)
  {
    ERROR (TEST, "list_free", rc);
    test_status = EFAILED;
  }
  
  return test_status;
}

/*
 * Loads data into the list
 */
static int
load_list (list_t * list, size_t elements)
{
  register int i;		/* General purpose iterator */
  int test_status;              /* Test status variable  */
  int rc;                       /* General purpose error handling variable */

  /* Initializations */
  test_status = 0x0;

  /* Loads the list */
  for (i = 0x0; (i < elements); ++i)
  {
    int *item;			/* Item to insert */

    /* Allocates memory for a single item */
    item = (int *)malloc (sizeof (int));
    if (!item)
    {
      ERROR (TEST, "malloc", 0);
      test_status = ENOMEM;
      break;
    }
    /* Builds the item data */
    *item = i + 1;
    /* Inserts the item in the list */
    rc = list_insert (list, item);
    if (rc)
    {
      ERROR (TEST, "list_insert", rc);
      test_status = EFAILED;
      break;
    }
  }
  
  return test_status;
}

/*
 * Check list contents
 */
static int
check_contents (list_t * list, size_t elements)
{
  int *item;			/* Item to grab from the list */
  int rc;			/* General error checking variable */
  int test_status;              /* Test status */
  register int i;		/* General iterator */

  /* Initializations */
  test_status = 0x0;
  i = 0x0;
  
  /* Gets the data from the list, iterating it and checking the contents */
  rc = list_move (list, HEAD);
  if (rc)
  {
    ERROR (TEST, "list_move", rc);
    test_status = EFAILED;
  }
  while (! rc)
  {
    /* Gets the current item of the list and goes to the next */
    rc = list_get (list, (void **)&item, NEXT);
    if (rc  > 0x0)
    {
      ERROR (TEST, "list_get", rc);
      test_status = EFAILED;
    }
    if (rc == EOF)
    {
      /* EOF */
      break;
    }
    if (*item != (i + 1))
    {
      printf ("[LIST TEST] Data mismatch: i=%d, item=%d\n",
          i, *item);
      test_status = EFAILED;
      break;
    }
    ++i;
  }
  if (i != elements)
  {
    printf ("[LIST TEST] Number of elements mismatch: %d != %d\n", i,
            elements);
    test_status = EFAILED;
  }
  return test_status;
}

/*
 * Checks the deletion of items of the list in different positions
 */
static int
check_deletion (list_t * list, size_t elements)
{
  int deleted;			/* Number of elements deleted */
  int *item;			/* Item deleted from the list */
  int rc;                       /* General purpose error handling variable */
  register int i;		/* A simple iterator */

  /* Initializations */
  deleted = 0x0;
  i = 0x0;

  /* Deletes the head of the list */
  rc = list_move (list, HEAD);
  if (rc)
  {
    ERROR (TEST, "list_move", rc);
    return EFAILED;
  }
  rc = list_del (list, (void **)&item);
  if (rc)
  {
    ERROR (TEST, "list_del", rc);
    return EFAILED;
  }
  free (item);
  ++deleted;
  /* Moves to somewhere in the middle of the list */
  for (i = 0; i < elements / 2; ++i)
  {
    rc = list_move (list, NEXT);
    if (rc)
    {
      ERROR (TEST, "list_move", rc);
      return EFAILED;
    }
  }
  /* Deletes an item at somewhere in the middle of the list */
  rc = list_del (list, (void **)&item);
  if (rc)
  {
    ERROR (TEST, "list_del", rc);
    return EFAILED;
  }
  free (item);
  ++deleted;
  /* Deletes the tail of the list */
  rc = list_move (list, TAIL);
  if (rc)
  {
    ERROR (TEST, "list_move", rc);
    return EFAILED;
  }

  /* Try to get the tail out */
  rc = list_del (list, (void **)NULL);
  if (! rc)
  {
    /* The tail was deleted. This is a serious bug, since it is not possible
       to delete the tail of a single linked list */
    ERROR (TEST, "list_del - tail deletion", rc);
    return EFAILED;
  }
  /* Check for inconsistencies */
  if (elements - deleted != descriptor_size (list))
  {
    printf ("[LIST TEST] Number of elements mismatch for deletion\n");
    return EFAILED;
  }
  
  return 0x0;
}
