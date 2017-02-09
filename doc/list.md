
# Single linked lists in Feijuca Library

Feijuca Library implements single linked lists through the header file
<fjc_list.h>. The list descriptor contains always the first and the last
elements for fast access in the list. Navigation in the list is possible only in
one way: from the beginning through the end. This is an effect on how single
linked lists are built.

Single linked lists are useful when you have a collection of data that must be
traversed from the beginning through the end and you don't know the amount of
data that will be loaded in memory.

Until this release, no thread safety was analyzed or even implemented in this
algorithm. So, thread safety is not guaranteed.

## Data types

The data structure _fjc\_list\_t_ is the list descriptor. This is used to hold
all needed data to implement the list. There is no need to access directly any
element of this structure since they are manipulated by the library's
functions. You should treat as an opaque data structure.

It is important, though, since all list operations are linked to this data
type. So, you will always need a list descriptor in order to create a new list,
manipulate it and destroy it.

## Functions

### fjc\_list\_init

```c
int fjc_list_init (fjc_list_t *list, deallocator_t dealloc)
```

Purpose: Initializes the list descriptor.

Parameters:

- list:

List descriptor to initialize

- dealloc:

Deallocator pointer function for the user-defined deallocation function
(required)

The deallocator is used to delete items inserted into the list. By design, the
list doesn't make any assumption on data that is stored in it. So, it is your
responsibility to allocate and deallocate data inserted into a given list.

Return values:

- E\_FJC\_OK: List was initialized successfully
- E\_FJC\_NOMEM: There was no enough memory for list description allocation and
initialization.
- E\_FJC\_INVAL: If parameters cannot be accepted for the list creation and
initialization.

**Hints**:

- The deallocator function is a user-defined function that will handle
the deallocation of the data stored in the list. Since this set of
functions were designed to work over any kind of user-defined data, so
the deallocation will be responsibility of the user, since the library
has no way to know how to handle deallocations of generic data. This
function must have the following prototype:

```c
void deallocator (void *data);
```

You will note that this prototype is exactly the same definition of the
_deallocator\_t_ data type.

### fjc\_list\_destroy

```c
fjc_error_t fjc_list_destroy (fjc_list_t list);
```

Purpose: destroys a list, deallocating all of its members from memory.

Parameters:

- list: List descriptor to destroy.

When you are done using a list, you should call this function to deallocate it
from memory. The list destroy will iterate through all elements, deallocating
one by one. Element data is deallocated using the deallocator provided when the
list descriptor was first initialized.

This is a O(n) function. So, know that deallocating a list may take some time.

Return values:

- E\_FJC\_OK: List was correctly destroyed.
- E\_FJC\_INVAL: if the list descriptor provided is NULL.

### fjc\_list\_get

```c
fjc_error_t fjc_list_get (fjc_list_t list, fjc_position_t position, void **data);
```

Purpose: Get an element at a given position in the list.

Parameters:

- list: List descriptor to get data from.

- position: The position you want to get data from. Valid values are:

    - POS\_FJC\_HEAD: get data from the head of the list

    - POS\_FJC_\TAIL: get data from the tail of the list

    - POS\_FJC\_CURRENT: if there is a current value, get it

    - POS\_FJC\_NEXT: get data on the next element, if the list is positioned at a given element

Remarks:

The _current_ element on a list depend on its navigation. If you never moved in
the list by using _fjc\_list\_move_ function, the current element is NULL. It
means that the list is not being navigated. So, if you want to get an element
that is different from the head or tail, you must navigate your list first.

Return values:

- E\_FJC\_OK: Operation was successful

- E\_FJC\_INVAL: One of the provided parameters is invalid.

- E\_FJC\_EOF: There is no element that match your criteria.

### fjc\_list\_insert

```c
fjc_error_t fjc_list_insert (fjc_list_t list, fjc_position_t position, const void *data);
```

Purpose: inserts an element into the list

Parameters:

- list: List descriptor, previously initialized with fjc\_list\_init

- position: Where do you want to insert data. Valid values are:

    - POS\_FJC\_HEAD: Inserts into the head of the list

    - POS\_FJC\_TAIL: Inserts into the tail of the list

    - POS\_FJC\_NEXT: Insert into the element after the current one, if current
      is available.

Remarks:

The current element depend on list navigation. If you try to insert an element
on an element different on the head or tail without starting a navigation, the
insertion will fail.

### fjc\_list\_move

```c
fjc_error_t fjc_list_move (fjc_list_t list, fjc_position_t position);
```

Purpose: navigates the list, moving the pointer to a proper position

Parameters:

- list: List descriptor, previously initialized with fjc\_list\_init

- position: Where do you want to move to. Valid values:

    - POS\_FJC\_HEAD: Moves to the head of the list

    - POS\_FJC\_TAIL: Moves to the tail of the list

    - POS\_FJC\_NEXT: Moves to the element after the current one, if current
      is available.

Hints:

In order to navigate the list, start it by moving to the head element. Then,
execute a series of moves to the next. This will iterate from the first to the
last element.

### fjc\_list\_del

```c
fjc_error_t fjc_list_del (fjc_list_t list, fjc_position_t position, void **data);
```
Purpose: deletes an element from the list

Parameters:

- list: List descriptor, previously initialized with fjc\_list\_init

- position: where do you want to delete the item. Valid values:

    - POS\_FJC\_HEAD: List head

    - POS\_FJC\_NEXT: next element. It is only available if you have previously navigated the list.

- data: If you provide a valid pointer, data saved on the list is returned. So,
  it is your responsibility to remove it from memory. If you provide a NULL
  pointer, data associated to the list element will be removed from memory by
  calling your deallocator function, the one you have used to initialize the
  list.

Remarks:

You cannot delete the list's tail. Since this is a single-linked list, it is not
possible to delete the tail since there is not enough information on the element
to get the previous one.

### fjc\_list\_reverse

```c
fjc_error_t fjc_list_reverse (fjc_list_t list);
```

Purpose: reverses a single-linked list

Parameters:

- list: List descriptor to reverse

Remarks:

This function uses a sliding window algorithm to reverse the entire list. Even
being interesting, it is important to notice that the algorithm is higly
dependent on the quantity of items inside the list. Its complexity is O(n). So,
be careful when using it because it may cause a high CPU usage depending on how
many items are stored in the list.

### fjc\_list\_get\_size

```c
fjc_error_t fjc_list_get_size (fjc_list_t list, size_t *size);
```

Purpose: get the current number of elements (size) of a list

Parameters:

- list: List descriptor

- size: Return parameter. The size of the list is stored here.

Remarks:

Since the list descriptor keeps track of each element on the list, getting the
size of a given list is very, very fast. This routine only return the bookeeping
information without having to iterate through every item to count it. So, it is
a very efficient routine which you can call without fear.
