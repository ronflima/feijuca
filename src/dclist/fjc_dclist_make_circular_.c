/* -*-c-*-
 G.A. Library - A generic algorithms and data structures library
 Copyright (C) 2005 - Ronaldo Faria Lima

 This library is free software; you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as
 published by the Free Software Foundation; either version 2.1 of the
 License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful, but
 WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
 USA

 System: G.A. Lib

 Description: Makes the dclist circular again by linking the head to
 the tail and the tail to the head. This is an internal function that
 is used by the circular lists routine. Notice that several checkings
 that are usually done for exported routines are ommitted here in
 order to make the function as simple as possible.
*/
#include <assert.h>
#include "fjc_dclist.h"
#include "fjc_dclist_.h"
#include "fjc_dlist_.h"

fjc_error_t
fjc_dclist_make_circular_ (fjc_dclist_t dclist)
{
  assert (dclist != NULL);
  if (dclist == NULL)
    {
      return E_FJC_INVAL;
    }
  if ((dclist->list_->head_ != NULL) && (dclist->list_->head_->prev_ == NULL))
    {
      dclist->list_->head_->prev_ = dclist->list_->tail_;
    }
  if ((dclist->list_->tail_ != NULL) && (dclist->list_->tail_->next_ == NULL))
    {
      dclist->list_->tail_->next_ = dclist->list_->head_;
    }
  return E_FJC_OK;
}
