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
 $Id: list.c,v 1.5 2004-10-05 10:29:29 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "list.h"

/*
 * Local prototypes
 */
static int
  load_list(list_t * list, size_t elements);
static int
  check_contents(list_t * list, size_t elements);
static int
  check_deletion(list_t * list, size_t elements);

int
test_list(void)
{
  list_t *list;			/* List descriptor */
  int *item;			/* Item to load into the list */
  int rc;			/* Error handling variable */
  unsigned int errors;		/* Errors found so far */
  register int i;		/* General purpose iterator */

  /* Initializations */
  errors = 0x0U;
  /* Allocates the list. We are using the free as the deallocator since this
     test will involve only simple allocated data */
  errno = 0;
  rc = list_alloc(&list, free);
  if (errno)
  {
    printf("[LIST TEST] Error allocating list\n");
    ++errors;
    list = (list_t *) NULL;
  }
  if (!rc)
  {
    /* Performs the load test */
    errors += load_list(list, MAX_ELEMENTS);
    /* Performs the navigation test */
    errors += check_contents(list, MAX_ELEMENTS);
    /* Performs the deletion test */
    errors += check_deletion(list, MAX_ELEMENTS);
  }
  /* Frees the list only if it was already allocated */
  if (list)
  {
    errno = 0;
    rc = list_free(&list);
    if (errno)
    {
      printf("[LIST TEST] Could not free the list\n");
      ++errors;
    }
  }
  return errors;
}

/*
 * Loads data into the list
 */
static int
load_list(list_t * list, size_t elements)
{
  int errors;			/* Errors counter */
  register int i;		/* General purpose iterator */

  /* Initializations */
  errors = 0x0;

  /* Loads the list */
  for (i = 0x0; (i < elements); ++i)
  {
    int *item;			/* Item to insert */

    /* Allocates memory for a single item */
    item = (int *)malloc(sizeof(int));
    if (!item)
    {
      printf("[LIST TEST] Could not allocate memory" \
	     " for an item\n");
      ++errors;
      break;
    }
    /* Builds the item data */
    *item = i + 1;
    /* Inserts the item in the list */
    errno = 0;
    list_insert(list, item);
    if (errno)
    {
      printf("[LIST TEST] Error inserting into " \
	     "the list\n");
      ++errors;
    }
  }
  return errors;
}

/*
 * Check lists contents
 */
static int
check_contents(list_t * list, size_t elements)
{
  int errors;			/* Error counter */
  int *item;			/* Item to grab from the list */
  int rc;			/* General error checking variable */
  register int i;		/* General iterator */

  /* Initializations */
  errors = 0x0;
  rc = 0x0;

  /* Gets the data from the list, iterating it and checking the contents */
  errno = 0;
  list_move(list, HEAD);
  if (errno)
  {
    printf("[LIST TEST] Error moving the list\n");
    ++errors;
    rc = -1;
  }
  i = 0x0;
  while (!rc)
  {
    /* Gets the current item of the list and goes to the next */
    errno = 0;
    rc = list_get(list, (void **)&item, NEXT);
    if (errno)
    {
      printf("[LIST TEST] Could not get the list " \
	     "item\n");
      ++errors;
    }
    if (rc)
    {
      /* EOF */
      break;
    }
    if (*item != (i + 1))
    {
      printf("[LIST TEST] Data mismatch: i=%d, item=%d\n",
	     i, *item);
      ++errors;
    }
    ++i;
  }
  if (i != elements)
  {
    printf("[LIST TEST] Number of elements mismatch\n");
    ++errors;
  }
  return errors;
}

/*
 * Checks the deletion of items of the list
 */
static int
check_deletion(list_t * list, size_t elements)
{
  int errors;			/* Error counter */
  int deleted;			/* Number of elements deleted */
  int *item;			/* Item deleted from the list */
  register int i;		/* A simple iterator */

  /* Initializations */
  errors = 0x0;
  deleted = 0x0;
  i = 0x0;

  /* Deletes the head of the list */
  list_move(list, HEAD);
  list_del(list, (void **)&item);
  free(item);
  ++deleted;
  /* Moves to somewhere in the middle of the list */
  for (i = 0; i < elements / 2; ++i)
  {
    list_move(list, NEXT);
  }
  /* Deletes an item at somewhere in the middle of the list */
  list_del(list, (void **)&item);
  free(item);
  ++deleted;
  /* Deletes the tail of the list */
  list_move(list, TAIL);
  if (!list_del(list, (void **)NULL))
  {
    /* The tail was deleted. This is a serious bug, since it is not possible
       to delete the tail of a single linked list */
    ++errors;
    printf("[LIST TEST] The tail was deleted. It is a serious bug\n");
  }
  /* Check for inconsistencies */
  if (elements - deleted != descriptor_size(list))
  {
    printf("[LIST TEST] Number of elements mismatch for deletion\n");
    ++errors;
  }
  return errors;
}
