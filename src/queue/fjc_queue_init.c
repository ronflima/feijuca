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

   Description: Allocates and initializes a queue
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "fjc_list.h"
#include "fjc_queue.h"
#include "fjc_queue_.h"

fjc_error_t
fjc_queue_init (fjc_queue_t * queue, fjc_deallocator_t * dealloc)
{
  fjc_error_t rc = E_FJC_OK;
  
  assert (queue != NULL);
  assert (dealloc != NULL);
  if (queue == NULL || dealloc == NULL)
    {
      rc =  E_FJC_INVAL;
    }
  else if ((*queue = (fjc_queue_t) malloc (sizeof (struct fjc_queue_t))) == NULL)
    {
      rc = E_FJC_NOMEM;
    }
  else
    {
      fjc_list_t list = NULL;
      (*queue)->signature_ = FJC_QUEUE_SIGNATURE;
      if ((rc = fjc_list_init (&list, dealloc)) != E_FJC_OK)
        {
          free (*queue);
        }
      else 
        {
          fjc_queue_set_list_(*queue, list);
        }
    }
  return rc;
}
