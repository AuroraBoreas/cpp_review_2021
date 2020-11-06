# Dynamic Memory Allocation

(474)

topics

- how a program can allocate and release memory dynamically in line with current memory requirements

Dynamic memory allocation is an important factor in many C++
programs.

## the operator `new`

(475)

### dynamic memory allocation

when a program is compiled, the size of the data the program will need to handle is often an unknown factor; in other words there is NO WAY to estimate the memory requirements of the program. in cases like this, u will need to allocate memory dynamically, that is, while the program is running.

dynamically allocated memory can be released to continually optimize memory usage with respect to current requirements. this is turn provides a high level of flexibility, allowing a programmer to represent dynamic data structures, such as trees and linked lists.

programs can access a large space of free memory known as the `heap`. depending on the operating system (and how the OS is configured), the `heap` can also occupy large amounts of unused space on the hard disk by *swapping* memory to disk.

C++ uses the `new` and `delete` operators to allocate and release memory, and this means that objects of any type can be created and destroyed.

### calling `new` for fundamental types

syntax: 

```c++

ptr = new type; // where ptr is a pointer to type.

```

[explanation]

**the `new` operator creates an obj of the specified type and returns the address of that obj**. the address is normally assigned to a pointer variable. if the pointer belongs to a wrong type, the compiler will issue an error message.

example:

```c++

long double &pld = new long double; // allocate momery w/o initialization
pld = new long double(10000.99); // allocate memory with initialization

cout << *pld << endl;

```

## the operator `delete`

(477)

A program should make careful use of available memory and always release memory that is no longer needed. Failure to do so can impact the performance of your computer system. Memory that is released is available for further calls to new.

example:

```c++
// dynstd.cpp
#include <iostream>
using namespace std;

int main()
{
    double* ptr_length = new double(99.99); // dynamic memory allocation
    delete ptr_length;                      // free storage
    ptr_length = new double(36.90);         // dynamic memory allocation again
    double& var = *ptr_length;              // wtf is this line?! reference to double?

    return 0;
}

```

### reference variable

