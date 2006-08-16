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

 Description: Internal header file for circular lists. This is the
 definition module for circular lists. This header file is used only
 for g.a. library compilation.

 CVS Information
 $Author: harq_al_ada $
 $Id: clist_.h,v 1.4 2006-08-16 10:14:35 harq_al_ada Exp $
*/
#ifndef CLIST__H
#define CLIST__H

#include <stddef.h>
#include "list.h"
#include "gacommon.h"
#include "gainternal_.h"

GABEGINDECLS
/*
 * Constants
 */
enum
{
  GA_CLIST_SIGNATURE=(ga_magic_t)0xB00BD00Du /* clist signature for validity checks */
};

/*
 * Datatypes
 */

/* Abstraction for the list descriptor */
struct clist_t
{
  ga_magic_t signature_; /* Descriptor signature for validity checks */
  list_t list_;          /* Internal list that holds all data */
};

/* 
 *  Prototypes
 */
int (clist_is_valid_) __P((clist_t));
GAERROR (clist_get_list_) __P((clist_t, list_t *));
GAERROR (clist_set_signature_) __P((clist_t));

GAENDDECLS
#endif /* CLIST__H */
