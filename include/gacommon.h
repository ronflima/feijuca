/* -*-c-*-
   Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
   Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

   This file is part of G.A. Lib.

   G.A. Lib is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   G.A. Lib is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with G.A. Lib; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

   System: G.A. Lib

   Description: Common declarations used by G.A. Library. This is
   intended to be an internal header file that should not be included
   directly by your application.

   CVS Information
   $Author: ron_lima $
   $Id: gacommon.h,v 1.18 2005-01-19 23:55:47 ron_lima Exp $
*/

#ifndef GACOMMON_H
#define GACOMMON_H

/*
 * Macros
 */
/* Declaration handles for C++ compilations - Simplifies the syntax */
#if defined (__cplusplus) || defined (c_plusplus)
#define GABEGINDECLS extern "C" {
#define GAENDDECLS }
#else
#define GABEGINDECLS
#define GAENDDECLS
#endif

/* Prototypation handle - It is used to let K&R compilers to compile
   and use the library */
#ifndef __P
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
#define __P(prototype) prototype
#else
#define __P(prototype) ()
#endif
#endif

/* Error codes: Errors that are returned from G.A. Library
   routines. */
#define EGAINVAL 2500		/* Invalid argument */
#define EGANOMEM 2501		/* No memory */
#define EGABADC  2502		/* Bad current position */

/* Simple information getters */
#define descriptor_size(list) (list)->size_

GABEGINDECLS
/*
 * Datatypes
 */
/* List iteration types */
typedef enum
{
  HEAD = 0x0,
  TAIL,
  NEXT,
  CURR,
  PREV
}
position_t;

/* Deallocator function pointer type */
typedef void (deallocator_t) (void *);
/* Comparison function pointer type */
typedef int (compare_t) (const void *, const void *);

GAENDDECLS
#endif /* GACOMMON_H */
