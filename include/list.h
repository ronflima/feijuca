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

 Description: Interfaces and datatypes for single linked lists

 CVS Information
 $Author: ron_lima $
 $Id: list.h,v 1.9 2004-07-17 11:49:31 ron_lima Exp $
*/
 
#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include "gacommon.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Datatypes
 */
/* Abstraction for a single list element */
typedef struct list_element_t_
    {
        void                   * data_;
        struct list_element_t_ * next_;
    } list_element_t;

/* Abstraction for the list descriptor */
typedef struct list_t
    {
        size_t           size_;
        list_element_t * curr_;
        list_element_t * head_;
        list_element_t * tail_;
        deallocator_t  * deallocator_;
    } list_t;

/* 
 * Prototypes 
 */
extern int
(list_alloc) (list_t ** list, deallocator_t * dealloc);

extern int
(list_free) (list_t ** list);

extern int 
(list_get) (list_t * list, void **data, position_t whence);

extern int 
(list_insert) (list_t * list, const void *data);

extern int
(list_move) (list_t * list, position_t whence);

extern int
(list_del) (list_t * list, void **data);

#ifdef __cplusplus
}
#endif

#endif /* LIST_H */
