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

  Description: Element manipulator. Gets the data that is encapsulated
  inside the element. This function is internal to the library.

 CVS Information $Author: harq_al_ada $ $Id: list_del.c,v 1.7 2004/07/19 00:53:45
 ron_lima Exp $
 */
#include <assert.h>
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_element_get_data_.c,v 1.3 2006-05-15 10:56:21 harq_al_ada Exp $";

GAERROR
list_element_get_data_ (list_element_t element, void ** data)
{
  assert (element != NULL);
  assert (data != NULL);

  if ((element == NULL) || (data == NULL))
    {
      return EGAINVAL;
    }
  *data = (void *) element->data_;

  return EGAOK;
}
