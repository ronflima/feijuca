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

 Description: Interfaces and datatypes for single linked circular lists

 CVS Information
 $Author: ron_lima $
 $Id: clist.h,v 1.4 2004-06-27 00:20:24 ron_lima Exp $
*/
 
#ifndef CLIST_H
#define CLIST_H

#include <stdio.h>
#include "list.h"
#include "gacommon.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Datatypes
 */

/* Abstraction for the list descriptor */
typedef list_element_t clist_element_t; /* List element */
typedef list_t         clist_t;         /* List descriptor */

/* 
 * Prototypes 
 */
extern int
(clist_alloc) (clist_t ** clist, deallocator_t * dealloc);
extern int
(clist_free) (clist_t ** clist);
extern int
(clist_del) (clist_t * clist, void **data);
extern int 
(clist_get) (clist_t * clist, void **data, position_t whence);
extern int
(clist_move) (clist_t * clist, position_t whence);
extern int 
(clist_insert) (clist_t * clist, const void * data);

#ifdef __cplusplus
}
#endif

#endif /* CLIST_H */