(https://www.cprogramming.com/tutorial/references.html)

C++ references allow u to create a **second name** for the a variable that u can use to read or modify the original data stored in that variable. 

what this means is that when u declare a reference and assign it a variable, it will allow u to treat the reference exactly as though it were the original variable for the purpose of accessing and modifying the value of the original variable -- even if the send name(the reference) is located within a different scope.

#### basic syntax

syntax: `int& foo = ...;`

[creating]

1. when a reference is created, u **MUST tell it which variable it will become an alias for**. after u create the reference, whenever u use the variable, u can just treat it as though it were a regular integer variable.
2. but when u create it, u **MUST initialize it with another variable**, whose address it will keep around behind the scenes to allow u to use it to modify that variable.

in a way, this is similar to having a pointer that always points to the same thing.

[reference-var vs pointer]

- one key difference is that **`references variable` do NOT require dereferencing** in the same way that pointers do; u just treat them as normal variables.
- when u create a reference to a variable, **u need not do anything special to get the memory address**. the compiler figures this out for u.

Table: reference-var vs pointer

| item              | reference-var(ByRef in VB)            | pointer           |
|-------------------|---------------------------------------|-------------------|
| dereference       | NO                                    | YES, `*`          |
| get memory addr?  | NO need. compiler do it automatically | YES, `&`          |

example:

```c++
// variable of reference.cpp

#include <iostream>

int main()
{
    int x;
    int& foo = x; // foo is now a reference to x..

    foo = 56;
    std::cout << x << std::endl; // output 56

    return 0;
}

```

#### functions taking `references paramters`

example:

```c++
// reference var as parameters
inline void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 2, b = 3;
    swap(a, b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}

```

#### references and safety: the exceptions

it is possible to have an <font color="red">invalid</font> references in one minor and one major case.

example:

```c++

int *x = 0;
int& y = *x; // bad. assign a reference to a dereferenced NULL pointer

```

a more pressing issue is that it is possbile to "invalidate" a reference in the sense that it is possible that a reference to a block of memory can live on past the time when the memory is valid.

example:

```c++

int& getLocalVariable()
{
    int x;
    return x; // Error
}

// possible fix

int& getLocalVariable()
{
    static int x; // using static keyword to ensure x lives till program is terminated.
    return x;
}

```

#### references and dynamicall allocated memory

be aware of references to dynamicall allocated memory.

- one problem is that when u **use references, it's NOT clear that the memory backing the reference needs to be deallocated** -- it usually doesn't, after all. this can be fine when u pass data into a function since the function would generally not be responsible for deallocating the memory anyway.
- on the other hand, if u **return a reference to dynamically allocated memory**, then u are asking for trouble since it won't be clear that there is something that needs to be cleaned up by the function caller.

### calling `delete`

syntax: 

```c++

long *ptr = new long(111);

delete ptr; // the operand ptr addresses the memory space to be released.

ptr = new long(2000000); // dynamically allocate again

```

If you do not call delete, the dynamically allocated memory space is not released until the program terminates.

u can pass a NULL pointer to `delete` when u call the operator. in this case nothing happens and `delete` just return, so u do not need to check for NULL pointers when releasing memory.

A `delete` expression is always a `void type`, so u can NOT check whether memory has been released successfully.

misuse of `delete` can be disastrous.

- do NOT call `delete` twice for the same obj
- do NOT use `delete` to release statically allocated memory

### error handling for `new`

if there is NOT enough memory available, the so-called `new handler` is called.

## dynamic storage allocation for classes

(479)

the operator `new` and `delete` were designed to create and destroy instance of a class dynamically. 

- in this case, in addtion to allocating memory, a suitable constructor MUST be called. 
- before releasing memory, the destructor MUST be called to perform cleaning up tasks.

however, the operator `new` and `delete` ensure that this happens.

### calling `new` with a default constructor

example:

```c++

Euro* pEuro = new Euro;
// u MUST make sure that a default constructor exists!

```

### explicit initialization

to initialize an obj explicitly, u can state its initial values in parentheses when u call `new`.

syntax:

```c++

Type *ptr = new Type(initializating_list);

```

### releasing memory

when an obj that was created dynamically is destroyed, the `delete` operator makes sure that the obj is cleaned up. **the `destructor` is first called, and only then is the memory space released**.

as previously discussed in the section on fundamental types, when u call `delete` u must ensure that the pointer is addressing a dynamic obj or that u are dealing with a NULL pointer.

syntax:

```c++

float *ptr = NULL; // NULL pointer

```

## dynamic storage allocation for arrays

(481)

imagine u are compiling a program that will store an unknown quantity of elements in an array. your best option is to let the program create the array dynamically. an array of this type is known as a `dynamic array`.

### the `new[]` operator

the `new[]` operator is available for creating dynamic arrays. when u call the operator, u MUST supply the type and quantity of the array elements.

syntax: `vekPtr = new Type[cnt];`

Example:

```c++

Account *pk = new Account[256];

// this statement allocates memory of 256 `Account` type obj and uses the default constructor to initialize them.

// these obj are
pk[0], pk[1], ..., pk[255];
// or pointer notation
*pk, *(pk+1), ..., *(pk+255)

```

**if the array elements are of a class type, the class MUST have a `default constructor`, (or a default paramaterized constructor), since u can NOT supply an initialization list when calling `new[]`**. starting values for the array elements can NOT be assigned until later.

### the `delete[]` operator

it is always a good idea to release the memory space occupied by a dynamic array, if the array is no longer needed. to do so, simply call the `delete[]` operator. **the braces[] tell the compiler to release the whole array, and not just a single array element**.

example:

```c++

delete [] pk;

```

the operand for `delete[]` -- the `pointer` pk in this case -- MUST reference the place in memory that was allocated by a call to `new[]`! the destructor belonging to the current class is called for each array element. this shows the big difference to `delete`, which would merely call the destructor for *pk, i.e. for the first array element.

Table: `new[]` vs `new`, `delete[]` vs `delete`

| operator      | what?                                                                             | pre-requisit                                                               |
|---------------|-----------------------------------------------------------------------------------|----------------------------------------------------------------------------|
| `new[]`       | create an array of certain type in heap, then return the address of that array    | class must have `default constructor`                                      |
| `new`         | create an obj of certain type in heap, then return obj's address                  |                                                                            |
| `delete[]`    | call destructor of certain type for each array element, then clean up             | must reference the place in memory that was allocated by a call to `new[]` |
| `delete`      | call destructor of certain type, then clean up                                    |                                                                            |

## application: linked lists

(483)

### dynamic data structures

a `linked list` is a dynamic data structure that allows easy insertion and deletion of data. a `data structure` defines how data can be organized in units, stored, and manipulated -- as array, or trees for examples.

in constrast to a static data structure, whose size is known before a program is launched, a `dynamic` data structure can change `size` while a program is running.

### defining a linked list

linked list has the following characteristics:

- each list element contains **a data store for the live data** and **a pointer to the next element** in the list
- each list element -- except the first and last elements -- has exactly one predecessor and one successor. the first element in the list has no predecessor and the last element no successor

### advantages

the storage used for the list elements need NOT be contiguous. the main advantage of `linked list` is:

- memory for the list elements is only allocated when needed
- u only need to move a pointer when inserting or deleting list elements.

when an array element is inserted or deleted, the other array elements have to be moved to make room or fill up the "gap" in the array. if there is no room left, u need to allocate memory for a new array and copy the data to it before inserting a new element.

## representing a linked list

(485)

### representing list elements`delete`

pass

### representing a list

pass
