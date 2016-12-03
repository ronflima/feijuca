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

 Description: Gets the current element of the list and iterates to the
 next one
*/
#include <assert.h>
#include "fjc_dclist.h"
#include "fjc_dclist_.h"

fjc_error_t
fjc_dclist_get (fjc_dclist_t dclist, void **data, fjc_position_t whence)
{
  assert (dclist != NULL);
  assert (data != NULL);
  if (dclist == NULL || data == NULL)
    {
      return E_FJC_INVAL;
    }
  CHECK_SIGNATURE (dclist, FJC_DCLIST_SIGNATURE);
  *data = (void *)fjc_dlist_get (dclist->list_, whence);
  return E_FJC_OK;
}
