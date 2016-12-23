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

   Description: Finishes the queue. This routine will delete the stack
   from the memory
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fjc_list.h"
#include "fjc_queue.h"
#include "fjc_queue_.h"

fjc_error_t
fjc_queue_destroy (fjc_queue_t queue)
{
  fjc_error_t rc = E_FJC_OK;
  fjc_list_t list = NULL;
  
  assert (queue != NULL);
  if (! fjc_queue_is_valid_ (queue))
    {
      rc = E_FJC_INVAL;
    }
  else 
    {
      fjc_queue_get_list_(queue, &list);
      fjc_list_destroy (list);
      memset (queue, 0x0, sizeof (struct fjc_queue_t));
      free (queue);
    }
  return rc;
}
