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

 Description: Inserts a new element in the list

 CVS Information
 $Author: ron_lima $
 $Id: clist_insert.c,v 1.2 2004-04-11 12:16:01 ron_lima Exp $
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

int 
clist_insert (clist_t * list, const void *data)
{
    clist_element_t * element;

    /* Allocates memory for the new element */
    element = (clist_element_t *) malloc (sizeof (clist_element_t));
    if (! element)
        {
            errno = ENOMEM;
            return -1;
        }
    element->data_ = (void *) data;
    element->next_ = (clist_element_t *) NULL;
    /* Check the size of the list */
    if (! list->size_)
        {
            /* This is the head of the list */
            list->head_ = element;
            list->tail_ = element;
        }
    else
        {
            /* Insert at the end */
            list->tail_->next_ = element;
            list->tail_        = element;
        }
    /* Makes the circular link in the list */
    list->tail_->next_ = list->head_;
    list->curr_ = element;
    list->size_++;
    return 0;
}
