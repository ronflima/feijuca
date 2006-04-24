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
 along with G.A. Lib; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  System: G.A. Lib

  Description: Checks the signature of a list descriptor for
  validity. This is an internal function.

 CVS Information $Author: daniel_csoares $ $Id: list_del.c,v 1.7 2004/07/19 00:53:45
 ron_lima Exp $
 */
#include <stdio.h>
#include "queue.h"
#include "queue_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: queue_is_valid_.c,v 1.1 2006-04-24 12:39:18 daniel_csoares Exp $";

int 
queue_is_valid_ (queue_t queue)
{
  int rc=0x1;

  if (queue == NULL) 
    {
      rc = 0x0;
    }
  else if (queue->signature_ != GA_QUEUE_SIGNATURE)
    {
      rc = 0x0;
    }
  return rc;
}
