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
 $Id: stack.c,v 1.6 2005-01-16 11:47:14 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include "gatests.h"
#include "stack.h"

/*
 * Local macros
 */
#define TEST "STACK"

/*
 * Local prototypes
 */
static int test_stack_push (stack_t *, size_t);
static int test_stack_pop (stack_t *, size_t);

/*
 * Exported function definitions
 */
int
test_stack (void)
{
  stack_t *stack;		/* Descriptor for stacks */
  int rc;			/* General return code for errors */
  int test_status;		/* Status of the test */

  /* Initializations */
  test_status = 0x0;

  /* Allocates memory for the stack - use the free function as deallocator */
  rc = stack_alloc (&stack, free);
  if (rc)
    {
      ERROR (TEST, "stack_alloc", rc);
      return EFAILED;
    }

  /* Test the stack normal operations */
  /* Push stuff to the stack */
  rc = test_stack_push (stack, MAX_ELEMENTS);
  if (!rc)
    {
      /* Pop stuff from the stack */
      rc = test_stack_pop (stack, MAX_ELEMENTS);
      if (rc)
        {
          /* Pop test has failed */
          ERROR (TEST, "Stack POP operation", rc);
          test_status = EFAILED;
        }
    }
  else
    {
      /* The push into the stack has failed */
      ERROR (TEST, "Stack push operation", rc);
      test_status = EFAILED;
    }

  /* Frees the entire stack */
  rc = stack_free (&stack);
  if (rc)
    {
      ERROR (TEST, "stack_free", rc);
      test_status = EFAILED;
    }

  return test_status;
}

/*
 * Local function definitions
 */

/* Loads data into the stack */
static int
test_stack_push (stack_t * stack, size_t nitems)
{
  register int i;		/* General iterator */

  /* Pushes stuff to the stack */
  for (i = 0; i < nitems; ++i)
    {
      int *data;		/* Data to push into the stack */
      int rc;			/* General error handling variable */

      data = (int *) malloc (sizeof (int));

      if (data)
        {
          /* Puts some value inside the data pointer */
          *data = i;

          /* Pushes the data into the stack */
          rc = stack_push (stack, data);
          if (rc)
            {
              ERROR (TEST, "stack_push", rc);
              return rc;
            }
        }
    }

  return 0x0;
}

/* Pops data from the stack */
static int
test_stack_pop (stack_t * stack, size_t nitems)
{
  register int i;		/* General iterator */
  unsigned char loop;		/* Loop control variable */

  /* Initializations */
  i = 0x0;
  loop = '\x1';

  /* Gets all the pushed data from the stack */
  while (loop)
    {
      int *data;		/* Buffer to hold the created data */
      int rc;			/* General error handling variable */
      /* pops data from the stack */
      rc = stack_pop (stack, (void *) &data);
      switch (rc)
        {
        case 0x0:		/* Normal operation  */
          ++i;
          break;

        case EOF:		/* End of file - no more items to get */
          loop = '\x0';
          break;

        default:		/* Error situation  */
          ERROR (TEST, "stack_pop", rc);
          loop = '\x0';
          break;
        }
    }
  /* Check if everything was pushed from the stack */
  if (i != nitems)
    {
      /* Not everything was pushed from the stack */
      ERROR (TEST, "Number of elements mismatch in data retrieval", ECKFAIL);
      return EFAILED;
    }

  return 0x0;
}
