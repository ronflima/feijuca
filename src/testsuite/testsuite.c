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
 $Id: testsuite.c,v 1.17 2005-07-29 02:44:43 ron_lima Exp $
*/

/*
 * Includes
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "gacommon.h"
#include "gatests.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: testsuite.c,v 1.17 2005-07-29 02:44:43 ron_lima Exp $";

/*
 * Local functions prototypes
 */
static int cmdline_parse __P((cmdline_t *, const int, const char **));
static int cmdline_value_getint __P((int *, cmdline_t *, const char *));
static int cmdline_parameter_provided __P((const cmdline_t *, const char *));
static void help __P((void));

/*
 * Exported functions definitions
 */
int
main (int argc, char **argv)
{
  register int i;               /* Simple iterator */
  size_t maxelements;           /* Maximum number of elements to load */
  cmdline_t cmdline;            /* Command line parsed arguments */
  int rc;                       /* General return code */
  char do_test;                 /* Flag to avoid test execution */
  test_t tests[] =        /* Vector containing all tests to be done */
  {
    {"LIST", test_list},
    {"DLIST", test_dlist},
    {"STACK", test_stack},
    {"CLIST", test_clist},
    {"QUEUE", test_queue},
    {"IVECTOR", test_ivector},
    {"DEQUE", test_deque}
  };

  /* Initializations */
  maxelements = MAX_ELEMENTS;
  do_test = '\x1';

  /* Prints a small friendly message */
  printf ("\n\nG.A. Library Test Suite\n(c) 2004-2005 - Ronaldo Faria Lima\n");
  printf ("Several parts written by Daniel Costa Soares\n");
  printf ("This software is licensed under the Gnu Public License\n\n");

  /* Parses the command line */
  if (rc = cmdline_parse (&cmdline, argc, (const char **) argv))
    {
      printf ("Error parsing command line: %d\n", rc);
      return -1;
    }
  /* Checks if help was asked */
  if (cmdline_parameter_provided (&cmdline, "h"))
    {
      /* Show a small help screen */
      help ();
      do_test = '\x0';
    }

  /* Get the maximum number of elements  */
  cmdline_value_getint (&maxelements, &cmdline, "m");

  /* Performs all tests at once */
  for (i = 0x0; (i < (sizeof (tests) / sizeof (test_t))) && do_test; ++i)
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
  /* Frees the command line descriptor */
  if (cmdline.items)
    {
      free (cmdline.items);
    }
  printf ("\nTest suite finished.\n");
  return 0x0;
}

/*
 * Local functions definitions
 */
/* Parses the command line and returns a structure of parsed
   stuff. The command line parsing was written this way in order to
   make it available to all possible platforms, since the getopts is
   available only in unix systems.  */
static int 
cmdline_parse (cmdline_t * cmdline, const int argc, const char **argv)
{
  register int i;               /* Iterator for the command line parsing */

  /* Initializations */
  cmdline->items = (cmdline_item_t *) NULL;
  cmdline->size = 0x0ul;

  /* Parses the command line in a portable way */
  for (i=1; i<argc; ++i)
    {
      /* Check if the current one is a parameter */
      if (* argv[i] == '-')
        {
          cmdline_item_t * newcmdline; /* Temporary buffer */
          unsigned int j;       /* Iterator for the items list */

          cmdline->size++;
          newcmdline = (cmdline_item_t *) realloc ((void *) cmdline->items, 
                                                   cmdline->size 
                                                   * sizeof (cmdline_item_t));
          if (! newcmdline)
            {
              /* No memory !! */
              return ENOMEM;
            }

          /* Sets the iterator for the items list accordingly */
          j = cmdline->size - 1;

          /* Sets the provided pointer to the new location */
          cmdline->items = newcmdline;

          /* loads the cmd line */
          cmdline->items[j].option = (char *) argv[i] + 1;

          /* Check if there is an argument for the parameter */
          cmdline->items[j].value = (char *) NULL;
          if (argv[++i] && *argv [i] != '-')
            {
              cmdline->items[j].value = (char *)argv[i];
            }
        }
    }
  return 0x0;
}

/* Gets and int value from the command line parameter. If nothing
   could be found. the value remains untouched. */
static int 
cmdline_value_getint (int *value, cmdline_t *cmdline, const char *parm)
{
  register size_t i;            /* Iterator for the list */

  /* Do a linear search in the list */
  for (i=0; i<cmdline->size; ++i)
    {
      if (cmdline->items[i].option[0] == *parm)
        {
          int newvalue;
          /* We have found the parameter. Lets check if the parameter
             has a value */
          if (! cmdline->items[i].value)
            {
              return EOF;
            }
          /* Convert it to int */
          newvalue = atoi (cmdline->items[i].value);
          /* Check if the convertion was okay */
          if (newvalue > 0x0)
            {
              *value = newvalue;
              return 0x0;
            }
          /* Error - could not convert the value */
          break;
        }
    }
  return EOF;
}

/* Checks if a parameter was really provided */
static int 
cmdline_parameter_provided (const cmdline_t * cmdline, const char *param)
{
  register size_t i;            /* Iterator for the list of parameters */

  for (i=0x0u; i<cmdline->size; ++i)
    {
      if (cmdline->items[i].option[0] == *param)
        {
          return 0x1;
        }
    }
  return 0x0;
}

/* Shows a small help screen */
static void
help (void)
{
  printf ("Usage:\n"\
          "\t-m n: Number of elements to use on each test\n" \
          "\t-h  : This help screen\n\n"); 
}
