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
 $Id: ivector.c,v 1.4 2005-01-09 12:30:21 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "ivector.h"

/*
 * Local macros
 */
#define TEST "IVECTOR"

/*
 * Local prototypes
 */
static int compare (const void *, const void *);
static int load_ivector (ivector_t *, size_t);
static int check_del (ivector_t *);

/*
 * Exported functions
 */
int
test_ivector (void)
{
  ivector_t * ivector;          /* Infinite vector descriptor */
  int rc;                       /* General error handling variable */
  int * buffer;                 /* Buffer to hold data */
  int key;                      /* Search key */

  /* Allocates the whole vector */
  rc = ivector_alloc (&ivector, compare, free, sizeof (int));
  if (rc)
  {
    ERROR (TEST, "ivector_alloc", rc);
    return EFAILED;
  }
  rc = load_ivector (ivector, MAX_ELEMENTS);
  if (rc)
  {
    ERROR (TEST, "ivector load error", ECKFAIL);
    return EFAILED;
  }  
  /* Re-orders the list */
  rc = ivector_qsort (ivector);
  if (rc)
  {
    ERROR (TEST, "ivector_qsort", rc);
    return EFAILED;
  }
  /* Searches for something */
  key = MAX_ELEMENTS / 2;
  rc = ivector_bsearch (ivector, &buffer, &key);
  if (rc)
  {
    ERROR (TEST, "ivector_bsearch", rc);
    return EFAILED;
  }
  /* Puts something using an index */
  key /= 2;
  rc = ivector_put (ivector, MAX_ELEMENTS / 2, &key);
  if (rc)
  {
    ERROR (TEST, "ivector_put", rc);
    return EFAILED;
  }
  /* Check deletions */
  rc = check_del (ivector);
  if (rc)
  {
    ERROR (TEST, "check_del", ECKFAIL);
    return EFAILED;
  }
  /* Deallocates the vector */
  rc = ivector_free (&ivector);
  if (rc)
  {
    ERROR (TEST, "ivector_free", rc);
    return EFAILED;
  }
  return 0x0;
}

/* Compare function for the infinite vector */
static int compare (const void * arg1, const void * arg2)
{
  int * v1 = (int *) arg1;
  int * v2 = (int *) arg2;

  return *v1 > *v2;
}

/* Loads data into the infinite vector */
static int
load_ivector (ivector_t * ivector, size_t elements)
{
  register int i;               /* General iterator */

  for (i = elements - 1; i > -1; --i)
  {
    int buffer;              /* Data buffer to load into the vector */
    int rc;                     /* General error handling variable */
    
    /* Loads data into the buffer */
    buffer = i + 1;
    /* Adds data to the vector */
    rc = ivector_add (ivector, (void *) & buffer);
    if (rc)
    {
      ERROR (TEST, "ivector_add", rc);
      return EFAILED;
    }
  }
  return 0x0;
}

/* Checks deletions */
static int
check_del (ivector_t * ivector)
{
  int rc;                       /* General error handling variable */

  /* Deletes something */
  rc = ivector_del (ivector, MAX_ELEMENTS / 2);
  if (rc)
  {
    ERROR (TEST, "ivector_del", rc);
    return EFAILED;
  }
  /* Deletes the first element */
  rc = ivector_del (ivector, 0x0);
  if (rc)
  {
    ERROR (TEST, "ivector_del", rc);
    return EFAILED;
  }
  /* Deletes the last element */
  rc = ivector_del (ivector, descriptor_size(ivector));
  if (rc)
  {
    ERROR (TEST, "ivector_del", rc);
    return EFAILED;
  }
  
  return 0x0;
}
