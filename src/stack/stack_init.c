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

 Description: Allocates and initializes a stack

 CVS Information
 $Author: harq_al_ada $
 $Id: stack_init.c,v 1.6 2006-01-29 12:37:05 harq_al_ada Exp $
*/
#include <assert.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"
#include "stack_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: stack_init.c,v 1.6 2006-01-29 12:37:05 harq_al_ada Exp $";

int
stack_init (stack_t * stack, deallocator_t * dealloc)
{
  int rc = 0x0;

  assert (stack != NULL);
  assert (dealloc != NULL);
  if (stack == NULL || dealloc == NULL)
    {
      rc = EGAINVAL;
    }
  else if ((*stack = (stack_t) malloc (sizeof (struct stack_t))) == NULL)
    {
      rc = EGANOMEM;
    }
  else 
    {
      (*stack)->signature_ = GA_STACK_SIGNATURE;
      if (((*stack)->list_ = list_init (dealloc)) == NULL)
        {
          free (*stack);
        }
    }
  return rc;
}
