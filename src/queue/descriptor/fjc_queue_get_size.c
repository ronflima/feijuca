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

   Description: Returns the size of a queue
*/

#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include "fjc_list.h"
#include "fjc_queue.h"
#include "fjc_queue_.h"

fjc_error_t
fjc_queue_get_size (fjc_queue_t queue, size_t * size)
{
  fjc_list_t list = NULL;

  assert (queue != NULL);
  if (! fjc_queue_is_valid_ (queue) || size == NULL)
    {
      return E_FJC_INVAL;
    }
  fjc_queue_get_list_(queue, &list);
  return fjc_list_get_size (list, size);
}
