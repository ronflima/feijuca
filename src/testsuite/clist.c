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

 Description: Test suite routines for circular lists. This test suite is also
              an example on how to use the lists routines

 CVS Information
 $Author: ron_lima $
 $Id: clist.c,v 1.10 2005-12-13 10:18:52 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "clist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: clist.c,v 1.10 2005-12-13 10:18:52 ron_lima Exp $";

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
static int load_clist (clist_t *, size_t, unsigned char);
static int check_navigation (size_t);

/*
 * Exported functions
 */

int
test_clist (size_t maxelements)
{
  int rc = 0x0;
  register int i;
  scenario_t scenarios [] = {
    {"Navigation checking", check_navigation}
  };

  return execute_scenarios (TEST, maxelements, scenarios, sizeof (scenarios));
}

/* Utility function: Loads data into the circular list */
static int
load_clist (clist_t * clist, size_t elements, unsigned char use_pattern)
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
      if ((rc = clist_insert (clist, item)) != 0x0)
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

  test_result = 0x0;

  if ((rc = clist_init (&clist, free)) != 0x0)
    {
      ERROR (TEST, "clist_init", rc);
      test_result = EFAILED;
    }
  else if ((rc = load_clist (&clist, maxelem, '\x0')) != 0x0)
    {
      ERROR (TEST, "load_clist", rc);
      test_result = EFAILED;
    }
  else if ((rc = clist_move (&clist, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "clist_move", rc);
      test_result = EFAILED;
    }
  else
    {
      int i = 0x1;
      do 
        {
          if (clist.list_.curr_ == clist.list_.tail_)
            {
              break;
            }
          ++i;
        }
      while ((rc = clist_move (&clist, POS_NEXT)) == 0x0);
      if (rc > 0x0)
        {
          ERROR (TEST, "CList navigation failed", rc);
          test_result = EFAILED;
        }
      if (i != descriptor_size (&clist.list_))
        {
          ERROR (TEST, "Navigation wrong: number of items mismatch", ECKFAIL);
          test_result = EFAILED;
        }
    }
  if ((rc = clist_destroy (&clist)) != 0x0)
    {
      ERROR (TEST, "clist_destroy", rc);
      test_result = EFAILED;
    }
  return test_result;
}
