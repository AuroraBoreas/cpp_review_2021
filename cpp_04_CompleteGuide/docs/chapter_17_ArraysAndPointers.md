# arrays and pointers

this chapter describes relationship btwn pointers and arrays.

topics:

- pointer arithmetic
- pointer version of functions
- pointers as return_values and read-only pointers
- pointer arrays

## arrays and pointers(1)

(371)

### name and address of an `array`

```c++

// i dont understand this line
char* cPtr = "Hello "; // let cPtr point to "Hello "

```

in c++, the name of an array is also the starting address for that array. to be more precise, **an array name is a pointer to the first array element**

example:

```c++

char town[] = "Beijing";

```

in this case, *town* is a char pointer to *town[0]*, that is, a pointer to the memory address that stores the 'B' character. expression *town* and *&town[0]* aer thus equivalent.

example:

```c++

cout << town;     // output "Beijing"
// or:
cout << &town[0]; // output "Beijing"

```

a pointer to the first character of the string *town* is passed. the characters forming the string are read and displayed from this point onward until the terminating null character, '\0', is reached.

### pointer variables and arrays

an array name is NOT a `pointer variable` but a `constant` that can NOT be modified. however, u can assign this constant to a pointer variable.

example:

```c++

char town[] = "Beijing";

char *cPtr;
cPtr = town; // or: cPtr = &town[0];

cout << cPtr;

```

now *cPtr* points to the array element *town[0]* just like *town*. BUT, in constrast to *town*, *cPtr* is a variable that can be moved.

Table: array_name vs pointer variable

| item       | array_name                                     | pointer variable        |
|------------|------------------------------------------------|-------------------------|
| front view | array                                          | variable                |
| back view  | pointer to array_name[0], can **NOT** be moved | variable, can be moved  |

example:

```c++

char town[] = "Beijing";
char* cPtr  = &town[0];
// or:
cPtr = town;

for(int i=0; i < 7; ++i)
{
    cout << &town[0] << endl;
    &town[0]++; // Error.. why? address can not be moved
    town++;     // Error.. why? constant can not be moved

    cout << *cPtr << endl; // de-reference cPtr pointer
    cPtr++;                // pointer variable can be moved
}

```

### typeless pointer `void*`

**if u need to display the address rather the string**, u should pass a `void* type` pointer rather than a `char pointer`.

example:

```c++

cout << (void*)town;

```

this casts the `char` pointer to a `void* type` pointer and passes it as an argument to the `<<` operator, which in turn outputs the address in hexadecimal format.

the `<<` operator belongs to the `ostream` class and is overloaded for `void* type` for this purpose.

a `void*` pointer represents a memory address w/o establishing a certain type. `void*` pointers are referred to as `typeless pointers` for this reason.

**when u use a typeless pointer for memory access, u MUST therefore name the type being accessed explicitly by means of type casting**.

example:

```c++
// aha! this is way i want to display address of each element in *town*
#include <iostream>
#define MAX_SIZE 7

using namespace std;

char town[] = "Beijing";
char* cPtr  = town;
// or
cPtr = &town[0];

// display string
for(int i=0; i < MAX_SIZE; ++i)
{
    cout << *cPtr << endl;
    cPtr++;
}

// display address of each element in char array town
for(int i=0; i < MAX_SIZE; ++i)
{
    cout << (void*)cPtr << endl; // convert `pointer variable` *cPtr* to `typeless pointer` to access memory address
    cPtr++;
}

```

Table: Ptr vs (void*)Ptr to get address

| item            | Ptr       | (void*)Ptr    |
|-----------------|-----------|---------------|
| normal variable | get addr  | get addr      |
| number array    | get addr  | get addr      |
| string array    | get addr  | get addr      |
| **char** array  | *get val* | get addr      |

example:

```c++
// code snippet

int a(10);
int numbers[] = {1, 3, 5};

// pointer points to normal variable
int* Ptr = &a;
cout << "variable a's address: " << Ptr << endl;
// or:
cout << "variable a's address: " << (void*)Ptr << endl;
cout << "pointer variable Ptr's address: " << &Ptr << endl;

// pointer points to array
Ptr = numbers; // or: Ptr = &numbers[0];
cout << "array numbers' address: " << Ptr << endl;
cout << "array numbers' address: " << (void*)Ptr << endl;
cout << "pointer variable Ptr's address: " << &Ptr << endl;

// pointer points to char array
char hello[] = "hello world";
char* hPtr = hello;
cout << "char array address: " << hPtr << endl; // difference here
cout << "char array address: " << (void*)hPtr << endl;
cout << "pointer var hPtr address: " << &hPtr << endl;

```

## arrays and pointers(2)

(373)

### addressing array elements

access to individual elements in c++ is very close related to **pointer arithmetic**.

example:

```c++

int arr[4] = {0, 10, 20, 30};

```

now it is possible to add or subtract pointers and integral values. the `size of the object` **referenced by the pointer** is automatically taken into consideration.

thus, the following applies to any given number, i:

- `arr + i` points to the array element `arr[i]`
- `*(arr + i)` is the array element `arr[i]`

this technique can also be used to address memory spaces outside of the array. thus, `arr - i` addresses the word that precedes `arr[0]`. **but generally this does NOT make much sense, since u have no means of knowing what is stored at this memory address**.

### addressing with `pointer variable`

array elements can aslo be addressed using pointer variables.

example:

```c++

int* iPointer = arr; // iPointer points to arr[0]

```

for any given integer, `i`, the following expressions are thus equivalent:

```c++

&arr[i];
arr + i;
iPointer + i

```

the following thus represent equivalent values:

```c++

arr[i];
*(arr + i);
*(iPointer + i);
iPointer[i];  // this line is rather confusing. indexing a pointer variable like an array?

```

at first it might seem surprising that u can use the array notation `iPointer[i]` for pointers. the compiler translates `arr[i]` to `*(arr + i)`, in other words: " start at address `arr`, move i objects up, and access the object!". this also applies to `iPointer[i]`.

## pointer arithmetic

(375)

### pointer arithmetic

Table: precedence of indirect operator, (prefix/post) increment operator

| precedence        | operator                      |
|-------------------|-------------------------------|
|     High          | var`++`; var`--`; `*`var;     |
|      ^            | ++var; --var;

## arrays as arguments

(377)

## pointer versions of functions

(379)

## read-only pointers

(381)

## returning pointers

(383)

## arrays of pointers

(385)

## command line arguments

(387)