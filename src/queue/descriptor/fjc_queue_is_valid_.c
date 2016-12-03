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
 */
#include <stdio.h>
#include "fjc_queue.h"
#include "fjc_queue_.h"

int
fjc_queue_is_valid_ (fjc_queue_t queue)
{
  int rc = 0x1;

  if (queue == NULL) 
    {
      rc = 0x0;
    }
  else if (queue->signature_ != FJC_QUEUE_SIGNATURE)
    {
      rc = 0x0;
    }
  return rc;
}
