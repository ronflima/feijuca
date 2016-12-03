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

 Description: Internal header file for fjc_queues. This file is intended
 to be used only for g.a. library compilation and should not be
 installed on the final target system.

 CVS Information
 $Author: harq_al_ada $
 $Id: fjc_queue_.h,v 1.4 2007-06-24 23:57:17 harq_al_ada Exp $
*/

#ifndef FJC_QUEUE__H
#define FJC_QUEUE__H

#include <stddef.h>
#include "fjc_common.h"
#include "fjc_list.h"

FJC_BEGINDECLS
/*
 * Constants
 */
enum
{
  FJC_QUEUE_SIGNATURE=(fjc_magic_t)0xFADEDEADu
};

/*
 * Datatypes
 */
struct fjc_queue_t
{
  fjc_magic_t signature_;
  fjc_list_t list_;
};

/*
 * Methods
 */
int (fjc_queue_is_valid_) __P((fjc_queue_t));
int (fjc_queue_get_list_) __P((fjc_queue_t, fjc_list_t *));
int (fjc_queue_set_list_) __P((fjc_queue_t, fjc_list_t));

FJC_ENDDECLS
#endif /* FJC_QUEUE__H */
