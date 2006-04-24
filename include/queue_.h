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

 Description: Internal header file for queues. This file is intended
 to be used only for g.a. library compilation and should not be
 installed on the final target system.

 CVS Information
 $Author: daniel_csoares $
 $Id: queue_.h,v 1.2 2006-04-24 12:36:13 daniel_csoares Exp $
*/

#ifndef QUEUE__H
#define QUEUE__H

#include <stddef.h>
#include "gacommon.h"
#include "gainternal_.h"
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
struct queue_t
{
  ga_magic_t signature_;
  list_t list_;
};

/*
 * Methods
 */
int (queue_is_valid_) __P((queue_t queue));
int (queue_get_list_) __P((queue_t queue, list_t * list));

GAENDDECLS
#endif /* QUEUE__H */
