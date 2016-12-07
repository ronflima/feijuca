/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This is contributed code by Daniel Costa Soares
 <daniel_csoares@yahoo.com.br>

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

 Description: Inserts a new element in the dclist given a position
*/
#include <assert.h>
#include "fjc_dclist.h"
#include "fjc_dclist_.h"

fjc_error_t
fjc_dclist_insert (fjc_dclist_t dclist, const void *data, fjc_position_t whence)
{
  fjc_error_t rc = E_FJC_OK;

  assert (dclist != NULL);
  if (dclist == NULL)
    {
      return E_FJC_INVAL;
    }
  if (dclist->signature_ != FJC_DCLIST_SIGNATURE)
    {
      return E_FJC_INVAL;
    }
  if ((rc = fjc_dlist_insert (dclist->list_, data, whence)) == E_FJC_OK)
    {
      /* Makes list circular again, since dlist_insert will ignore
       * this fact when operation on the head or tail. */
      fjc_dclist_make_circular_ (dclist);
    }
  return rc;
}
