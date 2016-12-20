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

   Created: 2016-12-18 by Ronaldo Faria Lima

   This file purpose: Check list loading with integers.
*/

/* Forces the assertions to be in code */
#ifdef NDEBUG
#undef NDEBUG
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "fjc_list.h"

static void
load_list(fjc_list_t list);

int
main(void)
{
  fjc_list_t list;
  fjc_error_t rc;
  unsigned qty = 0x0;
  
  rc = fjc_list_init(&list, free);
  assert(rc == E_FJC_OK);
  load_list(list);
  rc = fjc_list_move(list, POS_FJC_HEAD);
  assert(rc == E_FJC_OK);
  do {
    int *n;
    fjc_list_get(list, (const void **)&n, POS_FJC_CURR);
    assert (*n >= 0 && *n < 1000);
    rc = fjc_list_move(list, POS_FJC_NEXT);
    ++qty;
  } while (rc == E_FJC_OK);
  assert (qty == 1000);
  rc = fjc_list_destroy(list);
  assert(rc == E_FJC_OK);
  
  return 0x0;
}

static void
load_list(fjc_list_t list)
{
  register int i;
  for (i=0; i<1000; ++i)
    {
      fjc_error_t rc;
      int *j = (int *)malloc(sizeof(int));
      assert(j != NULL);
      *j = i;
      rc = fjc_list_insert(list, (void *)j, POS_FJC_HEAD);
      assert(rc ==  E_FJC_OK);
    }
}
