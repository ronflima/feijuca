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

 Description: Gets the current element of the list and iterates to the
 next one

 CVS Information
 $Author: ron_lima $
 $Id: dlist_get.c,v 1.6 2004-05-25 11:08:53 ron_lima Exp $
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

int 
dlist_get (dlist_t * list, void **data, position_t whence)
{
    if (! list->curr_)
        {
            return EOF;
        }
    *data = list->curr_->data_;
    switch (whence)
        {
        case CURR: 
            /* Used only for parameter checking */
            break;
        case NEXT:                  /* Moves to the next element */
        case PREV:                  /* Moves to the previous element */
            return dlist_move (list, whence);
            break;
        default:                    /* Invalid parameter provided */
            errno = EINVAL;
            return -1;
        }
    return 0;
}
