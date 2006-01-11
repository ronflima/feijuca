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

 Description: Determines the size of an ivector

 CVS Information
 $Author: harq_al_ada $
 $Id: ivector_size.c,v 1.1 2006-01-10 09:53:09 harq_al_ada Exp $
*/
#include <stddef.h>
#include <assert.h>
#include "gacommon.h"
#include "ivector.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: ivector_size.c,v 1.1 2006-01-10 09:53:09 harq_al_ada Exp $";

int
ivector_size (ivector_t * vector, size_t * size)
{
  assert (vector != NULL);
  assert (size != NULL);
  if (vector == NULL || size == NULL)
    {
      return EGAINVAL;
    }
  CHECK_SIGNATURE (vector, GA_IVECTOR_SIGNATURE);
  *size = vector->size_;
  return 0x0;
}