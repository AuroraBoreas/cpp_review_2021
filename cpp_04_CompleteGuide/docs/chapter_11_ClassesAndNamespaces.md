# storage classes and namespaces

The storage class is responsible for defining those parts of a program where an object or function can be used. 

Namespaces can be used to avoid conflicts when naming global identifiers.


## storage class specifiers

the storage class of an object is determined by

- the position of its declaration in the source file
- the storage class specifier, which can be supplied optionally.


the following storage class specifiers can be used

- extern
- static
- auto
- register

what does *storage class* do?

1. storage class specifies the lifetime of the object, that is, the period of time from the construction of the object until its destruction.

2. in addition, the storage class delimits the part of the program in which the object can be accessed directly by its name, the so-called object *scope*

## global object

A global object must be defined once, and once only, in a program.

However, it can be declared as often as needed and at any position in the program.

## extern object

An object belonging to the extern storage class is initially only available in the source file where it was defined

example

```c++

extern long position; // declaration

/*
This statement declares position as an external object of type long.

The extern declaration thus allows you to “import” an object from another source file.
*/

```

an `extern` declaration only refers to an object and should therefor NOT be used to initialize the object.

if u do initialize the object, u are defining that object!

## static object

if an object definition is preceded by the `static` keyword, the object belongs to the static storage class.

the most important characteristic of static objects is their `static` (or permanent) lifetime.

`static` objects are NOT placed on the stack, but are stored in the data area of a program just like `external` objects.

static vs external

