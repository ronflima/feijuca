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

 Description: Test suite routines for lists. This test suite is also an
              example on how to use the lists routines

 CVS Information
 $Author: ron_lima $
 $Id: dlist.c,v 1.14 2005-07-29 02:35:19 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "dlist.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: dlist.c,v 1.14 2005-07-29 02:35:19 ron_lima Exp $";

/*
 * Local macros
 */
#define TEST "DLIST"

/*
 * Local prototypes
 */
static int load_list (dlist_t *, size_t);
static int check_contents (dlist_t *, size_t);
static int check_deletion (dlist_t *, size_t);
static int check_uninitialized (dlist_t *);
static position_t next_position (position_t);

int
test_dlist (size_t maxelements)
{
  dlist_t list;                 /* List descriptor */
  int rc;                       /* Error handling variable */
  int test_status;              /* Test status variable */

  test_status = 0x0;
  if ((rc = check_uninitialized (&list)) != 0)
    {
      ERROR (TEST, "check_uninitialized", rc);
      test_status = EFAILED;
    }
  /* We are using the free as the deallocator since this test will
     involve only simple allocated data */
  if ((rc = dlist_init (&list, free)) != 0)
    {
      ERROR (TEST, "dlist_alloc", rc);
      test_status = EFAILED;
    }
  else
    {
      if ((rc = load_list (&list, maxelements)) == 0)
        {
          if ((rc = check_contents (&list, maxelements)) != 0)
            {
              ERROR (TEST, "check_contents", rc);
              test_status = EFAILED;
            }
          if ((rc = check_deletion (&list, maxelements)) != 0)
            {
              ERROR (TEST, "check_deletion", rc);
              test_status = EFAILED;
            }
        }
      else
        {
          ERROR (TEST, "dload_list", rc);
          test_status = EFAILED;
        }
      if ((rc = dlist_destroy (&list)) != 0)
        {   
          ERROR (TEST, "dlist_free", rc);
          test_status = EFAILED;
        }
    }

  return test_status;
}

/*
 * Loads data into the list
 */
static int
load_list (dlist_t * list, size_t elements)
{
  register int i;		/* General purpose iterator */
  position_t position;          /* Position to test */
  
  position = POS_NONE;

  /* Loads the list */    
  for (i = 0x0; (i < elements); ++i)
    {
      int *item;		/* Item to insert */
      int rc;			/* General purpose error handling variable */
      
      item = (int *) malloc (sizeof (int));
      if (item == NULL)
        {
          ERROR (TEST, "malloc", ECKFAIL);
          return ENOMEM;
        }
      *item = i + 1;
      if (position == POS_NEXT || position == POS_PREV || position == POS_CURR)
        {
          dlist_move (list, POS_HEAD);
          dlist_move (list, POS_NEXT);
        }
      if ((rc = dlist_insert (list, item, position)) != 0x0)
        {
          ERROR (TEST, "dlist_insert", rc);
          return EFAILED;
        }
       position = next_position (position);      
    }
  return 0x0;
}

/*
 * Check lists contents
 */
static int
check_contents (dlist_t * list, size_t elements)
{
  int *item;			    /* Item to grab from the list */
  int rc;			    /* General error checking variable */
  position_t position = POS_HEAD;
  unsigned cksum [2]= {0x0u, 0x0u}; /* Checksum for data validation */
  int c=0x0;

  while (position != POS_PREV)
    {
      register int i = 0x0;		    /* General iterator */

      /* Gets the data from the list, iterating it and checking the contents */
      if((rc = dlist_move (list, position)) != 0x0)
        {
          ERROR (TEST, "dlist_move", rc);
          return EFAILED;
        }
      position = position == POS_HEAD ? POS_NEXT : POS_PREV;
      while (rc == 0x0)
        {
          /* Gets the current item of the list and goes to the next */
          rc = dlist_get (list, (void **) &item, position);
          if (rc > 0x0)
            {
              ERROR (TEST, "dlist_get", rc);
              return EFAILED;
            }
          if (rc < 0x0)
            {
              /* EOF */
              break;
            }
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
  if (cksum[0] != cksum [1])
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
check_deletion (dlist_t * list, size_t elements)
{
  int deleted;			/* Number of elements deleted */
  int *item;			/* Item deleted from the list */
  int rc;			/* General error handling variable */
  register int i;		/* A simple iterator */

  /* Initializations */
  deleted = 0x0;
  i = 0x0;

  /* Deletes the head of the list */
  rc = dlist_move (list, POS_HEAD);
  if (rc)
    {
      ERROR (TEST, "dlist_move", rc);
      return EFAILED;
    }
  rc = dlist_del (list, (void **) &item, POS_CURR);
  if (rc)
    {
      ERROR (TEST, "dlist_del", rc);
      return EFAILED;
    }
  ++deleted;
  /* Moves to the head of the list */
  rc = dlist_move (list, POS_HEAD);
  if (rc)
    {
      ERROR (TEST, "dlist_move", rc);
      return EFAILED;
    }
  /* Moves to somewhere in the middle of the list */
  for (i = 0; i < elements / 2; ++i)
    {
      rc = dlist_move (list, POS_NEXT);
      if (rc)
        {
          ERROR (TEST, "dlist_move", rc);
          return EFAILED;
        }
    }
  /* Deletes an item at somewhere in the middle of the list */
  rc = dlist_del (list, (void **) &item, POS_NEXT);
  if (rc)
    {
      ERROR (TEST, "dlist_del", rc);
      return EFAILED;
    }
  ++deleted;
  /* Deletes the tail of the list */
  rc = dlist_move (list, POS_TAIL);
  if (rc)
    {
      ERROR (TEST, "dlist_move", rc);
      return EFAILED;
    }
  rc = dlist_del (list, (void **) NULL, POS_CURR);
  if (rc)
    {
      ERROR (TEST, "dlist_del", rc);
      return EFAILED;
    }
  ++deleted;
  /* Check for inconsistencies */
  if (elements - deleted != descriptor_size (list))
    {
      ERROR (TEST, "Number of elements mismatch for deletion", ECKFAIL);
      return EFAILED;
    }
  return 0x0;
}

static int check_uninitialized (dlist_t * dlist)
{
  int rc;
  int test_status = 0x0;
  void * buf = NULL;

  rc = dlist_destroy (dlist);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dlist_destroy", rc);
      test_status = EFAILED;      
    }
  rc = dlist_get (dlist, &buf, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dlist_get", rc);
      test_status = EFAILED;      
    }
  rc = dlist_insert (dlist, buf, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dlist_insert", rc);
      test_status = EFAILED;      
    }
  rc = dlist_move (dlist, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dlist_move", rc);
      test_status = EFAILED;      
    }
  rc = dlist_del (dlist, &buf, POS_HEAD);
  if (rc != EGAINVAL)
    {
      ERROR (TEST, "dlist_del", rc);
      test_status = EFAILED;      
    }
  return test_status;
}

/* Increments the position represented by whence */
static position_t next_position (position_t whence)
{
  switch (whence)
    {
        case POS_NONE:
          return POS_HEAD;
        case POS_HEAD:
          return POS_TAIL;
        case POS_TAIL:
          return POS_NEXT;
        case POS_NEXT:
          return POS_CURR;
        case POS_CURR:
          return POS_PREV;
    }
  /* Cycles the position */
  return POS_NONE;
}
