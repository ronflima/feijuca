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
 $Id: gacommon.h,v 1.5 2004-04-02 10:26:13 ron_lima Exp $
*/
 
#ifndef GACOMMON_H
#define GACOMMON_H

/*
 * Macros
 */
/* Simple information getters */
#define list_size(list) (list)->size_

/*
 * Datatypes
 */
/* List iteration types */
typedef enum 
  {
    HEAD = 0,
    TAIL,
    NEXT,
    CURR,
    PREV
  } list_position_t;

/* Deallocator function pointer type */
typedef void (* deallocator_t)(void *data);
/* Comparison function pointer type */
typedef int (* compare_t)(const void * a, const void * b);

#endif /* GACOMMON_H */
