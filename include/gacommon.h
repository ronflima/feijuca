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

 Description: Common declarations used by G.A. Library. This is
 intended to be an internal header file that should not be included
 directly by your application.

 CVS Information
 $Author: ron_lima $
 $Id: gacommon.h,v 1.25 2005-12-13 10:18:50 ron_lima Exp $
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

GABEGINDECLS
/* Prototypation handle - It is used to let K&R compilers to compile
   and use the library */
#ifndef __P
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
#define __P(prototype) prototype
#else
#define __P(prototype) ()
#endif
#endif

/* Simple information getters */
#define descriptor_size(list) (list)->size_
/* In-line code for signature checking */
#define CHECK_SIGNATURE(descriptor, signature) \
if (descriptor->signature_!= signature) return EGAINVAL

/*
 * Constants
 */
/* Error codes: Errors that are returned from G.A. Library
   routines. */
enum 
{
  EGAINVAL = 2500,		/* Invalid argument */
  EGANOMEM = 2501,		/* No memory */
  EGABADC  = 2502		/* Bad current position */
};

/*
 * Datatypes
 */
/* List iteration types */
typedef enum
{
  POS_NONE = 0x0,		/* No position - dummy value */
  POS_HEAD,			/* Head */
  POS_TAIL,			/* Tail */
  POS_NEXT,			/* Next element  */
  POS_CURR,			/* Current element */
  POS_PREV			/* Previous element */
}
position_t;

/* Deallocator function pointer type */
typedef void (deallocator_t) (void *);
/* Comparison function pointer type */
typedef int (compare_t) (const void *, const void *);
/* Magic number data type */
typedef unsigned int ga_magic_t;


GAENDDECLS
#endif /* GACOMMON_H */
