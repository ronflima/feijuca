/* -*-c-*-
 Copyright Ronaldo Faria Lima (C) 2004 - All rights reserved
 Feel free to contact the author in <ronaldo@ronaldolima.eti.br>

 This file is part of [SYSTEM].

 [SYSTEM] is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 [SYSTEM] is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with [SYSTEM]; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 System: G.A. Lib

 Description: Allocates and initializes the list

 CVS Information
 $Author: ron_lima $
 $Id: list_alloc.c,v 1.1 2004-02-29 10:30:55 ron_lima Exp $
*/
#include <errno.h>
#include <stdlib.h>
#include "list.h"

int
list_alloc (LIST ** list, deallocator_t dealloc)
{
  /* Allocates memory for the list structure */
  *list = (LIST *) malloc (sizeof (LIST));
  if(! *list)
    {
      errno = ENOMEM;
      return -1;
    }

  (*list)->size_        = 0x0;
  (*list)->head_        = (LIST_ELEMENT *) 0x0;
  (*list)->tail_        = (LIST_ELEMENT *) 0x0;
  (*list)->curr_        = (LIST_ELEMENT *) 0x0;
  (*list)->deallocator_ = dealloc;

  /* The deallocator must be always provided */
  if(! (*list)->deallocator_)
    {
      errno = EINVAL;
      free (*list);
      *list = (LIST *) 0x0;
      return -1;
    }
  return 0x0;
}
