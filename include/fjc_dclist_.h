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
 $Id: dclist_.h,v 1.3 2007-06-24 23:57:17 harq_al_ada Exp $
*/

#ifndef FJC_DCLIST__H
#define FJC_DCLIST__H

#include "fjc_common.h"
#include "fjc_dlist.h"
#include "fjc_dclist.h"

FJC_BEGINDECLS

/*
 * Constants
 */
enum 
{
  FJC_DCLIST_SIGNATURE = 0x5EEDDEAFu
};

/*
 * Datatypes
 */
struct fjc_dclist_t
{
  fjc_magic_t signature_;
  fjc_dlist_t list_;
};

/*
 * Prototypes
 */
fjc_error_t (fjc_dclist_make_circular_) (fjc_dclist_t);

FJC_ENDDECLS
#endif /* FJC_DCLIST__H */
