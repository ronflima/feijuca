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

 Description: Test suite routines for stacks. This test suite is also an
              example on how to use the stacks routines

 CVS Information
 $Author: harq_al_ada $
 $Id: stack.c,v 1.13 2006-01-29 12:37:05 harq_al_ada Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include "gatests.h"
#include "stack.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: stack.c,v 1.13 2006-01-29 12:37:05 harq_al_ada Exp $";

/*
 * Local macros
 */
#define TEST "STACK"

/*
 * Local prototypes
 */
static int load_stack (stack_t, size_t);
static int test_stack_push (size_t);
static int test_stack_pop (size_t);


/*
 * Exported function definitions
 */
int
test_stack (size_t maxelements)
{
  scenario_t scenarios [] = {
    {"Stack push test", test_stack_push},
    {"Stack pop test" , test_stack_pop }
  };

  return execute_scenarios (TEST, maxelements, scenarios, sizeof (scenarios));
}

/*
 * Local function definitions
 */

/*
 * Utility function: Loads data into the stack
 */
static int
load_stack (stack_t stack, size_t nelements)
{
  register size_t i;
  for (i=0x0; i<nelements; ++i)
    {
      int *data;
      int rc;

      data = (int *) malloc (sizeof (int));
      if (data == NULL)
        {
          ERROR (TEST, "Available memory exhausted", ECKFAIL);
          return ECKFAIL;
        }
      *data = i;
      if ((rc = stack_push (stack, (const void *) data)) != 0x0)
        {
          ERROR (TEST, "stack_push", rc);
          return ECKFAIL;
        }
    }
  return 0x0;
}

/* 
 * Scenario 1: Loads data into the stack 
 */
static int
test_stack_push (size_t nitems)
{
  register int i; 
  stack_t stack;
  int rc;
  int test_status;

  test_status = 0x0;

  if ((rc = stack_init (&stack, free))!= 0x0)
    {
      ERROR (TEST, "stack_init", rc);
      return EFAILED;
    }
  if ((rc = load_stack (stack, nitems)) != 0x0)
    {
      ERROR (TEST,"Stack load procedure", rc);
      test_status = EFAILED;
    }
  if ((rc = stack_destroy (stack)) != 0x0)
    {
      ERROR (TEST, "stack_destroy", rc);
      test_status = EFAILED;
    }

  return test_status;
}

/* 
 * Scenario 2: Pops data from the stack and check the contents
 */
static int
test_stack_pop (size_t nitems)
{
  stack_t stack;
  int test_status;
  int rc;

  test_status = 0x0;

  if ((rc = stack_init (&stack, free))!= 0x0)
    {
      ERROR (TEST, "stack_init", rc);
      return EFAILED;
    }
  if ((rc = load_stack (stack, nitems)) != 0x0)
    {
      ERROR (TEST,"Stack load procedure", rc);
      test_status = EFAILED;
    }
  else
    {
      int * data;
      size_t pushed_elements;

      pushed_elements = 0x0ul;
      while ((rc = stack_pop (stack, (void **)&data)) == 0x0)
        {
          pushed_elements++;
        }
      if (rc != EOF)
        {
          ERROR (TEST, "stack_push", rc);
          test_status = EFAILED;
        }
      else if (pushed_elements != nitems)
        {
          ERROR (TEST, "Pushed elements mismatch", rc);
          test_status = EFAILED;
        }
    }
  if ((rc = stack_destroy (stack)) != 0x0)
    {
      ERROR (TEST, "stack_destroy", rc);
      test_status = EFAILED;
    }

  return test_status;
}
