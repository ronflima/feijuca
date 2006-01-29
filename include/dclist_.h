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

 Description: This is an internal header file used for dclist
 compilation solely. The declarations here are useful only for library
 compilation. This header file should not be deployed with the library
 binaries.
 
 CVS Information
 $Author: harq_al_ada $
 $Id: dclist_.h,v 1.2 2006-01-29 19:24:13 harq_al_ada Exp $
*/

#ifndef DCLIST__H
#define DCLIST__H

#include "gacommon.h"
#include "gainternal_.h"
#include "dlist.h"
#include "dclist.h"

GABEGINDECLS
/*
 * Constants
 */
enum 
{
  GA_DCLIST_SIGNATURE = 0x5EEDDEAFu
};

/*
 * Datatypes
 */
struct dclist_t
{
  ga_magic_t signature_;
  dlist_t list_;
};

/*
 * Prototypes
 */
int (dclist_make_circular_) (dclist_t);

GAENDDECLS
#endif /* DCLIST__H */
