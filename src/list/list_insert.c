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

 Description: Inserts a new element in the list

 CVS Information
 $Author: harq_al_ada $
 $Id: list_insert.c,v 1.31 2007-02-14 22:48:41 harq_al_ada Exp $
*/
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_insert.c,v 1.31 2007-02-14 22:48:41 harq_al_ada Exp $"; 

/* Local prototypes */

/*
 * Inserts an element on head and tail of the list. This is used when
 * the list is empty and the head and tail must point to the same
 * element.
 * Return values:
 * - 0 on success
 * - EGAINVAL if the new element could not be inserted.
 */
static GAERROR
list_insert_element_on_both_ends_ __P((list_t, list_element_t));

/*
 * Inserts an element on the head of the list. This function
 * guarantess the integrity of the resulting list.
 * Return values:
 * - 0 on sucess
 * - EGAINVAL if the new element could not be inserted into the list
 * After execution the list will become:
 * element -> old head
 */
static GAERROR
list_insert_element_on_head_ __P((list_t, list_element_t));

/*
 * Inserts an element after the next element. This function guarantees
 * the integrity of the resulting list.
 * Return values:
 * - 0 on success
 * - EGABADC if the current pointer points to nowhere
 * After the execution of this routine, the list will become:
 * curr -> element -> next
 * where next is the original next element from curr
 */
static GAERROR
list_insert_element_on_next_ __P((list_t, list_element_t));

/*
 * Inserts an element into the tail of the list. This function
 * guaratees the integrity of the resulting list
 * Return values:
 * - 0 on success
 * - EGAINVAL if the element could not be inserted for some reason.
 * After execution, the list will become:
 * old tail -> element -> NULL
 */
static GAERROR
list_insert_element_on_tail_ __P((list_t, list_element_t));

/* Exported function definition */
GAERROR
list_insert (list_t list, const void *data, position_t whence)
{
  list_element_t element;
  GAERROR rc = EGAOK;

  assert (list != NULL);
  assert (data != NULL);
  if (! list_is_valid_ (list) || ((whence != POS_HEAD) && (whence != POS_NEXT) && (whence != POS_TAIL)))
    {
      rc = EGAINVAL;
    }
  else if ((rc = list_element_init_ (&element, data)) == EGAOK)
    {
      size_t size;

      if ((rc = list_get_size (list, &size)) == EGAOK)
        {
          if (size == 0x0u)
            {
              /* Empty list. New element is not both head and tail */
              rc = list_insert_element_on_both_ends_ (list, element);
            }
          else
            {
              if (whence == POS_HEAD)
                {
                  rc = list_insert_element_on_head_ (list, element);
                }
              else if (whence == POS_NEXT)
                {
                  rc = list_insert_element_on_next_ (list, element);
                }
              else if (whence == POS_TAIL)
                {
                  rc = list_insert_element_on_tail_ (list, element);
                }
              else 
                {
                  rc = EGAINVAL;
                }
            }
        }
      if (rc == EGAOK)
        {
          rc = list_increment_size_ (list, 0x1);
        }
      else
        { 
          /* Resets the data in order to preserve the data member */
          if ((rc = list_element_set_data_ (element, NULL)) == EGAOK)
            {
              deallocator_t *dealloc;

              if ((rc = list_get_deallocator_ (list, &dealloc)) == EGAOK)
                {
                  rc = list_element_destroy_ (element, dealloc);
                }
            }
        }
    } 

  return rc;
}

/* Local functions definitions */
static GAERROR
list_insert_element_on_both_ends_ (list_t list, list_element_t element)
{
  GAERROR rc = EGAOK;
  if (element != NULL)
    {
      rc = list_set_head_ (list, element);
      if (rc == EGAOK)
        {
          rc = list_set_tail_ (list, element);
        }
    }
  else
    {
      rc = EGAINVAL;
    }
  return rc;
}

static GAERROR
list_insert_element_on_head_ (list_t list, list_element_t element)
{
  GAERROR rc = EGAOK;
  list_element_t head;
  
  rc = list_get_head_ (list, &head);
  if (rc == EGAOK)
    {
      if ((rc = list_element_set_next_ (element, head)) == EGAOK)
        {
          rc = list_set_head_ (list, element);
        }
    }
  return rc;
}

static GAERROR
list_insert_element_on_next_ (list_t list, list_element_t element)
{
  GAERROR rc = EGAOK;
  list_element_t curr;

  rc = list_get_curr_ (list, &curr);
  if (rc == EGAOK)
    {
      list_element_t next;
      if ((rc = list_element_get_next_ (curr, &next)) == EGAOK)
        {
          if ((rc == list_element_set_next_ (element, next)) == EGAOK)
            {
              rc = list_element_set_next_ (curr, element);
            }
        }
    }
  else
    {
      rc = EGABADC;
    }
  return rc;
}

static GAERROR
list_insert_element_on_tail_ (list_t list, list_element_t element)
{
  GAERROR rc = EGAOK;
  if (element != NULL)
    {
      list_element_t tail;

      rc = list_get_tail_ (list, &tail);
      if(rc == EGAOK)
        {
          if ((rc = list_element_set_next_ (tail, element)) == EGAOK)
            {
              rc = list_set_tail_ (list, element);
            }
        }
    }
  else
    {
      rc = EGAINVAL;
    }
  return rc;
}
