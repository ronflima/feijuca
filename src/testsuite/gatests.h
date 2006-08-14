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

 Description: Header file with definitions needed by the test suite

 CVS Information
 $Author: harq_al_ada $
 $Id: gatests.h,v 1.17 2006-08-14 00:16:24 harq_al_ada Exp $
*/

#ifndef GATESTS_H
#define GATESTS_H
/*
 * Includes
 */
#include <stdio.h>
#include "gacommon.h"

GABEGINDECLS
/*
 * Macros
 */
/* Constants */
#define MAX_TESTS    1		/* Maximum number of tests */
#define MAX_ELEMENTS 10000U	/* Maximum number of elements  */
/* Errors */
  enum
{
  EFAILED = 50001u,		/* Test failed */
  ENOTIMP = 50002u,		/* Test not implemented yet :"> */
  ECKFAIL = 50003u		/* Check failed  */
};


/* Error reporting and handling */
#define ERROR(test, function, status) fprintf (stderr, "\t[%-7s] error %d " \
"- %s @ %s:%d\n", test, status, function, __FILE__, __LINE__);

/*
 * Datatypes
 */
/* Test procedures data types */
typedef GAERROR (test_proc_t) (size_t);	    /* Test procedure */
typedef GAERROR (test_scenario_t) (size_t); /* Test scenario  */

typedef struct
{
  char *test_name;
  test_proc_t *test_routine;
}
test_t;				/* Test procedure descriptor */

typedef struct
{
  char *name;
  test_scenario_t *routine;
}
scenario_t;			/* Test scenario to execute */

/* Command line parsing support structures */
typedef struct
{
  char *option;			/* Option */
  char *value;			/* Value of the parameter */
}
cmdline_item_t;			/* Command line item */

typedef struct
{
  cmdline_item_t *items;	/* List of items */
  size_t size;			/* Size of the list */
}
cmdline_t;			/* Command line descriptor */
/*
 * Prototypes
 */
GAERROR (test_list) (size_t);
GAERROR (test_dlist) (size_t);
GAERROR (test_stack) (size_t);
GAERROR (test_clist) (size_t);
GAERROR (test_queue) (size_t);
GAERROR (test_ivector) (size_t);
GAERROR (test_deque) (size_t);
GAERROR (test_dclist) (size_t);
GAERROR (execute_scenarios) (const char *, size_t, scenario_t[], size_t);

GAENDDECLS
#endif /* GATESTS_H */
