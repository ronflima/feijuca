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
 $Author: harq_al_ada $
 $Id: ivector.c,v 1.16 2006-02-04 21:27:50 harq_al_ada Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector.c,v 1.16 2006-02-04 21:27:50 harq_al_ada Exp $";

/*
 * Local constants
 */
enum 
{
  PATTERN = 0xDEADBEEFu
};

/*
 * Local macros
 */
#define TEST "IVECTOR"

/*
 * Local prototypes
 */
static int compare (const void *, const void *);
static int load_ivector (ivector_t, size_t, unsigned char);
static int check_del (size_t);

/*
 * Exported functions
 */
int 
test_ivector (size_t maxelem)
{
  int rc = 0x0;
  register int i;
  scenario_t scenarios [] = {
    {"Deletion checking"             , check_del          }
  };

  return execute_scenarios (TEST, maxelem, scenarios, sizeof (scenarios));
}

/* Compare function for the infinite vector */
static int
compare (const void *arg1, const void *arg2)
{
  int *v1 = (int *) arg1;
  int *v2 = (int *) arg2;

  return *v1 > *v2;
}

/* Utility function: Loads data into the infinite vector */
static int
load_ivector (ivector_t ivector, size_t maxelem, unsigned char use_pattern)
{
  register int i;		/* General iterator */

  for (i=0; i<maxelem; ++i)
    {
      int buf;
      int rc;			/* General error handling variable */

      if (use_pattern) 
        {
          buf = PATTERN;
        }
      else
        {
          buf = i;
        }
      if ((rc = ivector_add (ivector, (void *) &buf)) != 0x0)
        {
          ERROR (TEST, "ivector_add", rc);
          return EFAILED;
        }
    }
  return 0x0;
}

/* Scenario 1: Checks deletions */
static int
check_del (size_t maxelem)
{
  int rc;
  int status;
  ivector_t ivector;

  status = 0x0;

  if ((rc = ivector_init (&ivector, compare, sizeof (int))) != 0x0)
    {
      ERROR (TEST, "ivector_init", rc);
      status = EFAILED;
    }
  else if ((rc = load_ivector (ivector, maxelem, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_ivector (utility function)", rc);
      status = EFAILED;
    }
  else 
    {
      register size_t i;
      size_t size;
      int to_delete;

      to_delete = maxelem / 2;
      for (i = 0; (i < to_delete) && (status != EFAILED); ++i)
        {
          if ((rc = ivector_del (ivector, i)) != 0x0)
            {
              ERROR (TEST, "ivector_del", rc);
              status = EFAILED;
            }
        }
      if ((rc = ivector_size (ivector, &size)) != 0x0)
        {
          ERROR (TEST, "ivector_size", ECKFAIL);
          status = EFAILED;
        }
      if (size != (maxelem - to_delete))
        {
          ERROR (TEST, "number of elements mismatch", ECKFAIL);
          status = EFAILED;
        }
    }
  if ((rc = ivector_destroy (ivector)) != 0x0)
    {
      ERROR (TEST, "ivector_destroy", rc);
      status = EFAILED;
    }
  return 0x0;
}
