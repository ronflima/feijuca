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

 Description: Test suite routines for deques.

 CVS Information
 $Author: daniel_csoares $
 $Id: deque.c,v 1.3 2005-08-23 13:00:53 daniel_csoares Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "gacommon.h"
#include "deque.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: deque.c,v 1.3 2005-08-23 13:00:53 daniel_csoares Exp $";

/*
 * Local macros
 */
#define TEST "DEQUE"

/*
 * Local prototypes
 */
static int check_deque_push (deque_t *, size_t, position_t);
static int check_deque_pop (deque_t *, size_t, position_t);

/*
 * Exported functions
 */
int
test_deque (size_t maxelements)
{
  deque_t deque;		/* Deque descriptor */
  int rc;			/* General error handle variable */

  /* Check the deque allocation */
  rc = deque_init (&deque, free);
  if (rc)
    {
      ERROR (TEST, "deque_alloc", rc);
      return EFAILED;
    }

  /* Loads data into the deque */
  rc = check_deque_push (&deque, maxelements,POS_HEAD);
  if (rc)
    {
      ERROR (TEST, "check_push_head", rc);
      return EFAILED;
    }

  /* Checks the pop of data from the deque */
  rc = check_deque_pop (&deque, maxelements,POS_TAIL);
  if (rc)
    {
      ERROR (TEST, "check_pop_head", rc);
      return EFAILED;
    }

  /* Loads data into the deque */
  rc = check_deque_push (&deque, maxelements,POS_TAIL);
  if (rc)
  {
      ERROR (TEST, "check_push_tail", rc);
      return EFAILED;
  }

  /* Checks the pop of data from the deque */
  rc = check_deque_pop (&deque, maxelements,POS_HEAD);
  if (rc)
  {
      ERROR (TEST, "check_pop_tail", rc);
      return EFAILED;
  }
  
  /* Frees the deque */
  rc = deque_destroy (&deque);
  if (rc)
    {
      ERROR (TEST, "deque_free", rc);
      return EFAILED;
    }

  return 0x0;
}

/* Loads data into the circular list */
static int
check_deque_push (deque_t * deque, size_t elements, position_t whence)
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
      /* Inserts the item in the list */
      rc = deque_push (deque, item, whence);
      if (rc)
        {
          ERROR (TEST, "deque_push", rc);
          test_status = EFAILED;
          break;
        }
    }

  return test_status;
}

/* Checks the pop of data from the deque */
static int
check_deque_pop (deque_t * deque, size_t elements, position_t whence)
{
  register int i;		/* General iterator */

  for (i = 0; i < elements; ++i)
    {
      int *buffer;		/* Buffer to hold popped data from the deque */
      int rc;			/* General error handling variable */

      /* Pops data from the deque */
      rc = deque_pop (deque, (void **) &buffer, whence);
      if (rc)
        {
          ERROR (TEST, "deque_pop", rc);
          return EFAILED;
        }
      /* Checks popped data */
      if (!buffer)
        {
          ERROR (TEST, "Null popped data found", ECKFAIL);
          return EFAILED;
        }
      if (*buffer != i + 1)
        {
          ERROR (TEST, "Popped data mismatch", ECKFAIL);
          return EFAILED;
        }
      /* Frees popped data */
      free ((void *) buffer);
    }
  return 0x0;

}
