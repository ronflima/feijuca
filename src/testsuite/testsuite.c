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

 Description: Entry point to the test suite for G.A. Library

 CVS Information
 $Author: ron_lima $
 $Id: testsuite.c,v 1.5 2004-10-20 10:38:30 ron_lima Exp $
*/

#include <stdio.h>
#include "gatests.h"

int
main (int argc, char **argv)
{
  register int i;		/* Simple iterator */
  test_t tests[] =		/* Vector containing all tests to be done */
  {
    {"List Test", test_list},
    {"DList Test", test_dlist},
    {"Stack Test", test_stack}
  };

  for (i = 0x0; i < sizeof (tests) / sizeof (test_t); ++i)
  {
    int errors;			/* Errors detected */

    /* Performs each test */
    printf ("Performing %s\n", tests[i].test_name);
    errors = tests[i].test_routine ();
    printf ("Found %d error(s) for %s. Test %s.\n", errors,
        tests[i].test_name, errors ? "failed" : "passed");
  }
  return 0;
}
