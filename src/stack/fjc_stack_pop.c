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

 Description: Pops an element from the stack

 CVS Information
 $Author: harq_al_ada $
 $Id: stack_pop.c,v 1.15 2006-02-04 21:26:38 harq_al_ada Exp $
*/
#include <assert.h>
#include "fjc_stack.h"
#include "fjc_stack_.h"

fjc_error_t
fjc_stack_pop (fjc_stack_t stack, void **data)
{
  assert (stack != NULL);
  if (stack == NULL)
    {
      return E_FJC_INVAL;
    }
  if (stack->signature_ != FJC_STACK_SIGNATURE) 
    {
      return E_FJC_INVAL;
    }
  return fjc_list_del (stack->list_, data, POS_FJC_HEAD);
}
