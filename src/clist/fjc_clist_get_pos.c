/* -*-c-*-
 Feijuca Library - A generic algorithms and data structures library
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

 System: Feijuca Lib

 Description: This function is a wrapper to list_get_pos since that list function is
 suitable for this functionality and can be used without any problem.
*/
#include <assert.h>
#include "fjc_list.h"
#include "fjc_clist.h"


fjc_error_t
fjc_clist_get_pos (fjc_clist_t clist, fjc_position_t *pos)
{
  assert (clist != NULL);
  assert (pos != NULL);
  if (clist == NULL || pos == NULL)
    {
      return E_FJC_INVAL;
    }
  return fjc_list_get_pos ((fjc_list_t) clist, pos);
}
