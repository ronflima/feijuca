/* -*-c-*-
 Feijuca Library - A generic algorithms and data structures library
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

 System: Feijuca Lib

 Description: Test suite routines for circular lists. This test suite is also
              an example on how to use the lists routines

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "clist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id$";

/*
 * Local macros
 */
#define TEST "CLIST"

/*
 * Local constants
 */
enum 
{
  PATTERN = 0xDEADBEEFu
};


/*
 * Local prototypes
 */
static int load_clist (clist_t, size_t, unsigned char);
static int check_navigation (size_t);
static int check_deletion (size_t);

/*
 * Exported functions
 */

int
test_clist (size_t maxelements)
{
  int rc = 0x0;
  register int i;
  scenario_t scenarios [] = {
    {"Navigation checking", check_navigation},
    {"Deletion check"     , check_deletion  }
  };

  return execute_scenarios (TEST, maxelements, scenarios, sizeof (scenarios));
}

/* Utility function: Loads data into the circular list */
static int
load_clist (clist_t clist, size_t elements, unsigned char use_pattern)
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
      if (item == NULL)
        {
          ERROR (TEST, "malloc", 0);
          test_status = ENOMEM;
          break;
        }

      /* Builds the item data */
      if (use_pattern == '\x1') 
        {
          *item = PATTERN;
        }
      else 
        {
          *item = i + 1;
        }

      /* Inserts the item in the list */
      if ((rc = clist_insert (clist, item, POS_HEAD)) != 0x0)
        {
          ERROR (TEST, "clist_insert", rc);
          test_status = EFAILED;
          break;
        }
    }

  return test_status;
}

/* Scenario 1: checks the list navigation */
static int
check_navigation (size_t maxelem)
{
  clist_t clist;
  int rc;
  int test_result;
  size_t size;

  test_result = 0x0;

  if ((clist = clist_init (free)) == NULL)
    {
      ERROR (TEST, "clist_init", rc);
      test_result = EFAILED;
    }
  else if ((rc = load_clist (clist, maxelem, '\x0')) != 0x0)
    {
      ERROR (TEST, "load_clist", rc);
      test_result = EFAILED;
    }
  else if ((rc = clist_move (clist, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "clist_move", rc);
      test_result = EFAILED;
    }
  else
    {
      int i = 0x1;
      do 
        {
          position_t whence;
	  
	  whence = clist_get_pos (clist);
          if (whence == POS_TAIL)
            {
              break;
            }
          ++i;
        }
      while ((rc = clist_move (clist, POS_NEXT)) == 0x0);
      if (rc > 0x0)
        {
          ERROR (TEST, "CList navigation failed", rc);
          test_result = EFAILED;
        }
      size = clist_get_size (clist);
      if (i != size)
        {
          ERROR (TEST, "Navigation wrong: number of items mismatch", ECKFAIL);
          test_result = EFAILED;
        }
    }
  clist_destroy (clist);
  return test_result;
}

/* Scenario 2: deletion of elements from the list */
static int
check_deletion (size_t elements)
{
  clist_t clist;
  int rc;
  int test_result;

  test_result = 0x0;

  if ((clist = clist_init (free)) == NULL)
    {
      ERROR (TEST, "clist_init", rc);
      test_result = EFAILED;
    }
  else if ((rc = load_clist (clist, elements, '\x0')) != 0x0)
    {
      ERROR (TEST, "load_clist", rc);
      test_result = EFAILED;
    }
  else if ((rc = clist_move (clist, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "clist_move", rc);
      test_result = EFAILED;
    }
  else
    {
      /* Test 1: check deletion of an arbitrary element of the list */
      if ((rc = clist_del (clist, NULL, POS_NEXT)) != 0x0)
        {
          ERROR (TEST, "clist_del", rc);
          test_result = EFAILED;
        }
      else
        {
          /* Test 2: check deletion of the head of the list */
          if ((rc = clist_del (clist, NULL, POS_HEAD)) != 0x0)
            {
              ERROR (TEST, "clist_del", rc);
              test_result = EFAILED;
            }
          else
            {
              size_t clist_length;            
	      register int i = 0x1;

	      /* Test 3: check the deletion of the tail of the list */
	      clist_length = clist_get_size (clist);
	      /* Move to the element prior to the tail */
	      while ((rc = clist_move (clist, POS_NEXT)) == 0x0)
		{
		  ++i;
		  if (i >= clist_length - 1)
		    {
		      break;
		    }
		}
	      if (rc > 0x0)
		{
		  ERROR (TEST, "clist_move", rc);
		  test_result = EFAILED;
		}
	      else if ((rc = clist_del (clist, NULL, POS_NEXT)) != 0x0)
		{
		  ERROR (TEST, "clist_del", rc);
		  test_result = EFAILED;
		}
	      else if ((rc = clist_move (clist, POS_TAIL)) != 0x0)
		{
		  ERROR (TEST, "clist_move", rc);
		  test_result = EFAILED;
		}
	      else
		{
		  /* Test 4: Delete the head through the tail */
		  if ((rc = clist_del (clist, NULL, POS_NEXT)) != 0x0)
		    {
		      ERROR (TEST, "clist_del", rc);
		      test_result = EFAILED;
		    }
		}
	    }
	}
    }
  clist_destroy (clist);
  return test_result;
}
