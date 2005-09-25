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

 Description: Test suite routines for circular lists. This test suite is also
              an example on how to use the lists routines

 CVS Information
 $Author: ron_lima $
 $Id: ivector.c,v 1.11 2005-09-25 20:37:27 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector.c,v 1.11 2005-09-25 20:37:27 ron_lima Exp $";

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
static int load_ivector (ivector_t *, size_t, unsigned char);
static int check_del (size_t);
static int check_uninitialized (size_t);

/*
 * Exported functions
 */
int 
test_ivector (size_t maxelem)
{
  int rc = 0x0;
  register int i;
  scenario_t scenarios [] = {
    {"Check uninitialized descriptor", check_uninitialized},
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
load_ivector (ivector_t * ivector, size_t maxelem, unsigned char use_pattern)
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

  if ((rc = ivector_init (&ivector, compare, NULL, sizeof (int))) != 0x0)
    {
      ERROR (TEST, "ivector_init", rc);
      status = EFAILED;
    }
  else if ((rc = load_ivector (&ivector, maxelem, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_ivector (utility function)", rc);
      status = EFAILED;
    }
  else 
    {
      register size_t i;
      for (i = 0; (i < maxelem / 2) && (status != EFAILED); ++i)
        {
          if ((rc = ivector_del (&ivector, i)) != 0x0)
            {
              ERROR (TEST, "ivector_del", rc);
              status = EFAILED;
            }
        }
      if (descriptor_size (&ivector) != (maxelem / 2))
        {
          ERROR (TEST, "number of elements mismatch", ECKFAIL);
          status = EFAILED;
        }
    }
  if ((rc = ivector_destroy (&ivector)) != 0x0)
    {
      ERROR (TEST, "ivector_destroy", rc);
      status = EFAILED;
    }
  return 0x0;
}

/* Scenario 2: Checks signature validation */
static int check_uninitialized (size_t maxelem)
{
  int rc;
  void * buf = NULL;
  int test_status = 0x0;
  ivector_t ivector;

  if ((rc = ivector_destroy (&ivector)) != EGAINVAL)
    {
      ERROR (TEST, "ivector_destroy", rc);
      test_status = EFAILED;
    }
  else if ((rc = ivector_get (&ivector, &buf, 0x0)) != EGAINVAL)
    {
      ERROR (TEST, "ivector_get", rc);
      test_status = EFAILED;
    }
  else if ((rc = ivector_put (&ivector, 0x0, buf)) != EGAINVAL)
    {
      ERROR (TEST, "ivector_put", rc);
      test_status = EFAILED;
    }
  else if ((rc = ivector_add (&ivector, buf)) != EGAINVAL)
    {
      ERROR (TEST, "ivector_add", rc);
      test_status = EFAILED;
    }
  else if ((rc = ivector_qsort (&ivector)) != EGAINVAL)
    {
      ERROR (TEST, "ivector_qsort", rc);
      test_status = EFAILED;
    }
  else if ((rc = ivector_bsearch (&ivector, &buf, buf)) != EGAINVAL)
    {
      ERROR (TEST, "ivector_bsearch", rc);
      test_status = EFAILED;
    }
  else if ((rc = ivector_del (&ivector, 0x0)) != EGAINVAL)
    {
      ERROR (TEST, "ivector_del", rc);
      test_status = EFAILED;
    }
  return test_status;
}
