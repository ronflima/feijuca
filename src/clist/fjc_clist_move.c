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

 Description: Moves the curr_ pointer depending on the parameter of the
 list. This function is simply a wrapper to list_move since that function is
 suitable for this context.
*/
#include <assert.h>
#include "fjc_list.h"
#include "fjc_clist.h"

fjc_error_t
fjc_clist_move (fjc_clist_t clist, fjc_position_t whence)
{
  return fjc_list_move (clist, whence);
}
