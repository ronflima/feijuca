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

 Description: Header file with definitions needed by the test suite

 CVS Information
 $Author: ron_lima $
 $Id: gatests.h,v 1.4 2004-10-20 10:40:00 ron_lima Exp $
*/

#ifndef GATESTS_H
#define GATESTS_H
/*
 * Includes
 */

/*
 * Macros
 */
#define MAX_TESTS    1
#define MAX_ELEMENTS 10000U
/*
 * Datatypes
 */
typedef int (test_proc_t) (void);
typedef struct
{
  char *test_name;
  test_proc_t *test_routine;
} test_t;

/*
 * External storage
 */

/*
 * Prototypes
 */
extern int
  (test_list) (void);
extern int
  (test_dlist) (void);
extern int
  (test_stack) (void);

#endif				/* GATESTS_H */
