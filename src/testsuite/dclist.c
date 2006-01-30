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
 $Author: daniel_csoares $
 $Id: dclist.c,v 1.7 2006-01-30 18:13:23 daniel_csoares Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "dclist.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist.c,v 1.7 2006-01-30 18:13:23 daniel_csoares Exp $";

/*
 * Local macros
 */
#define TEST "DCLIST"

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
static int load_dclist (dclist_t, size_t, unsigned char);
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
      {"Check uninitialized descriptor", scenario_check_uninitialized},
      {"Check contents", scenario_check_contents},
      {"Check deletion", scenario_check_deletion}
  };

  return execute_scenarios (TEST, maxelements, scenarios, sizeof (scenarios));

}

/* Utility function: loads data into the list */
static int
load_dclist (dclist_t dclist, size_t maxelem, unsigned char use_pattern)
{
  register size_t i;
  int status;

  /* Initializations */
  status = 0x0;

  for (i = 0x0; (i < maxelem) && (status == 0x0); ++i)
    {
      int rc;
      int * elem;

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
              * elem = PATTERN;
            }
          else 
            {
              *elem = i;
            }
          if ((rc = dclist_insert (dclist, elem, POS_TAIL)) != 0x0)
            {
              ERROR (TEST, "dclist_insert", rc);
              status = EFAILED;
            }
        }
    }
  return status;
}

/* Check values inserted at dclist*/
static int
scenario_check_contents (size_t maxelem)
{
    dclist_t dclist;
    int rc;
    int status;
    register int i;
  
    i = 0x0;
    status = 0x0;

    if ((rc = dclist_init (&dclist, free)) != 0x0)
    {
        ERROR (TEST, "dclist_init", rc);
        status = EFAILED;
    }
    else if ((rc = load_dclist (dclist, maxelem, '\x0')) != 0x0)
    {
        ERROR (TEST, "load_dclist", rc);
        status = EFAILED;
    }
    else if ((rc = dclist_move (dclist, POS_HEAD)) != 0x0)
    {
        ERROR (TEST, "dclist_move", rc);
        status = EFAILED;
    }
    else 
    {
        int * elem;      
        size_t size;

        while ( i < maxelem && status == 0x0)
        {
            if ((rc = dclist_get(dclist, (void**)&elem, POS_NEXT)) != 0x0)
            {     
                ERROR (TEST, "dclist_get", rc);
                status = EFAILED;
                break;
            }
            if ( *elem != i )
            {
                ERROR (TEST, "Data mismatch in data retrieval", ECKFAIL);
                status = EFAILED;
                break;
            }
            i++;         
        }
    }
    if ((i != maxelem) && status == 0x0)
    {
        ERROR (TEST, "Data number mismatch in data retrieval", ECKFAIL);
        status = EFAILED;
    }
  
    if ((rc = dclist_destroy (dclist)) != 0x0)
    {
        ERROR (TEST, "dclist_destroy", rc);
        status = EFAILED;
    }

    return status;
}

/* Check values inserted at dclist*/
static int
scenario_check_deletion (size_t maxelem)
{
    dclist_t dclist;
    int rc;
    int status;
    register int i;
  
    i = 0x0;
    status = 0x0;

    if ((rc = dclist_init (&dclist, free)) != 0x0)
    {
        ERROR (TEST, "dclist_init", rc);
        status = EFAILED;
    }
    else if ((rc = load_dclist (dclist, maxelem, '\x0')) != 0x0)
    {
        ERROR (TEST, "load_dclist", rc);
        status = EFAILED;
    }
    else if ((rc = dclist_move (dclist, POS_HEAD)) != 0x0)
    {
        ERROR (TEST, "dclist_move", rc);
        status = EFAILED;
    }
    else 
    {
        int * elem;      
        size_t size;

        while ( i < maxelem && status == 0x0)
        {
            if ((rc = dclist_del(dclist, (void**)&elem, POS_HEAD)) != 0x0)
            {     
                ERROR (TEST, "dclist_del", rc);
                status = EFAILED;
                break;
            }
            if ( *elem != i )
            {
                ERROR (TEST, "Data mismatch in data retrieval", ECKFAIL);
                status = EFAILED;
                break;
            }
            i++;         
        }
    }
    if ((i != maxelem) && status == 0x0)
    {
        ERROR (TEST, "Data number mismatch in data retrieval", ECKFAIL);
        status = EFAILED;
    }
  
    if ((rc = dclist_destroy (dclist)) != 0x0)
    {
        ERROR (TEST, "dclist_destroy", rc);
        status = EFAILED;
    }

    return status;
}


/* Check error if call functions to a not initialized dclist*/
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
