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
 $Id: stack.c,v 1.2 2004-10-05 10:29:29 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "stack.h"

/*
 * Local prototypes
 */

int
test_stack(void)
{
  stack_t *stack;		/* Descriptor for stacks */
  int rc;			/* General return code for errors */
  int errors;			/* Counter for errors */
  register int i;		/* General iterator */

  /* Initializations */
  errors = 0x0;

  /* Allocates memory for the stack - use the free function as deallocator */
  rc = stack_alloc(&stack, free);
  if (rc)
  {
    ++errors;
    printf("STACK TEST: Could not allocate the stack\n");
    return errors;
  }

  /* Pushes stuff to the stack */
  for (i = 0; i < MAX_ELEMENTS; ++i)
  {
    int *data;			/* Data to push into the stack */

    data = (int *)malloc(sizeof(int));

    if (data)
    {
      /* Puts some value inside the data pointer */
      *data = i;
      /* Pushes the data into the stack */
      rc = stack_push(stack, data);
      if (rc)
      {
	++errors;
      }
    }
  }

  /* Gets all the pushed data from the stack */
  i = 0x0;
  while (1)
  {
    int *data;
    /* pops data from the stack */
    rc = stack_pop(stack, &data);
    if (!rc)
    {
      ++i;
    }
    else
    {
      break;
    }
  }
  if (i != MAX_ELEMENTS)
  {
    /* Not everything was pushed from the stack */
    ++errors;
  }
  /* Frees the entire stack */
  rc = stack_free(&stack);
  if (rc)
  {
    ++errors;
  }
  return errors;
}
