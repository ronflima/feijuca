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

 Description: Test suite routines for deques.

 CVS Information
 $Author: harq_al_ada $
 $Id: deque.c,v 1.6 2006-01-29 19:24:13 harq_al_ada Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "gacommon.h"
#include "deque.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: deque.c,v 1.6 2006-01-29 19:24:13 harq_al_ada Exp $";

/*
 * Local macros
 */
#define TEST "DEQUE"

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
static int check_deque_push (size_t);
static int check_deque_pop (size_t);

/*
 * Exported functions
 */
int
test_deque (size_t maxelements)
{
  int rc = 0x0;
  register int i;
  scenario_t scenarios [] = {
    {"Deque pushing test", check_deque_push},
    {"Deque popping test", check_deque_pop }
  };

  return execute_scenarios (TEST, maxelements, scenarios, sizeof (scenarios));
}

/* 
 * Utility function: loads a deque 
 */
static int
load_deque (deque_t deque, size_t elements, unsigned char use_pattern, position_t whence)
{
  register int i;		/* General purpose iterator */

  for (i = 0x0; i < elements; ++i)
    {
      unsigned int *item;       /* Item to insert */
      int rc;

      item = (int *) malloc (sizeof (unsigned int));
      if (item == NULL)
        {
          ERROR (TEST, "malloc", ECKFAIL);
          return ENOMEM;
        }
      if (use_pattern == '\x1')
        {
          *item = PATTERN;
        }
      else 
        {
          *item = i + 1;
        }
      if ((rc = deque_push (deque, item, whence)) != 0x0)
        {
          ERROR (TEST, "deque_push", rc);
          return EFAILED;
        }
    }

  return 0x0;
}

/*
 * Scenario 1: Checks deque pushing
 */
static int
check_deque_push (size_t elements)
{
  int status;
  int rc;
  deque_t deque;

  status = 0x0;

  if ((rc = deque_init (&deque, free)) != 0x0)
    {
      ERROR (TEST, "deque_init", rc);
      status = EFAILED;
    }
  else if ((rc = load_deque (deque, elements, POS_HEAD, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_deque", rc);
      status = EFAILED;
    }
  else if ((rc = load_deque (deque, elements, POS_TAIL, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_deque", rc);
      status = EFAILED;
    }
  if ((rc = deque_destroy (deque)) != 0x0)
    {
      ERROR (TEST, "deque_destroy", rc);
      status = EFAILED;
    }

  return status;
}

/* 
 * Scenario 2: Checks the pop operation from the deque 
 */
static int
check_deque_pop (size_t elements)
{
  int rc;
  int status;
  deque_t deque;

  status = 0x0;
  if ((rc = deque_init (&deque, free)) != 0x0)
    {
      ERROR (TEST, "deque_init", rc);
      status = EFAILED;
    }
  else if ((rc = load_deque (deque, elements, POS_HEAD, '\x1')) != 0x0)
    {
      ERROR (TEST, "load_deque", rc);
      status = EFAILED;
    }
  else 
    {
      int * buf;
      position_t pos;

      pos = POS_HEAD;
      while ((rc = deque_pop (deque, (void **) &buf, pos)) == 0x0)
        {
          if (buf == NULL)
            {
              ERROR (TEST, "Null popped data found", ECKFAIL);
              status = EFAILED;
              break;
            }
          else 
            {
              free (buf);
              if (pos == POS_HEAD)
                {
                  pos = POS_TAIL;
                }
              else
                {
                  pos = POS_HEAD;
                }
            }
        }
    }
  if ((rc = deque_destroy (deque)) != 0x0)
    {
      ERROR (TEST, "deque_destroy", rc);
      status = EFAILED;
    }
  return 0x0;

}
