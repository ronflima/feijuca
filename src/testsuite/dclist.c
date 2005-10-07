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

 Description: Test suite routines for dclists. This test suite is also an
              example on how to use the dclists routines

 CVS Information
 $Author: daniel_csoares $
 $Id: dclist.c,v 1.2 2005-10-07 17:54:26 daniel_csoares Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "dclist.h"

/* Version info */
static char const rcsid[] = "@(#) $Id: dclist.c,v 1.2 2005-10-07 17:54:26 daniel_csoares Exp $";

/*
 * Local macros
 */
#define TEST "DCLIST"

/*
 * Local prototypes
 */
static int load_list (dclist_t *, size_t);
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
      {"Check uninitialized descriptor", scenario_check_uninitialized}/*	,
        							   {"Contents checking", scenario_check_contents},
        							   {"Deletion checking", scenario_check_deletion} */
  };

  return execute_scenarios (TEST, maxelements, scenarios, sizeof (scenarios));

}

/*
 * Loads data into the list
 */
static int
load_list (dclist_t * list, size_t elements)
{

  register int i;		/* General purpose iterator */

  for (i = 0x0; i < elements; ++i)
    {
      unsigned int *item;	/* Item to insert */
      int rc;

      item = (int *) malloc (sizeof (unsigned int));
      if (item == NULL)
        {
          ERROR (TEST, "malloc", ECKFAIL);
          return ENOMEM;
        }

      *item = i + 1;

      if ((rc = dclist_insert (list, item, POS_TAIL)) != 0x0)
        {
          ERROR (TEST, "dclist_insert", rc);
          return EFAILED;
        }
    }

  return 0x0;
}

/*
 * Check lists contents
 */
static int
scenario_check_contents (size_t elements)
{
    /* THIS FUNCTION IS NOT FINISHED YET */
  int *item;			/* Item to grab from the list */
  int rc;			/* General error checking variable */
  position_t position = POS_HEAD;
  unsigned cksum[2] = { 0x0u, 0x0u };	/* Checksum for data validation */
  int c = 0x0;
  dclist_t * list;
  while (position != POS_PREV)
    {
      register int i = 0x0;	/* General iterator */

      /* Gets the data from the list, iterating it and checking the contents */
      if ((rc = dclist_move (list, position)) != 0x0)
        {
          ERROR (TEST, "dclist_move", rc);
          return EFAILED;
        }
      position = position == POS_HEAD ? POS_NEXT : POS_PREV;
      while (rc == 0x0 && i != descriptor_size (list))
        {
          /* Gets the current item of the list and goes to the next */
          rc = dclist_get (list, (void **) &item, position);
          if (rc > 0x0)
            {
              ERROR (TEST, "dclist_get", rc);
              return EFAILED;
            }
          /* ARRUMAR */
          cksum[c] |= *item;
          ++i;
        }
      if (i != elements)
        {
          ERROR (TEST, "Number of elements mismatch", ECKFAIL);
          return EFAILED;
        }
      ++c;
      if (position == POS_NEXT)
        {
          position = POS_TAIL;
        }
    }
  if (cksum[0] != cksum[1])
    {
      ERROR (TEST, "Corrupt data found.", ECKFAIL);
      return EFAILED;
    }
  return 0x0;
}

/*
 * Checks the deletion of items of the list
 */
static int
scenario_check_deletion (size_t elements)
{
    /* THIS FUNCTION IS NOT FINISHED YET */
    
  int deleted;			/* Number of elements deleted */
  int *item;			/* Item deleted from the list */
  int rc;			/* General error handling variable */
  register int i;		/* A simple iterator */
  dclist_t * list;
  
  /* Initializations */
  deleted = 0x0;
  i = 0x0;

  if ((rc = dclist_del (list, (void **) &item, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "dclist_del", rc);
      return EFAILED;
    }

  ++deleted;
  if ((rc = dclist_del (list, (void **) &item, POS_TAIL)) != 0x0)
    {
      ERROR (TEST, "dclist_del", rc);
      return EFAILED;
    }

  ++deleted;
  if ((rc = dclist_move (list, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "dclist_move", rc);
      return EFAILED;
    }
  if ((rc = dclist_del (list, (void **) &item, POS_CURR)) != 0x0)
    {
      ERROR (TEST, "dclist_del", rc);
      return EFAILED;
    }

  ++deleted;
  if ((rc = dclist_move (list, POS_HEAD)) != 0x0)
    {
      ERROR (TEST, "dclist_move", rc);
      return EFAILED;
    }
  if ((rc = dclist_del (list, (void **) NULL, POS_NEXT)) != 0x0)
    {
      ERROR (TEST, "dclist_del", rc);
      return EFAILED;
    }
  ++deleted;
  if ((rc = dclist_move (list, POS_TAIL)) != 0x0)
    {
      ERROR (TEST, "dclist_move", rc);
      return EFAILED;
    }
  if ((rc = dclist_del (list, (void **) NULL, POS_CURR)) != 0x0)
    {
      ERROR (TEST, "dclist_del", rc);
      return EFAILED;
    }
  ++deleted;
  if ((elements - deleted) != descriptor_size (list))
    {
      ERROR (TEST, "Number of elements mismatch for deletion", ECKFAIL);
      return EFAILED;
    }
  return 0x0;
}

static int
scenario_check_uninitialized (size_t elements)
{
  int rc;
  int test_status = 0x0;
  void *buf = NULL;
  dclist_t dclist;

  rc = dclist_destroy (&dclist);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_destroy", rc);
      test_status = EFAILED;
    }
  rc = dclist_get (&dclist, &buf, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_get", rc);
      test_status = EFAILED;
    }
  rc = dclist_insert (&dclist, buf, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_insert", rc);
      test_status = EFAILED;
    }
  rc = dclist_move (&dclist, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_move", rc);
      test_status = EFAILED;
    }
  rc = dclist_del (&dclist, &buf, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dclist_del", rc);
      test_status = EFAILED;
    }
  return test_status;
}

static void
print_list (dclist_t * list)
{
  int i;
  int rc;
  int *item;
  /* Move to the begining */
  rc = dclist_move (list, POS_HEAD);
  if (rc)
    {
      return;
    }
  for (i = 0; i < descriptor_size (list); i++)
    {
      rc = dclist_get (list, (void **)&item, POS_CURR);
      if (rc)
        {
          return;
        }
      fprintf (stderr, "<%d> ", *item);
      rc = dclist_move (list, POS_NEXT);
      if (rc)
        {
          return;
        }
    }
  rc = dclist_move (list, POS_HEAD);
  if (rc)
    {
      return;
    }
  rc = dclist_get (list, (void **)&item, POS_CURR);
  if (rc)
    {
      return;
    }
  fprintf (stderr, "h<%d> ", *item);
  rc = dclist_move (list, POS_PREV);
  if (rc)
    {
      return;
    }
  rc = dclist_get (list, (void **)&item, POS_CURR);
  if (rc)
    {
      return;
    }
  fprintf (stderr, "t<%d> ", *item);
  rc = dclist_move (list, POS_NEXT);
  if (rc)
    {
      return;
    }
  rc = dclist_get (list, (void **)&item, POS_CURR);
  if (rc)
    {
      return;
    }
  fprintf (stderr, "h<%d>\n", *item);
}
