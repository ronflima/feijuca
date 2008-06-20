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
 $Id: dlist.c,v 1.21 2006-02-04 14:36:34 harq_al_ada Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "dlist.h"

/* Version info */
static char const rcsid[] =
  "@(#) $Id: dlist.c,v 1.21 2006-02-04 14:36:34 harq_al_ada Exp $";

/*
 * Local macros
 */
#define TEST "DLIST"

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
static int load_dlist (dlist_t, size_t, unsigned char);
static int scenario_check_forward_nav (size_t);
static int scenario_check_deletions (size_t);
static int scenario_check_back_nav (size_t);

/*
 * Exported functions
 */

int
test_dlist (size_t maxelem)
{
  int rc = 0x0;
  register int i;
  scenario_t scenarios[] = {
    {"Forward navigation check", scenario_check_forward_nav},
    {"Deletions check", scenario_check_deletions},
    {"Backward navigation check", scenario_check_back_nav}
  };

  return execute_scenarios (TEST, maxelem, scenarios, sizeof (scenarios));
}

/* Utility function: loads data into the list */
static int
load_dlist (dlist_t dlist, size_t maxelem, unsigned char use_pattern)
{
  register size_t i;		/* General purpose iterator */
  int status;

  status = 0x0;

  for (i = 0x0; (i < maxelem) && (status == 0x0); ++i)
    {
      int rc;
      int *elem;

      elem = (int *) malloc (sizeof (int));
      if (elem == NULL)
        {
          ERROR (TEST, "malloc", ENOMEM);
          status = EFAILED;
        }
      else
        {
          if (use_pattern)
            {
              *elem = PATTERN;
            }
          else
            {
              *elem = i + 1;
            }
          if ((rc = dlist_insert (dlist, elem, POS_HEAD)) != 0x0)
            {
              ERROR (TEST, "dlist_insert", rc);
              status = EFAILED;
            }
        }
    }

  return status;
}

/*
 * Local functions definitions
 */

/* Scenario 1: check forward navigation in the list */
static int
scenario_check_forward_nav (size_t maxelem)
{
  dlist_t dlist;
  int rc;
  int status;

  status = 0x0;

  if ((dlist = dlist_init (free)) == NULL)
    {
      ERROR (TEST, "dlist_init", rc);
      status = EFAILED;
    }
  else if ((rc = load_dlist (dlist, maxelem, '\x0')) != 0x0)
    {
      ERROR (TEST, "load_dlist", rc);
      status = EFAILED;
    }
  else if ((rc = dlist_move (dlist, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "dlist_move", rc);
      status = EFAILED;
    }
  else
    {
      register int i;
      size_t size;

      i = 0x0;
      do
        {
          if ((rc = dlist_move (dlist, POS_NEXT)) > 0x0)
            {
              ERROR (TEST, "dlist_move", rc);
              status = EFAILED;
              break;
            }
          if (rc == 0x0)
            {
              ++i;
            }
        }
      while (rc == 0x0);

      size = dlist_size (dlist);
      if (i != size)
        {
          ERROR (TEST, "# of elements mismatch", ECKFAIL);
          status = EFAILED;
        }
    }
  dlist_destroy (dlist);

  return status;
}

/* Test scenario: check the items deletions */
static int
scenario_check_deletions (size_t maxelem)
{
  int rc;
  int status;
  dlist_t dlist;

  status = 0x0;
  if ((dlist = dlist_init (free)) == NULL)
    {
      ERROR (TEST, "dlist_init", rc);
      status = EFAILED;
    }
  else if ((rc = load_dlist (dlist, maxelem, '\x0')) != 0x0)
    {
      ERROR (TEST, "load_dlist", rc);
      status = EFAILED;
    }
  else if ((rc = dlist_del (dlist, NULL, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "dlist_del", rc);
      status = EFAILED;
    }
  else if ((rc = dlist_del (dlist, NULL, POS_TAIL)) != 0x0)
    {
      ERROR (TEST, "dlist_del", rc);
      status = EFAILED;
    }
  else
    {
      if ((rc = dlist_move (dlist, POS_HEAD)) != 0x0)
        {
          ERROR (TEST, "dlist_move", rc);
          status = EFAILED;
        }
      else
        {
          register int i;
          size_t size;

          i = 0x0;
          while ((rc = dlist_move (dlist, POS_NEXT)) == 0x0)
            {
              ++i;
            }

          size = dlist_size (dlist);
          if (i != size)
            {
              ERROR (TEST, "Number of items mismatch", ECKFAIL);
              status = EFAILED;
            }
        }
    }
  dlist_destroy (dlist);
  return status;
}

/* Test scenario: check backward navigation */
static int
scenario_check_back_nav (size_t maxelem)
{
  int rc;
  int status;
  dlist_t dlist;

  status = 0x0;
  if ((dlist = dlist_init (free)) == NULL)
    {
      ERROR (TEST, "dlist_init", rc);
      status = EFAILED;
    }
  else if ((rc = load_dlist (dlist, maxelem, '\x0')) != 0x0)
    {
      ERROR (TEST, "load_dlist", rc);
      status = EFAILED;
    }
  else if ((rc = dlist_move (dlist, POS_TAIL)) != 0x0)
    {
      ERROR (TEST, "dlist_move", rc);
      status = EFAILED;
    }
  else
    {
      register int i;
      size_t size;

      i = 0x0;
      while ((rc = dlist_move (dlist, POS_PREV)) == 0x0)
        {
          ++i;
        }

      size = dlist_size (dlist);
      if (i != size)
        {
          ERROR (TEST, "Number of items mismatch", ECKFAIL);
          status = EFAILED;
        }
      if (rc > 0x0)
        {
          ERROR (TEST, "dlist_move", rc);
          status = EFAILED;
        }
    }
  dlist_destroy (dlist);
  return status;
}
