/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 Contributed code by Daniel Costa Soares <daniel_csoares@yahoo.com.br>

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

 Description: Test suite routines for dclists. This test suite is also an
              example on how to use the dclists routines

 CVS Information
 $Author: harq_al_ada $
 $Id: dclist.c,v 1.6 2006-01-29 19:24:13 harq_al_ada Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "dclist.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist.c,v 1.6 2006-01-29 19:24:13 harq_al_ada Exp $";

/*
 * Local macros
 */
#define TEST "DCLIST"

/*
 * Local prototypes
 */
static int load_list (dclist_t, size_t);
static int scenario_check_contents (size_t);
static int scenario_check_deletion (size_t);
static int scenario_check_uninitialized (size_t);

/* Debug purpose */
static void print_list (dclist_t *);

int
test_dclist (size_t maxelements)
{
  int rc = 0x0;
  register int i;
  scenario_t scenarios[] = {
      {"Check uninitialized descriptor", scenario_check_uninitialized}
  };

  return execute_scenarios (TEST, maxelements, scenarios, sizeof (scenarios));

}

static int
scenario_check_uninitialized (size_t elements)
{
  int rc;
  int test_status = 0x0;
  void *buf = NULL;
  dclist_t dclist = NULL;

  rc = dclist_destroy (dclist);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_destroy", rc);
      test_status = EFAILED;
    }
  rc = dclist_get (dclist, &buf, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_get", rc);
      test_status = EFAILED;
    }
  rc = dclist_insert (dclist, buf, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_insert", rc);
      test_status = EFAILED;
    }
  rc = dclist_move (dclist, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_move", rc);
      test_status = EFAILED;
    }
  rc = dclist_del (dclist, &buf, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_del", rc);
      test_status = EFAILED;
    }
  return test_status;
}
