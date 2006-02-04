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

 Description: Iternal declarations used by G.A. Library. This header
 file is intended to be used to compile the library.

 CVS Information
 $Author: harq_al_ada $
 $Id: gainternal_.h,v 1.1 2006-01-26 10:18:13 harq_al_ada Exp $
*/

#ifndef GAINTERNAL_H
#define GAINTERNAL_H

#include "gacommon.h"

/*
 * Macros
 */

GABEGINDECLS
/* In-line code for signature checking */
#define CHECK_SIGNATURE(descriptor, signature) \
if (descriptor->signature_!= signature) return EGAINVAL

GAENDDECLS
#endif /* GACOMMON_H */