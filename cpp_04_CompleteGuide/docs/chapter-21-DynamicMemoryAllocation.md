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

### calling `new` with a default constructor

### explicit initialization

### releasing memory

## dynamic storage allocation for arrays

(481)

### the `new[]` operator

### the `delete[]` operator

## application: linked lists

(483)

### dynamic data structures

### defining a linked list

### advantages

## representing a linked list

(485)

### representing list elements

### representing a list
