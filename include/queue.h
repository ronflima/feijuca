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

 Description: Interfaces and datatypes for queues

 CVS Information
 $Author: ron_lima $
 $Id: queue.h,v 1.1 2004-05-03 00:25:07 ron_lima Exp $
*/
 
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "gacommon.h"
#include "list.h"

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Datatypes
 */
typedef list_t queue_t;

/* 
 * Prototypes 
 */
extern int
(queue_alloc) (queue_t ** queue, deallocator_t dealloc);
extern int
(queue_free) (queue_t ** queue);
extern int
(queue_dequeue) (queue_t * queue, void **data);
extern int 
(queue_queue) (queue_t * queue, const void *data);
#ifdef __cplusplus
}
#endif
#endif /* QUEUE_H */
