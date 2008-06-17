/* -*-c-*-

 Feijuca Library - A generic algorithms and data structures library Copyright
 (C) 2005 - Ronaldo Faria Lima

 This library is free software; you can redistribute it and/or modify it under
 the terms of the GNU Lesser General Public License as published by the Free
 Software Foundation; either version 2.1 of the License, or (at your option) any
 later version.

 This library is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 details.

 You should have received a copy of the GNU Lesser General Public License along
 with this library; if not, write to the Free Software Foundation, Inc., 51
 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

 System: Feijuca Library

 Description: Test suite routines for lists. This test suite is also an example
              on how to use the lists routines
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list.c,v 1.28 2007-02-25 13:03:48 harq_al_ada Exp $";

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
static GAERROR check_deletion_in_middle (list_t, int *);
static GAERROR check_deletion_in_head (list_t, int *);
static GAERROR check_deletion_in_tail (list_t);
static GAERROR check_deletion_near_tail (list_t, int *);
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
  GAERROR rc;			/* General error checking variable */
  int test_status;		/* Test status */
  register int i;		/* General iterator */
  list_t list;

  test_status = 0x0;
  i = 0x0;

  if ((list = list_init (free)) == NULL)
    {
      ERROR (TEST, "list_init", rc);
      return rc;
    }
  if ((rc = load_list (list, elements, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_list", rc);
      test_status = EFAILED;
    }
  else if ((rc = list_move (list, POS_HEAD)) != EGAOK)
    {
      ERROR (TEST, "list_move", rc);
      test_status = EFAILED;
    }
  while (test_status == 0x0)
    {
      int *item;			/* Item to grab from the list */

      if ((item = (int *) list_get (list, POS_CURR)) == NULL)
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
      if ((rc = list_move (list, POS_NEXT)) == EGAEOF)
        {
          break;
        }
      else if (rc > 0x0)
        {
          ERROR (TEST, "list_move", rc);
          test_status = EFAILED;
          break;
        }
    }
  if ((i != elements) && test_status == 0x0)
    {
      ERROR (TEST, "Data number mismatch in data retrieval", ECKFAIL);
      test_status = EFAILED;
    }
  list_destroy (list);
  return test_status;
}

/*
 * Test scenario: Checks the deletion of items of the list in
 * different positions
 */
static int
check_deletion (size_t elements)
{
  GAERROR rc;                   /* General purpose error handling variable */
  int test_status = 0x0;        /* Test status */
  register int i = 0x0;		/* A simple iterator */
  list_t list;                  /* List descriptor */
  int nelem = 0x0;              /* Number of elements */
  int ndeleted = 0x0;           /* Number of deleted elements */

  if ((list = list_init (free)) == NULL)
    {
      ERROR (TEST, "list_init", rc);
      test_status = EFAILED;
    }
  else if ((rc = load_list (list, elements, '\x1')) != EGAOK)
    {
      ERROR (TEST, "load_list", rc);
      test_status = EFAILED;
    }
  else 
    {
      size_t size;              /* Size of the list after deletions */

      nelem = list_get_size (list);
      if ((rc = list_move (list, POS_HEAD)) != EGAOK)
        {
          ERROR (TEST, "list_move", rc);
          test_status = EFAILED;
        }
      else if ((rc = check_deletion_near_tail (list, &ndeleted)) != EGAOK)
        {
          ERROR (TEST, "check_deletion_near_tail", ECKFAIL);
          test_status = EFAILED;
        }
      else if ((rc = check_deletion_in_middle (list, &ndeleted)) != EGAOK)
        {
          ERROR (TEST, "check_deletion_in_middle", ECKFAIL);
          test_status = EFAILED;
        }
      else if ((rc = check_deletion_in_head (list, &ndeleted)) != EGAOK)
        {
          ERROR (TEST, "check_deletion_in_head", ECKFAIL);
          test_status = EFAILED;
        }
      else if ((rc = check_deletion_in_tail (list)) != EGAOK)
        {
          ERROR (TEST, "check_deletion_in_tail", ECKFAIL);
          test_status = EFAILED;
        }
      size = list_get_size (list);
      if ((rc == EGAOK) && (nelem - ndeleted) != size)
        {
          ERROR (TEST, "List number of items mismatch", ECKFAIL);
          test_status = EFAILED;
        }
    }
  list_destroy (list);
  return test_status;
}
/*
 * Part of the deletion test scenario: tests deletion at the middle of
 * the list.
 */
static GAERROR check_deletion_in_middle(list_t list, int * deleted)
{
  GAERROR rc;                   /* Error handling */

  if ((rc = list_move (list, POS_HEAD)) != EGAOK)
    {
      ERROR (TEST, "list_move", rc);
    }
  else
    {
      register int i;
      size_t size;		/* Size of the list */

      size = list_get_size (list);
      /* Move the curr to the middle of the list */
      for (i=0x0; i<size/2; ++i) 
        {
          if ((rc == list_move (list, POS_NEXT)) != EGAOK)
            {
              if (rc > 0x0) 
                {
                  ERROR (TEST, "list_move", rc);
                }
              break;
            }
        }
      if (rc == EGAOK)
        {
          if ((rc = list_del (list, NULL, POS_NEXT)) != EGAOK)
            {
              ERROR (TEST, "list_del", rc);
            }
          else 
            {
              ++(*deleted);
            }
        }
    }
  return rc;
}
/*
 * Part of the deletion test scenario: Check deletions on the head of
 * the list.
 */
static GAERROR check_deletion_in_head (list_t list, int * deleted)
{
  GAERROR rc;                   /* Error handling */

  if ((rc = list_del (list, NULL, POS_HEAD)) != EGAOK)
    {
      ERROR (TEST, "list_del", rc);
    }
  else
    {
      ++(*deleted);
    }
  return rc;
}
/*
 * Part of the deletion test scenario: Check deletions on the element
 * prior to the tail
 */
static GAERROR check_deletion_near_tail (list_t list, int * ndeleted)
{
  GAERROR rc;                   /* Error handling */
  size_t size;                  /* Size of the list */

  size = list_get_size (list);
  if (size > 1)
    {
      if ((rc = list_move (list, POS_HEAD)) != EGAOK)
	{
	  ERROR (TEST, "list_move", rc);
	}
      else
	{
	  register int i = size;     /* Counter to navigate the list */

	  /* This test makes sense only if the list has size greater
	   * than 1 */
	  while (i - 2 > 0)
	    {
	      if ((rc = list_move (list, POS_NEXT)) != EGAOK)
		{
		  break;
		}
	      --i;
	    }
	  if (rc == EGAOK)
	    {
	      if ((rc = list_del (list, NULL, POS_NEXT)) != EGAOK)
		{
		  ERROR (TEST, "list_del", rc);
		}
	      else
		{
		  ++(*ndeleted);
		}
	    }
	  else if (rc != EGAEOF)
	    {
	      ERROR (TEST, "list_move", rc);
	    }
	}
    }
  return rc;
}
/*
 * Part of the deletion test scenario: Check deletions on the tail of
 * the list - Exception since it is not possible to delete anything
 * from the tail.
 */
static GAERROR check_deletion_in_tail (list_t list)
{
  GAERROR rc;                   /* Error handling */

  if ((rc = list_del (list, NULL, POS_TAIL)) == EGAOK)
    {
      ERROR (TEST, "list_del", ECKFAIL);
    }
  else
    {
      rc = EGAOK;
    }
  return rc;
}

/*
 * Test scenario: Checks the reversal of the list
 */
static int
check_reversal (size_t elements)
{
  GAERROR rc;                   /* General return code */
  int bigger = 0x0;             /* Bigger item */
  size_t curr_item = 0x0u;      /* Current item counter */
  list_t list;                 
  int test_status = 0x0;

  if ((list = list_init (free)) == NULL)
    {
      ERROR (TEST, "list_init", rc);
      return rc;
    }
  if ((rc = load_list (list, elements, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_list", rc);
      test_status = EFAILED;
    }
  else if ((rc = list_reverse (list)) != EGAOK)
    {
      ERROR (TEST, "Error reversing the list", rc);
      test_status = EFAILED;
    }
  else 
    {
      if ((rc = list_move (list, POS_HEAD)) != EGAOK)
        {
          ERROR (TEST, "list_move", rc);
          test_status = EFAILED;
        }
    }
  while (test_status == 0x0)
    {
      int * data;
      if ((data = list_get (list, POS_NEXT)) == NULL)
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
  list_destroy (list);
  return test_status;
}

