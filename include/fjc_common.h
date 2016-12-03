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
 $Author: harq_al_ada $
 $Id: gacommon.h,v 1.30 2006-07-21 13:35:58 harq_al_ada Exp $
*/

#ifndef FJC_COMMON_H
#define FJC_COMMON_H

/*
 * Macros
 */
/* Declaration handles for C++ compilations - Simplifies the syntax */
#if defined (__cplusplus) || defined (c_plusplus)
#define FJC_BEGINDECLS extern "C" {
#define FJC_ENDDECLS }
#else
#define FJC_BEGINDECLS
#define FJC_ENDDECLS
#endif

FJC_BEGINDECLS
/* Prototypation handle - It is used to let K&R compilers to compile
   and use the library */
#ifndef __P
#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
#define __P(prototype) prototype
#else
#define __P(prototype) ()
#endif
#endif

/*
 * Constants
 */
/* Error codes: Errors that are returned from G.A. Library
   routines. */
typedef enum 
{
  E_FJC_OK    = 0x0,        /* No error so far. */
  E_FJC_EOF   = -0x1,       /* End of file */
  E_FJC_INVAL = 2500,		/* Invalid argument */
  E_FJC_NOMEM = 2501,		/* No memory */
  E_FJC_BADC  = 2502		/* Bad current position */
} fjc_error_t;

/*
 * Datatypes
 */
/* List iteration types */
typedef enum
{
  POS_FJC_NONE = 0x0,   /* No position - dummy value */
  POS_FJC_HEAD,			/* Head */
  POS_FJC_TAIL,			/* Tail */
  POS_FJC_NEXT,			/* Next element  */
  POS_FJC_CURR,			/* Current element */
  POS_FJC_PREV,			/* Previous element */
  POS_FJC_MID           /* Somewhere between the head or tail */
}
fjc_position_t;

/* Deallocator function pointer type */
typedef void (fjc_deallocator_t) (void *);
/* Comparison function pointer type */
typedef int (fjc_compare_t) (const void *, const void *);
/* Magic number data type */
typedef unsigned int fjc_magic_t;

FJC_ENDDECLS
#endif /* FJC_COMMON_H */
