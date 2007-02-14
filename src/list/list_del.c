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
 along with G.A. Lib; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

  System: G.A. Lib

  Description: Deletes the next element pointed by element

 CVS Information $Author: harq_al_ada $ $Id: list_del.c,v 1.7 2004/07/19 00:53:45
 ron_lima Exp $
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
#include "list_.h"

/* Version info */
static char const rcsid [] = "@(#) $Id: list_del.c,v 1.36 2007-02-14 22:46:01 harq_al_ada Exp $";

/* Local prototypes */

/*  
 * Deletes an element from the head of the list. This function
 * guarantees that the list is correctly linked after the extraction
 * of the head element.
 * Return values:
 * - pointer to the head if the element could be deleted.
 * - NULL if the element could not be deleted
 */
static list_element_t 
extract_element_from_head_ __P((list_t));

/*
 * This function extracts the next element from the list. It
 * guarantees that the list will be correctly linked after the
 * operation completes. It is expected that the current element
 * is valid.
 * Return values:
 * - A pointer to the element extracted from the list
 * - NULL if the element could not be extracted
 */
static list_element_t 
extract_element_from_next_ __P((list_t));

/* Exported function definitions */

GAERROR
list_del (list_t list, void **data, position_t whence)
{
  GAERROR rc = EGAOK;                 /* General error handling variable */

  assert (list != NULL);
  if (! list_is_valid_ (list))
    {
      rc = EGAINVAL;
    }
  else 
    {
      size_t size;

      if ((rc = list_get_size (list, &size)) == EGAOK)
        {
          if (data != NULL)
            {
              *data = (void *) NULL;
            }
          if ((size == 0x0) || ((size == 0x1) && (whence == POS_NEXT)))
            {
              rc = EGAEOF;
            }
          else if (whence == POS_TAIL)
            {
              /* Attempts to delete the tail are invalid, since there
               * is no way to relink the list later. */
              rc = EGAINVAL;
            }
          else 
            {
              list_element_t element = NULL; /* Element to be deleted */
              void * got_data;               /* Data got from the element of the list */

              /* Extracts the element from the list and delete it. There
               * are two valid positions: the head and the next after the
               * current. Any other position cannot be operated since the
               * list have not enough information to do so. */
              if (whence == POS_HEAD)
                {
                  element = extract_element_from_head_ (list);
                }
              else if (whence == POS_NEXT)
                {
                  element = extract_element_from_next_ (list);
                }
              if (element == NULL) 
                {
                  /* If could not get a valid element, then return EOF
                   * to the caller. This situation happens when the
                   * list has only one member or when curr_ points to
                   * the tail or user requests the deletion at
                   * POS_NEXT or curr_ points to nowhere */
                  rc = EGAEOF;
                }
              else if ((rc = list_element_get_data_ (element, &got_data)) == EGAOK)
                {
                  deallocator_t *dealloc=NULL;
                  if (data != NULL)
                    {
                      *data = got_data;

                      /* At this point, it is necessary to set the element
                       * data to NULL or else the list_element_destroy_
                       * function will wipe the data we want to restore
                       * from memory. */
                      rc = list_element_set_data_ (element, NULL);
                    }
                  else
                    {
                      rc = list_get_deallocator_ (list, &dealloc);
                    }
                  if (rc == EGAOK)
                    {
                      if ((rc = list_element_destroy_ (element, dealloc)) == EGAOK)
                        {
                          rc = list_increment_size_ (list, -0x1);
                        }
                    }
                }
            }
        }
    } /* else */
  return rc;
}

/* Local function definitions */

static list_element_t 
extract_element_from_head_ (list_t list)
{
  GAERROR rc;                   /* Error handling */
  list_element_t head;          /* Head of the list */
  list_element_t next;          /* Next item from the head */

  next = NULL;
  rc = list_get_head_ (list, &head);
  if (rc == EGAOK)
    {
      if(list_element_get_next_ (head, &next) == EGAOK) 
        {
          /* Sets the head to be the next item. This effectively extracts
           * the old head from the list. */
          rc = list_set_head_ (list, next);
        }
      else 
        {
          /* List has only a single element. Set the head to nothing. */
          rc = list_set_head_(list, NULL);
        }
    }
  /* Notifies the tail of the list if head is the same of the
   * tail. */
  if (rc == EGAOK) 
    {
      list_element_t tail;      /* Tail of the list */

      rc = list_get_tail_ (list, &tail);
      if ((rc == EGAOK) && (tail == head))
        {
          rc = list_set_tail_ (list, NULL);
        }
    }
  /* Notifies the current item of the list for changes. */
  if (rc == EGAOK)
    {
      list_element_t curr;          /* Current item of the list */

      if (list_get_curr_ (list, &curr) == EGAOK)
        {
          if (curr == head)
            {
              /* If the current pointer is set, notifies it for the
               * changes if it is pointing to the head. */
              rc = list_set_curr_ (list, next);
            }
        }
    }
  return head;
}

static list_element_t 
extract_element_from_next_ (list_t list)
{
  list_element_t element = NULL; /* Element to extract */
  list_element_t curr;           /* Current element */

  if (list_get_curr_ (list, &curr) == EGAOK)
    {
      if (list_element_get_next_ (curr, &element) == EGAOK)
        {
          list_element_t tail;  /* Tail of the list */

          if (list_get_tail_ (list, &tail) == EGAOK)
            {
              if (element == tail)
                {
                  /* If the element to delete is the tail, updates
                   * the tail to the current, since we are
                   * deleting the next element. */
                  list_set_tail_ (list, curr);
                  list_element_set_next_ (curr, NULL);
                }
              else
                {
                  list_element_t next; /* Next element */

                  /* Relinks the list, extracting out the element
                   * we selected to delete. */
                  if (list_element_get_next_ (element, &next) == EGAOK)
                    {
                      list_element_set_next_ (curr, next);
                    }
                }
            }
        }
    }
  return element;
}
