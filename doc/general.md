# Introduction to Feijuca Library

The idea of writing a library with generic algorithms is not new. In fact,
several projects in Github are libraries that intend to implement all general
public domain algorithms like lists, queues and so on. Also, there is a GNU
implementation of such algorithms (Glib). In fact, Feijuca Library is a project
that was born from my studies in algorithms. As a programmer, I was always
looking for such a library. However I wanted to know the algorithms, not only
play with someone else's library. Then I decided to write a small library with
all the ideas that I got from my studies.

This library intends to be as general as possible. As a programmer, I was always
developing some sort of algorithm that is implemented in this library. Actually,
I was always reimplementing those algorithms. I believe that all C programmers
around the world do exactly the same.

This library intends to be as portable as possible. This library has born in
unix but my primary idea is to make it work in every operating system that
supports the Standard C library. The library is self-contained and do not need
any other library in order to be compiled or used.

# Principles used in Feijuca Library

For every algorithm there is a descriptor that encapsulates all the needed data
to implement it. Even if you read and understand the header files where the
descriptors are defined, do not use the inner fields of it. Treat them as
_opaque_ data. The descriptors internals may change from one release to another
and it is not guaranteed that the field that you are using will be available in
the next release of the library with the same name. It can be even deleted.

The descriptors are containers that will hold up all data to implement not only
the algorithms but, also, to hold the data you are adding to the algorithm.

Each function that implements a given algorithm is an operation applied uppon
the descriptor. This is an object-oriented approach, for sure. However the
implementation, even being thought in an object-oriented manner, has been made
straightforward C. The main principle of the library is to follow the KISS
principle: Keep It Simple, Stupid.

Error reporting is done through function's return values. Every function return
a value that is defined by an enumeration which declares all possible values.

Another important principle used in this library regards namespacing. C is known
to have a global namespace, which is reportedly bad and may generate conflicts
easily. To minimize this limitation of C language, All items in the library is
prefixed by _fjc_ or similar prefix. It avoids conflicts.

## Internal headers

Feijuca library makes use of the central internal header fjc_common.h. This
header is automatically included by the others since it has several declarations
that are common throughout the library. You are advised to not include this
header file directly. Since it is an internal header file it can change without
notice. If you include it directly, you are doing it by your own risk.

## Common declarations

Some declarations are common for all algorithms within the library. All those
declarations are done inside internal header files as discussed in previous
section.

### Constants

Some constants are declared as macros and other as enumerations. Here are the
full set of common constants used through the library.

#### fjc\_position\_t

The position_t enumeration describes a position where you may operate within the
algorithms of the Feijuca Library. Depending on the operation, some of these
constants may not be supported.

- POS\_FJC\_NONE

Dummy operation. Depending on the algorithm, this constant informs to the
operation to not update the current pointer.

- POS\_FJC\_HEAD

Operates on the head. Depending on the algorithm, the _head_ is the beginning of
the data list in memory.

- POS\_FJC\_TAIL

Operates on the tail. Depending on the algorithm, the _tail_ is the end of the
data list in memory.

- POS\_FJC\_NEXT

Operates on the next item. 

- POS\_FJC\_CURR

Operates on the current selected item.

- POS\_FJC\_PREV

Operates in the previous item.

#### Error constants

Several error constants were introduced in order to inform error situations that
may happen inside the Feijuca Library operations. These error constants follow a
naming convention very similar to that adopted by the errno.h header
file. Feijuca Library is not using the constants already declared in errno.h
header file because several of them may not be available on different
systems. So, Feijuca Library declares the following constants in order to avoid
some sort of system dependency. All of them are part of an enumeration called
_fjc\_error\_t_.

- E\_FJC\_INVAL

Invalid argument. Some of the arguments provided for the operation is not valid
for the operation context.

- E\_FJC\_NOMEM

No more memory. The operation tried to allocate more memory to hold the caller's
request but the operating system said no.

- E\_FJC\_BADC

Bad current pointer. The operation needed a valid current position. However the
current position was not valid at all.

- E\_FJC\_OK

Operation finished correctly. No error to report.

- E\_FJC\_EOF

End-of-file. It means that you may have reached the end of a list, stack, or
whatever data structure.
  
  
