/* -*-c-*-
   Copyright (c) 2016 Ronaldo Faria Lima
   
   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.

   Description: Finishes a list. This routine will wipe the whole list from
   memory
*/

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "fjc_list.h"
#include "fjc_clist.h"

fjc_error_t
fjc_clist_destroy (fjc_clist_t clist)
{
  assert (clist != NULL);
  if (clist == NULL)
    {
      return E_FJC_INVAL;
    }
  while (fjc_clist_del (clist, POS_FJC_HEAD, NULL) == E_FJC_OK)
    ;
  free (clist);
  return E_FJC_OK;
}
