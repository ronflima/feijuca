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

 Description: Internal definitions for fjc_stack routines. This header
 file is intended to be used only for g.a. library compilation.

 CVS Information
 $Author: harq_al_ada $
 $Id: fjc_stack_.h,v 1.2 2007-06-24 23:57:17 harq_al_ada Exp $
*/

#ifndef FJC_STACK__H
#define FJC_STACK__H

#include <stddef.h>
#include "fjc_common.h"
#include "fjc_list.h"

FJC_BEGINDECLS

/*
 * Constants
 */
enum
{
  FJC_STACK_SIGNATURE=(fjc_magic_t)0xFADEBAD5u
};

/*
 * Datatypes
 */
struct fjc_stack_t
{
  fjc_magic_t signature_;
  fjc_list_t list_;
};

FJC_ENDDECLS
#endif /* FJC_STACK__H */
