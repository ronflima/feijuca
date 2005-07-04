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
 $Id: list.c,v 1.16 2005-07-04 00:34:21 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list.c,v 1.16 2005-07-04 00:34:21 ron_lima Exp $";

/*
 * Local macros
 */
#define TEST "LIST"

/*
 * Local prototypes
 */
static int load_list (list_t *, size_t);
static int check_contents (list_t *, size_t);
static int check_deletion (list_t *, size_t);
static int check_reversal (list_t *);
static int check_uninitialization (list_t *);

int
test_list (size_t maxelements)
{
  list_t list;                  /* List descriptor */
  int rc;                       /* Error handling variable */
  int test_status;              /* Test status control variable  */

  /* Initializations */
  test_status = 0x0;

  /* Checks the list uninitialized */
  rc = check_uninitialization (&list);
  if (rc)
    {
      ERROR (TEST, "check_uninitialization", rc);
      return EFAILED;
    }
  /* Allocates the list. We are using the free as the deallocator since this
     test will involve only simple allocated data */
  rc = list_init (&list, free);
  if (rc)
    {
      ERROR (TEST, "list_init", rc);
      return EFAILED;
    }
  /* Performs the load test */
  rc = load_list (&list, maxelements);
  if (!rc)
    {
      /* Performs the navigation test */
      rc = check_contents (&list, maxelements);
      if (rc)
        {
          ERROR (TEST, "check_contents", rc);
          test_status = EFAILED;
        }
      /* Performs the reversal of the list */
      rc = check_reversal (&list);
      if (rc)
        {
          ERROR (TEST, "check_reversal", rc);
          test_status = EFAILED;
        }
      /* Performs the deletion test */
      rc = check_deletion (&list, maxelements);
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
  rc = list_destroy (&list);
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
          ERROR (TEST, "malloc", ECKFAIL);
          test_status = ENOMEM;
          break;
        }
      /* Builds the item data */
      *item = i + 1;
      /* Inserts the item into the list */
      rc = list_insert (list, item, POS_TAIL);
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
  int test_status;		/* Test status */
  register int i;		/* General iterator */

  /* Initializations */
  test_status = 0x0;
  i = 0x0;

  /* Gets the data from the list, iterating it and checking the contents */
  rc = list_move (list, POS_HEAD);
  if (rc)
    {
      ERROR (TEST, "list_move", rc);
      test_status = EFAILED;
    }
  while (!rc)
    {
      /* Gets the current item of the list and goes to the next */
      rc = list_get (list, (void **) &item, POS_NEXT);
      if (rc > 0x0)
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
          ERROR (TEST, "Data mismatch in data retrieval", ECKFAIL);
          test_status = EFAILED;
          break;
        }
      ++i;
    }
  if (i != elements)
    {
      ERROR (TEST, "Data number mismatch in data retrieval", ECKFAIL);
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
  int rc;			/* General purpose error handling variable */
  register int i;		/* A simple iterator */

  /* Initializations */
  deleted = 0x0;
  i = 0x0;

  /* Deletes the head of the list */
  rc = list_move (list, POS_HEAD);
  if (rc)
    {
      ERROR (TEST, "list_move", rc);
      return EFAILED;
    }
  rc = list_del (list, (void **) &item);
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
      rc = list_move (list, POS_NEXT);
      if (rc)
        {
          ERROR (TEST, "list_move", rc);
          return EFAILED;
        }
    }
  /* Deletes an item at somewhere in the middle of the list */
  rc = list_del (list, (void **) &item);
  if (rc)
    {
      ERROR (TEST, "list_del", rc);
      return EFAILED;
    }
  free (item);
  ++deleted;
  /* Deletes the tail of the list */
  rc = list_move (list, POS_TAIL);
  if (rc)
    {
      ERROR (TEST, "list_move", rc);
      return EFAILED;
    }

  /* Try to get the tail out */
  rc = list_del (list, (void **) NULL);
  if (!rc)
    {
      /* The tail was deleted. This is a serious bug, since it is not possible
         to delete the tail of a single linked list */
      ERROR (TEST, "list_del - tail deletion", rc);
      return EFAILED;
    }
  /* Check for inconsistencies */
  if (elements - deleted != descriptor_size (list))
    {
      ERROR (TEST, "Number of elements mismatch", ECKFAIL);
      return EFAILED;
    }

  return 0x0;
}

static int
check_reversal (list_t * list)
{
  int rc;                       /* General return code */
  int bigger;                   /* Bigger item */
  size_t curr_item;             /* Current item counter */

  /* Initializations */
  rc = 0x0;
  bigger = 0x0;
  curr_item = 0x0u;

  /* Reverses the list  */
  if (list_reverse (list))
    {
      ERROR (TEST, "Error reversing the list", ECKFAIL);
      return EFAILED;
    }
  /* Navigates the list to check the contents */
  list_move (list, POS_HEAD);
  while (! rc)
    {
      int * data;
      rc = list_get (list, (void **) &data, POS_NEXT);
      if (rc == 0)
        {
          if (bigger < *data)
            if (! curr_item)
              {
                bigger = *data;
              }
            else
              {
                ERROR (TEST, "List reversion failed. Wrong sequence.", 
                       ECKFAIL);
                return EFAILED;
              }
          ++curr_item;
        }
    }
  return 0x0;
}

static int 
check_uninitialization (list_t * list)
{
  int rc;
  void * buf = NULL;
  int test_status = 0x0;

  rc = list_insert (list, &buf, POS_HEAD);
  if (rc != EGAINVAL) 
    {
      ERROR (TEST, "list_insert", rc);
      test_status = EFAILED;
    }
  rc = list_get (list, &buf, POS_HEAD);
  if (rc != EGAINVAL) 
    {
      ERROR (TEST, "list_get", rc);
      test_status = EFAILED;
    }
  rc = list_move (list, POS_HEAD);
  if (rc != EGAINVAL) 
    {
      ERROR (TEST, "list_move", rc);
      test_status = EFAILED;
    }
  rc = list_del (list, &buf);
  if (rc != EGAINVAL) 
    {
      ERROR (TEST, "list_del", rc);
      test_status = EFAILED;
    }
  rc = list_reverse (list);
  if (rc != EGAINVAL) 
    {
      ERROR (TEST, "list_reverse", rc);
      test_status = EFAILED;
    }
  rc = list_destroy (list);
  if (rc != EGAINVAL) 
    {
      ERROR (TEST, "list_destroy", rc);
      test_status = EFAILED;
    }
  return test_status;
}
