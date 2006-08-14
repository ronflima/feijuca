/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This library is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as
 published by the Free Software Foundation; either version 2.1 of the
 License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
 USA

 System: G.A. Lib

 Description: Test scenario engine. Executes several test scenarios at
 once

 CVS Information
 $Author: harq_al_ada $
 $Id: engine.c,v 1.4 2006-08-14 00:16:52 harq_al_ada Exp $
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gatests.h"
#include "list.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: engine.c,v 1.4 2006-08-14 00:16:52 harq_al_ada Exp $";

GAERROR
execute_scenarios (const char * test_name, size_t maxelements, 
                   scenario_t scenarios [], size_t size)
{
  GAERROR rc = EGAOK;
  register int i;

  for (i=0; i < (size/sizeof (scenario_t)); ++i) 
    {
      rc = scenarios[i].routine (maxelements);
      if (rc != EGAOK)
        {
          ERROR (test_name, scenarios[i].name, rc);
          break;
        }
    }
  return rc;
}
