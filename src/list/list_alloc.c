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

 Description: Allocates and initializes the list

 CVS Information
 $Author: ron_lima $
 $Id: list_alloc.c,v 1.4 2004-03-26 11:14:02 ron_lima Exp $
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int
list_alloc (list_t ** list, deallocator_t dealloc)
{
    /* The deallocator must be always provided */
    if(! dealloc)
        {
            errno = EINVAL;
            return -1;
        }
    /* Allocates memory for the list structure */
    *list = (list_t *) malloc (sizeof (list_t));
    if(! *list)
        {
            errno = ENOMEM;
            return -1;
        }
    /* Initializes each data member */
    (*list)->size_        = 0x0;
    (*list)->head_        = (list_element_t *) NULL;
    (*list)->tail_        = (list_element_t *) NULL;
    (*list)->curr_        = (list_element_t *) NULL;
    (*list)->deallocator_ = dealloc;
    return 0x0;
}
