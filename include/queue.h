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
 $Id: queue.h,v 1.9 2005-10-08 20:25:00 ron_lima Exp $
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "gacommon.h"
#include "list.h"

GABEGINDECLS
/*
 * Constants
 */
enum
{
  GA_QUEUE_SIGNATURE=(ga_magic_t)0xFADEDEADu
};

/*
 * Datatypes
 */
typedef struct queue_t
{
  ga_magic_t signature_;
  list_t list_;
} queue_t;

/*
 * Prototypes
 */
int (queue_init) __P ((queue_t *, deallocator_t *));
int (queue_destroy) __P ((queue_t *));
int (queue_pop) __P ((queue_t *, void **));
int (queue_push) __P ((queue_t *, const void *));

GAENDDECLS
#endif /* QUEUE_H */
