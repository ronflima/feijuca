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

 Description: Adds a new element at the end of the vector

 CVS Information
 $Author: ron_lima $
 $Id: ivector_add.c,v 1.2 2004-04-04 11:39:17 ron_lima Exp $
*/
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "ivector.h"

int 
ivector_add (ivector_t * vector, const void * data)
{
    void * v;                   /* New redimensioned vector */
    v = realloc (vector->data_, vector->datalen_ * (vector->size_ + 1));
    if (!v)
        {
            errno = ENOMEM;
            return -1;
        }
    vector->data_ = v;
    /* Moves v to the newly created entry */
    v = (void *)((char *) v + vector->size_ * vector->datalen_);
    /* Copies data into the new element */
    memcpy (v, data, vector->datalen_);
    vector->size_++;
    return 0x0;
}