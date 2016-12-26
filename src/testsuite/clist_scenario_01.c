/* -*-c-*-
   The MIT License (MIT)

   Copyright (c) 2016 - Ronaldo Faria Lima

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.

   Created: 2016-12-26 by Ronaldo Faria Lima
   
   This file purpose: Basic test suite for circular lists
*/

#ifdef NDEBUG
#undef NDEBUG
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fjc_clist.h"

static void
load_list(fjc_clist_t);

int
main (void)
{
  fjc_clist_t clist;
  fjc_error_t rc;
  int *head;
  int *data;
  register int i;

  rc = fjc_clist_init(&clist, free);
  assert (rc == E_FJC_OK);

  load_list(clist);
  rc = fjc_clist_move(clist, POS_FJC_HEAD);
  assert (rc == E_FJC_OK);
  rc = fjc_clist_get(clist, (const void **)&head, POS_FJC_HEAD); 
  assert(rc == E_FJC_OK);
  for (i=0; i<1000; ++i)
    {
      rc = fjc_clist_move(clist, POS_FJC_NEXT);
      assert(rc == E_FJC_OK);
    }
  rc = fjc_clist_get(clist, (const void **)&data, POS_FJC_CURR); 
  assert(rc == E_FJC_OK);
  assert(data == head);
  rc = fjc_clist_destroy(clist);
  assert (rc == E_FJC_OK);
  return 0x0;
}

static void
load_list(fjc_clist_t clist)
{
  register int i;
  void *arena = malloc(sizeof(int) * 1000);
  assert (arena != NULL);
  free(arena);
  for(i=0; i<1000; ++i)
    {
      fjc_error_t rc;
      int *j = (int *)malloc(sizeof(int));
      assert(j != NULL);
      rc = fjc_clist_insert(clist, (const void *)j, POS_FJC_HEAD);
      assert(rc == E_FJC_OK);
    }
}
