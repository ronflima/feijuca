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

 Description: Moves the iterator to the next item of the list. Do not
 update the list current item.

 CVS Information
 $Author: ron_lima $
 $Id: list_imove.c,v 1.1 2004-03-19 11:13:47 ron_lima Exp $
*/
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

LIST_ITERATOR *
list_imove (LIST_ITERATOR * iterator)
{
    assert (iterator != NULL);
    iterator = iterator->next_;
    return iterator;
}
