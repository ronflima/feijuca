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

 Description: Internal definitions for stack routines. This header
 file is intended to be used only for g.a. library compilation.

 CVS Information
 $Author: harq_al_ada $
 $Id: stack_.h,v 1.1 2006-01-29 12:37:02 harq_al_ada Exp $
*/

#ifndef STACK__H
#define STACK__H

#include <stddef.h>
#include "gacommon.h"
#include "gainternal_.h"
#include "list.h"

GABEGINDECLS

/*
 * Constants
 */
enum
{
  GA_STACK_SIGNATURE=(ga_magic_t)0xFADEBAD5u
};

/*
 * Datatypes
 */
struct stack_t
{
  ga_magic_t signature_;
  list_t list_;
};

GAENDDECLS
#endif /* STACK__H */
