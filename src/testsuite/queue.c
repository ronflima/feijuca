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

 Description: Test suite routines for queues.

 CVS Information
 $Author: ron_lima $
 $Id: queue.c,v 1.2 2005-01-09 00:01:58 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "queue.h"

/*
 * Local macros
 */
#define TEST "QUEUE"

/*
 * Local prototypes
 */
#ifdef TODO
static int check_push (queue_t *, size_t);
static int check_pop (queue_t *);
#endif

/*
 * Exported functions
 */
int
test_queue (void)
{
  queue_t *queue;		/* Queue descriptor */
  int rc;			/* General error handle variable */

  return ENOTIMP;

#ifdef TODO
  /* Check the queue allocation */
  rc = queue_alloc (&queue, free);
  if (rc)
  {
    ERROR (TEST, "queue_alloc", rc);
    return EFAILED;
  }

  /* Loads data into the queue */
  rc = check_push (queue, MAX_ELEMENTS);
  if (rc)
  {
    ERROR (TEST, "check_push", rc);
    return EFAILED;
  }

  /* Checks the pop of data from the queue */
  rc = check_pop (queue);
  if (rc)
  {
    ERROR (TEST, "check_pop", rc);
    return EFAILED;
  }

  /* Frees the queue */
  rc = queue_free (&queue);
  if (rc)
  {
    ERROR (TEST, "queue_free", rc);
    return EFAILED;
  }

  return 0x0;
#endif
}

#ifdef TODO
/* Loads data into the circular list */
static int
check_push (queue_t * queue, size_t elements)
{
  register int i;		/* General purpose iterator */
  int test_status;		/* Test status variable  */
  int rc;			/* General purpose error handling variable */

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
      ERROR (TEST, "malloc", ECKFAIL);
      test_status = ENOMEM;
      break;
    }
    /* Builds the item data */
    *item = i + 1;
    /* Inserts the item in the list */
    rc = queue_push (queue, item);
    if (rc)
    {
      ERROR (TEST, "queue_push", rc);
      test_status = EFAILED;
      break;
    }
  }

  return test_status;
}

/* Checks the pop of data from the queue */
static int
check_pop (queue_t * queue)
{
  /* TODO */
  return ENOTIMP;
}

#endif
