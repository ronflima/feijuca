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

 Description: Entry point to the test suite for G.A. Library. This
 test suite is not intended to be a testing software for the
 library. The main idea here is to have a minimum application to debug
 the library. Running this program will not guarantee that the library
 is free of bugs. Debugging the library inside a debugger will. :)

 CVS Information
 $Author: ron_lima $
 $Id: testsuite.c,v 1.9 2005-01-24 09:33:09 ron_lima Exp $
*/

#include <stdio.h>
#include "gatests.h"

int
main (int argc, char **argv)
{
  register int i;               /* Simple iterator */
  size_t maxelements;           /* Maximum number of elements to load */
  test_t tests[] =        /* Vector containing all tests to be done */
  {
    {"LIST", test_list},
    {"DLIST", test_dlist},
    {"STACK", test_stack},
    {"CLIST", test_clist},
    {"QUEUE", test_queue},
    {"IVECTOR", test_ivector}
  };

  /* Initializations */
  maxelements = MAX_ELEMENTS;

  /* Prints a small friendly message */
  printf ("G.A. Library Test Suite\n(c) 2004 - Ronaldo Faria Lima\n");
  printf ("This software is licensed under the Gnu Public License\n\n");

  /* Performs all tests at once */
  for (i = 0x0; i < sizeof (tests) / sizeof (test_t); ++i)
    {
      int rc;			/* Error handling */
      char *result;		/* Test result */

      /* Performs each test */
      printf ("[%-7s] Performing test...\n", tests[i].test_name);
      rc = tests[i].test_routine (maxelements);
      switch (rc)
        {
        case 0x0:		/* Successful test */
          result = "SUCESSFUL";
          break;

        case ENOTIMP:		/* Test not implemented yet */
          result = "This test is not implemented yet";
          break;

        default:		/* Failure */
          result = "FAILED";
        }
      printf ("\tTest result: %s.\n", result);
    }
  return 0;
}
