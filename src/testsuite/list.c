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

 Description: Test suite routines for lists. This test suite is also an
              example on how to use the lists routines

 CVS Information
 $Author: harq_al_ada $
 $Id: list.c,v 1.25 2006-02-04 21:28:16 harq_al_ada Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list.c,v 1.25 2006-02-04 21:28:16 harq_al_ada Exp $";

/*
 * Local macros
 */
#define TEST "LIST"

/*
 * Local constants
 */
enum 
{
  PATTERN = 0xDEADBEEFu,        /* Pattern for content testing */
};

/*
 * Local prototypes
 */
static int load_list (list_t, size_t, unsigned char);
static int check_contents (size_t);
static int check_deletion (size_t);
static int check_reversal (size_t);

int
test_list (size_t maxelements)
{
  int rc = 0x0;
  register int i;
  scenario_t scenarios [] = {
    {"Contents checking", check_contents},
    {"Deletion checking", check_deletion},
    {"Reversal checking", check_reversal}
  };

  return execute_scenarios (TEST, maxelements, scenarios, sizeof (scenarios));
}

/*
 * Utility function: loads data into the list
 */
static int
load_list (list_t list, size_t elements, unsigned char use_pattern)
{
  register int i;		/* General purpose iterator */

  for (i = 0x0; i < elements; ++i)
    {
      unsigned int *item;       /* Item to insert */
      int rc;

      item = (int *) malloc (sizeof (unsigned int));
      if (item == NULL)
        {
          ERROR (TEST, "malloc", ECKFAIL);
          return ENOMEM;
        }
      if (use_pattern == '\x1')
        {
          *item = PATTERN;
        }
      else 
        {
          *item = i + 1;
        }
      if ((rc = list_insert (list, item, POS_TAIL)) != 0x0)
        {
          ERROR (TEST, "list_insert", rc);
          return EFAILED;
        }
    }

  return 0x0;
}

/*
 * Test scenario: Check list contents for consistency
 */
static int
check_contents (size_t elements)
{
  int *item;			/* Item to grab from the list */
  int rc;			/* General error checking variable */
  int test_status;		/* Test status */
  register int i;		/* General iterator */
  list_t list;

  test_status = 0x0;
  i = 0x0;

  if ((rc = list_init (&list, free)) != 0x0)
    {
      ERROR (TEST, "list_init", rc);
      return rc;
    }
  if ((rc = load_list (list, elements, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_list", rc);
      test_status = EFAILED;
    }
  else if ((rc = list_move (list, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "list_move", rc);
      test_status = EFAILED;
    }
  while (test_status == 0x0)
    {
      if ((rc = list_get (list, (void **) &item, POS_NEXT)) == EOF)
        {
          break;
        }
      if (rc > 0x0)
        {
          ERROR (TEST, "list_get", rc);
          test_status = EFAILED;
          break;
        }
      if (*item != PATTERN)
        {
          ERROR (TEST, "Data mismatch in data retrieval", ECKFAIL);
          test_status = EFAILED;
          break;
        }
      ++i;
    }
  if ((i != elements) && test_status == 0x0)
    {
      ERROR (TEST, "Data number mismatch in data retrieval", ECKFAIL);
      test_status = EFAILED;
    }
  if ((rc = list_destroy (list)) != 0x0)
    {
      ERROR (TEST, "list_destroy", ECKFAIL);
      test_status = EFAILED;
    }
  return test_status;
}

/*
 * Test scenario: Checks the deletion of items of the list in
 * different positions
 */
static int
check_deletion (size_t elements)
{
  int deleted = 0x0;            /* Number of elements deleted */
  int *item;			/* Item deleted from the list */
  int rc;			/* General purpose error handling variable */
  int test_status = 0x0;        /* Test status */
  register int i = 0x0;		/* A simple iterator */
  list_t list;

  if ((rc = list_init (&list, free)) != 0x0)
    {
      ERROR (TEST, "list_init", rc);
      test_status = EFAILED;
    }
  else if ((rc = load_list (list, elements, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_list", rc);
      test_status = EFAILED;
    }
  else if ((rc = list_move (list, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "list_move", rc);
      test_status = EFAILED;
    }
  else if ((rc = list_del (list, (void **) &item, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "list_del", rc);
      test_status = EFAILED;
    }
  else
    {
      free (item);
      ++deleted;

      if ((rc = list_move (list, POS_HEAD)) != 0x0)
        {
          ERROR (TEST, "list_move", rc);
          test_status = EFAILED;
        }
      else
        {
          register int i = 0x0;
          size_t list_length;
          
          if ((rc = list_size (list, &list_length)) != 0x0)
            {
              ERROR (TEST, "list_size", rc);
              test_status = EFAILED;
            }
          else
            {
              while ((rc = list_move (list, POS_NEXT)) == 0x0)
                {
                  ++i;
                  if (i == (list_length - 2))
                    {
                      break;
                    }
                }
              if (rc != EOF && rc != 0x0)
                {
                  ERROR (TEST, "list_move", rc);
                  test_status = EFAILED;               
                }
              else if ((rc = list_del (list, NULL, POS_NEXT)) == 0x0)
                {
                  ++deleted;
                  if ((rc = list_size (list, &list_length)) != 0x0)
                    {
                      ERROR (TEST, "list_size", rc);
                      test_status = EFAILED;
                    }
                  else if (list_length != (elements - deleted))
                    {
                      ERROR (TEST, "list length mismatch", ECKFAIL);
                      test_status = EFAILED;
                    }
                  else if ((rc = list_move (list, POS_HEAD)) != 0x0)
                    {
                      ERROR (TEST, "list_move", rc);
                      test_status = EFAILED;
                    }
                  else if ((rc = list_del (list, NULL, POS_NEXT)) != 0x0)
                    {
                      ERROR (TEST, "list_del", rc);
                      test_status = EFAILED;
                    }
                }
              else
                {
                  ERROR (TEST, "list_del", rc);
                  test_status = EFAILED;
                  
                }
            }
        }
    }
  if ((rc = list_destroy (list)) != 0x0)
    {
      ERROR (TEST, "list_destroy", ECKFAIL);
      test_status = EFAILED;
    }
  return test_status;
}

/*
 * Test scenario: Checks the reversal of the list
 */
static int
check_reversal (size_t elements)
{
  int rc;                       /* General return code */
  int bigger = 0x0;             /* Bigger item */
  size_t curr_item = 0x0u;      /* Current item counter */
  list_t list;                 
  int test_status = 0x0;

  if ((rc = list_init (&list, free)) != 0x0)
    {
      ERROR (TEST, "list_init", rc);
      return rc;
    }
  if ((rc = load_list (list, elements, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_list", rc);
      test_status = EFAILED;
    }
  else if ((rc = list_reverse (list)) != 0x0)
    {
      ERROR (TEST, "Error reversing the list", rc);
      test_status = EFAILED;
    }
  else 
    {
      if ((rc = list_move (list, POS_HEAD)) != 0x0)
        {
          ERROR (TEST, "list_move", rc);
          test_status = EFAILED;
        }
    }
  while (test_status == 0x0)
    {
      int * data;
      if ((rc = list_get (list, (void **) &data, POS_NEXT)) == EOF)
        {
          break;
        }
      else if (rc == 0)
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
      else
        {
          ERROR (TEST, "list_get", rc);
          test_status = EFAILED;
        }
    }
  if ((rc = list_destroy (list)) != 0x0)
    {
      ERROR (TEST, "list_destroy", ECKFAIL);
      test_status = EFAILED;
    }
  return test_status;
}
