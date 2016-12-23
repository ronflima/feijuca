/* -*-c-*-
   Copyright (c) 2016 Ronaldo Faria Lima
   
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
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
