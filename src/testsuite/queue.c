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

 Description: Test suite routines for queues.

 CVS Information
 $Author: harq_al_ada $
 $Id: queue.c,v 1.11 2006-01-11 10:21:39 harq_al_ada Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "queue.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: queue.c,v 1.11 2006-01-11 10:21:39 harq_al_ada Exp $";

/*
 * Local macros
 */
#define TEST "QUEUE"

/*
 * Local prototypes
 */
static int load_queue (queue_t *, size_t);
static int test_queue_push (size_t);
static int test_queue_pop  (size_t);

/*
 * Exported functions
 */
int
test_queue (size_t maxelements)
{
  scenario_t scenarios [] = {
    {"Queue push test", test_queue_push},
    {"Queue pop test" , test_queue_pop }
  };

  return execute_scenarios (TEST, maxelements, scenarios, sizeof (scenarios));
}

/*
 * Static functions implementations
 */

/* Utility function: Loads a queue */
static int 
load_queue (queue_t * queue, size_t maxelem)
{
  size_t i;
  for (i=0x0; i<maxelem; ++i)
    {
      int * data;
      int rc;
      
      data = (int *) malloc (sizeof (int));
      if (data == NULL)
        {
          ERROR (TEST, "Data allocation failed: no more memory", ENOMEM);
          return -1;
        }
      if (rc = (queue_push (queue, (const void *) data)) != 0x0)
        {
          ERROR (TEST, "Error pushing data into the queue", rc);
          return rc;
        }
    }
  return 0x0;
}

/* Test scenario 1: Tests queue push operations */
static int
test_queue_push (size_t maxelem)
{
  int rc;
  int test_result = 0x0;
  queue_t queue;
  size_t size;

  if ((rc = queue_init (&queue, free)) != 0x0)
    {
      ERROR (TEST, "queue_init", rc);
      return rc;
    }
  if ((rc = load_queue (&queue, maxelem)) != 0x0)
    {
      ERROR (TEST, "load_queue", rc);
      test_result = EFAILED;
    }
  if ((rc = queue_size (&queue, &size)) != 0x0)
    {
      ERROR (TEST, "queue_size", ECKFAIL);
      test_result = EFAILED;
    }
  if (size != maxelem)
    {
      ERROR (TEST, "# of queued elements mismatch", ECKFAIL);
      test_result = EFAILED;
    }
  if ((rc = queue_destroy (&queue)) != 0x0)
    {
      ERROR (TEST, "queue_destroy", rc);
      test_result = EFAILED;
    }
  return test_result;
}

/* Test scenario 2: Tests queue pop operations */
static int
test_queue_pop (size_t maxelem)
{
  int rc;
  int test_result = 0x0;
  queue_t queue;
  size_t i;

  if ((rc = queue_init (&queue, free)) != 0x0)
    {
      ERROR (TEST, "queue_init", rc);
      return rc;
    }
  if ((rc = load_queue (&queue, maxelem)) != 0x0)
    {
      ERROR (TEST, "load_queue", rc);
      test_result = EFAILED;
    }
  for (i=maxelem; (i>0x0) && (test_result==0x0); --i)
    {
      int * data;
      if ((rc = queue_pop (&queue, (void **)&data)) > 0x0)
        {
          ERROR (TEST, "queue_pop", rc);
          test_result = EFAILED;
          break;
        }
      free (data);
    }
  if ((rc = queue_destroy (&queue)) != 0x0)
    {
      ERROR (TEST, "queue_destroy", rc);
      test_result = EFAILED;
    }
  return test_result;
}
