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
 $Id: clist.h,v 1.1 2004-03-30 11:29:31 ron_lima Exp $
*/
 
#ifndef CLIST_H
#define CLIST_H

#include <stdio.h>
#include "list.h"
#include "gacommon.h"

/*
 * Datatypes
 */

/* Abstraction for the list descriptor */
typedef list_element_t clist_element_t; /* List element */
typedef list_t         clist_t;         /* List descriptor */

/* 
 * Prototypes 
 */

/* Masked functions */
#define clist_alloc(list, dealloc)    list_alloc((list_t **)list, dealloc)
#define clist_free(list)              list_free ((list_t **)list)
#define clist_del(list, data)         list_del  ((list_t *) list, data)
#define clist_get(list, data, whence) list_get  ((list_t *) list, data, whence)
#define clist_move(list, whence)      list_move ((list_t *) list, whence)
/* Real functions */
extern int 
clist_insert (clist_t * list, const void *data);

#endif /* CLIST_H */
