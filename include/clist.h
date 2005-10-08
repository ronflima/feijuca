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
 $Id: clist.h,v 1.12 2005-10-08 20:25:00 ron_lima Exp $
*/

#ifndef CLIST_H
#define CLIST_H

#include <stdio.h>
#include "list.h"
#include "gacommon.h"

GABEGINDECLS
/*
 * Constants
 */
enum
{
  GA_CLIST_SIGNATURE=(ga_magic_t)0xB00BD00Du
};

/*
 * Datatypes
 */
/* Abstraction for the list descriptor */
typedef struct clist_t
{
  ga_magic_t signature_;
  list_t list_;
} clist_t;

/*
 * Prototypes
 */
int (clist_init) __P ((clist_t *, deallocator_t *));
int (clist_destroy) __P ((clist_t *));
int (clist_del) __P ((clist_t *, void **));
int (clist_get) __P ((clist_t *, void **, position_t));
int (clist_move) __P ((clist_t *, position_t));
int (clist_insert) __P ((clist_t *, const void *));

GAENDDECLS
#endif /* CLIST_H */
