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

 Description: Test scenario engine. Executes several test scenarios at
 once

 CVS Information
 $Author: ron_lima $
 $Id: engine.c,v 1.2 2005-09-01 10:52:01 ron_lima Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: engine.c,v 1.2 2005-09-01 10:52:01 ron_lima Exp $";

int
execute_scenarios (const char * test_name, size_t maxelements, 
                   scenario_t scenarios [], size_t size)
{
  int rc = 0x0;
  register int i;

  for (i=0; i < (size/sizeof (scenario_t)); ++i) 
    {
      rc = scenarios[i].routine (maxelements);
      if (rc != 0x0)
        {
          ERROR (test_name, scenarios[i].name, rc);
          break;
        }
    }
  return rc;
}
