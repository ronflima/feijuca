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

 Description: Interfaces and datatypes for double-linked circular lists.
 
 CVS Information
 $Author: daniel_csoares $
 $Id: dclist.h,v 1.1 2005-10-05 12:17:51 daniel_csoares Exp $
*/

#ifndef DCLIST_H
#define DCLIST_H

#include <stdio.h>
#include "gacommon.h"
#include "dlist.h"

GABEGINDECLS
/*
 * Datatypes
 */
typedef dlist_t dclist_t;

/*
 * Prototypes
 */
int (dclist_init) __P ((dclist_t *, deallocator_t *));
int (dclist_destroy) __P ((dclist_t *));
int (dclist_get) __P ((dclist_t *, void **, position_t));
int (dclist_insert) __P ((dclist_t *, const void *, position_t));
int (dclist_move) __P ((dclist_t *, position_t));
int (dclist_del) __P ((dclist_t *, void **, position_t));

GAENDDECLS
#endif /* DCLIST_H */
