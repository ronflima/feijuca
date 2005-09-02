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

 Description: Test suite routines for stacks. This test suite is also an
              example on how to use the stacks routines

 CVS Information
 $Author: ron_lima $
 $Id: stack.c,v 1.10 2005-09-02 10:36:42 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include "gatests.h"
#include "stack.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: stack.c,v 1.10 2005-09-02 10:36:42 ron_lima Exp $";

/*
 * Local macros
 */
#define TEST "STACK"

/*
 * Local prototypes
 */
static int test_stack_push (size_t);
static int test_stack_pop (size_t);

/*
 * Exported function definitions
 */
int
test_stack (size_t maxelements)
{
  int rc;
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
load_stack (stack_t * stack, size_t nelements)
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
  if ((rc = load_stack (&stack, nitems)) != 0x0)
    {
      ERROR (TEST,"Stack load procedure", rc);
      test_status = EFAILED;
    }
  if ((rc = stack_destroy (&stack)) != 0x0)
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
  if ((rc = load_stack (&stack, nitems)) != 0x0)
    {
      ERROR (TEST,"Stack load procedure", rc);
      test_status = EFAILED;
    }
  else
    {
      int * data;
      size_t pushed_elements;

      pushed_elements = 0x0ul;
      while ((rc = stack_pop (&stack, (void **)&data)) == 0x0)
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
  if ((rc = stack_destroy (&stack)) != 0x0)
    {
      ERROR (TEST, "stack_destroy", rc);
      test_status = EFAILED;
    }

  return test_status;
}
