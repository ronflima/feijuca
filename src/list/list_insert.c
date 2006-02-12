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
 $Id: list_insert.c,v 1.21 2006-02-12 23:28:08 harq_al_ada Exp $
*/
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_insert.c,v 1.21 2006-02-12 23:28:08 harq_al_ada Exp $"; 

/* Local prototypes */

/*
 * Inserts an element on head and tail of the list. This is used when
 * the list is empty and the head and tail must point to the same
 * element.
 * Return values:
 * - 0 on success
 * - EGAINVAL if the new element could not be inserted.
 */
static int
insert_element_on_both_ends_ __P((list_t, list_element_t *));

/*
 * Inserts an element on the head of the list. This function
 * guarantess the integrity of the resulting list.
 * Return values:
 * - 0 on sucess
 * - EGAINVAL if the new element could not be inserted into the list
 */
static int 
insert_element_on_head_ __P((list_t, list_element_t *));

/*
 * Inserts an element after the next element. This function guarantees
 * the integrity of the resulting list.
 * Return values:
 * - 0 on success
 * - EGABADC if the current pointer points to nowhere
 */
static int
insert_element_on_next_ __P((list_t, list_element_t *));

/*
 * Inserts an element into the tail of the list. This function
 * guaratees the integrity of the resulting list
 * Return values:
 * - 0 on success
 * - EGAINVAL if the element could not be inserted for some reason.
 */
static int
insert_element_on_tail_ __P((list_t, list_element_t *));

/* Exported function definition */
int
list_insert (list_t list, const void *data, position_t whence)
{
  list_element_t *element;
  int rc = 0x0;

  assert (list != NULL);
  assert (data != NULL);
  if (list == NULL)
    {
      rc = EGAINVAL;
    }
  else
    {
      CHECK_SIGNATURE (list, GA_LIST_SIGNATURE);
  
      if ((element = (list_element_t *) malloc (sizeof (list_element_t))) == NULL)
        {
          rc = EGANOMEM;
        }
      else
        {
          element->data_ = (void *) data;
          element->next_ = (list_element_t *) NULL;

          if (list->size_ == 0x0u)
            {
              rc = insert_element_on_both_ends_ (list, element);
            }
          else
            {
              if (whence == POS_HEAD)
                {
                  rc = insert_element_on_head_ (list, element);
                }
              else if (whence == POS_NEXT)
                {
                  rc = insert_element_on_next_ (list, element);
                }
              else if (whence == POS_TAIL)
                {
                  rc = insert_element_on_tail_ (list, element);
                }
              else 
                {
                  rc = EGAINVAL;
                }
            }
          if (rc == 0x0)
            {
              ++(list->size_);
            }
          else if (element != NULL)
            {
              free (element);
            }
        }
    }

  return 0x0;
}

/* Local functions definitions */
static int
insert_element_on_both_ends_ (list_t list, list_element_t * element)
{
  int rc = 0x0;
  if (element != NULL)
    {
      list->head_ = element;
      list->tail_ = element;
    }
  else
    {
      rc = EGAINVAL;
    }
  return rc;
}

static int 
insert_element_on_head_ (list_t list, list_element_t * element)
{
  int rc = 0x0;

  if (element != NULL)
    {
      element->next_ = list->head_;
      list->head_ = element;
    }
  else
    {
      rc = EGAINVAL;
    }
  return rc;
}

static int
insert_element_on_next_ (list_t list, list_element_t * element)
{
  int rc = 0x0;
  if (list->curr_ != NULL)
    {
      element->next_ = list->curr_->next_;
      list->curr_->next_ = element;
    }
  else
    {
      rc = EGABADC;
    }
  return rc;
}

static int
insert_element_on_tail_ (list_t list, list_element_t * element)
{
  int rc = 0x0;
  if (element != NULL)
    {
      list->tail_->next_ = element;
      list->tail_ = element;
    }
  else
    {
      rc = EGAINVAL;
    }
  return rc;
}
