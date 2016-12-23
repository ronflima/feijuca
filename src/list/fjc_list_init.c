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

   Description: Allocates and initializes the list
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "fjc_list.h"
#include "fjc_list_.h"

fjc_error_t
fjc_list_init (fjc_list_t *list, fjc_deallocator_t * dealloc)
{
  assert (list != NULL);
  assert (dealloc != NULL);
  *list = (fjc_list_t) malloc (sizeof (struct fjc_list_t));
  if (*list == NULL)
    {
      return E_FJC_NOMEM;
    }
  memset (*list, 0x0, sizeof(struct fjc_list_t));
  (*list)->deallocator_ = dealloc;
  return E_FJC_OK;
}
