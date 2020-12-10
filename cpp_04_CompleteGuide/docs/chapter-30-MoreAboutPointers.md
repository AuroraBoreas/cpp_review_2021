# more about pointers

topics:

- pointers to pointer
- funcs with a variable number of args
- pointers to funcs

## pointers to pointers

(703)

the function `accSort()`

```c++


```

### motivation

pointer variables are obj that have an address in memory, and this means u can use pointers to address them. it is thus possible to create *pointers to pointers*.

this is necessary if:

- an array of pointers is to be dynamically allocated, or
- a function expects an array of pointers as an args

in both cases, u need to declare a pointer var that can access the first element in the array. since each element in the array is a pointer, this pointer var MUST be a pointer to a pointer.

### generating pointer arrays dynamically

now let's look into creating a dynamic array of pointers to `Account` cls obj.

example: `Account** ptr = new Account*[400];`

### pointer arrays as args

when u define a function that expects an array of pointers as an arg, u MUST define parameters to match.

example: `void accSort(Account** kptr, int len);`

## variable number of args

(705)

fixed and varying args on the stack

c++ allows u to define functions that allow a variable number of args.

### obligatory and optional args

functions with a variable number of args always expect a fixed number of obligatory args and a variable number of optional args. at least one obligatory arg is required.

## variable number of args (continued)

(707)

skip

## pointers to functions

(709)

a jump table

### using pointers to functions

in c++, **the name of a function is a constant pointer to that function**. it addresses the machine code for the function. this is a situation that we have alrdy seen for arrays -- the array name is also a constant pointer to the first array element.

there are many uses for pointers to functions. u can save them in an array to form a `jump table`. individual functions are then accessible via an index.

a pointer to a function can also be passed as an arg to another function. this makes sense if the function u are calling needs to work with different functions depending on the current situation.

### declaring pointer to functions

a pointer to a function is declared as follows.

syntax: `type (*fucptr)(parameter_list);`

this defines the variable `funcptr`, which can store the address of a function. the function has the type `type` and the parameter list stated. **the first pair of parentheses is also important for the declaration**. the statement `type *funcptr(parameter_list);` would declare a function `funcptr` that returned a pointer.

example:

```c++

bool compare(double, double); // prototype
bool (*funcptr)(double, double);
funcptr = compare;
(*funcptr)(9.1, 7.2);

```

calling (*funcptr)() is now equivalent to calling compare(). the declaration of compare() is necessary to let the compiler know that compare is the name of a function.

example:

```c++
// jumpTable.cpp
#include <iostream>
#include <cstdlib>
#include <cctype>

using namespace std;

void error_message(char*), message(char*),
     message_up(char*), message_low(char*);

void (*functab[])(char*) = {error_message, message,
                            message_up, message_low};

char call[] = "input: 1, 2, or 3";

int main()
{
    cout << "choose whatever u wanna "
         << "btwn (1, 2, or 3)";
    int n;
    cin >> n;
    if(n<0 || n >3)
        (*functab[0])(call);
    else
        (*functab[n])("hello world\n");

}

void error_message(char* s)
{ cerr << s << endl; }

void message(char* s)
{ cout << s << endl; }

void message_up(char* s)
{ 
    int c;
    if(; *s!='\0'; ++s)
        c = toupper(*s), cout.put(c);
}

void message_low(char* s)
{
    int c;
    if(; *s!='\0'; ++s)
        c = tolower(*s), cout.put(c);
}

```

## complex declarations

(711)

examples:

```c++
// 1st
char (* strptr) [50];
// 2nd
long * (* func()) [];
// 3rd
char *(*(* funcptr)())[]

```

### operators and complex declarations

in the declaration and definition of a function or a variable the same operators that u find in expressions are used in addition to the base type and the name. these operators are:

| operator  | significance                        |
|-----------|-------------------------------------|
| `[]`      | array with elements of type         |
| `()`      | function with return value of type  |
| `*`       | pointer to                          |
| `&`       | reference to                        |

a *complex declaration* always uses more than one of these operators.

example: `char *strptr[50];`

in a declaration, **a combination of the three operators** is permissible, however, the following exceptions apply:

- the elements of an array can NOT be functions
- a function can NOT return a function or an array(BUT it can return a pointer to a function or an array)

operators have the same precedence in declarations as in expressions. u can use parentheses to redefine the order of precedence.

### rules

(712)

when a complex declaration is evaluated, the following rules are applied:

0. always start with the identifier being declared

then repeat the following steps until all the operators have been resolved:

1. if the parentheses/brackets () or [] are on the *right*, they are interpreted.
2. if there is nothing or just a right bracket on the *right* ), the asterisk on the *left* is interpreted, if it exists.
3. at last the base type is interpreted.

the above rules apply to both function and each of its args.

## defining typenames

(713)

example:

```c++

// 1st
typedef DayTime FREETIME;
FREETIME timeArr[100];

// 2nd
typedef struct { double re, im; } COMPLEX;
COMPLEX z1, z2, *zp;

// 3rd
typedef enum { Mo, Tu, We, Th, Fr} WORKDAY;
WORKDAY day;

// 4th
typedef enum { Diamonds, Hearts, Spades, Clubs } COLOR;
typedef enum { seven, eight, nine, ten, jack, queen, king, ace } VALUES;

typedef struct
{
    COLOR f;
    VALUE w;
} CARD;

typedef CARD[10] HAND;

HAND player1, player2, player3;

```

### the `typedef` keyword

(714)

c++ allows u to give types a new name using the keyword `typedef`.

example: `typedef unsigned char BYTE;`

this defines the type name BYTE, which can then be used as an abbreviation of the unsigned char type. the statement

example: `BYTE array[100];`

will then define an array `array` with 100 elements of the unsigned char type. type names are normally uppercase, although this is NOT mandatory.

example:

```c++

typedef int* INTPTR;
typedef enum{ RED, AMBER, GREEN } Lights;

```

type definition do NOT allocate memory and do NOT create a new type. they simply introduce a new name for an existing type.

example: `typedef char*(*PTR_TO_FUNC)();`

the type name `PTR_TO_FUNC` is an abbreviation for the type "pointer to a function that return a pointer to char." the declaration

example: `PTR_TO_FUNC search;`

is then equivalent to `char* (*search)();`

### advantages

the major advantage of using `typedef` is that it improves the readability of your prg, especially when complex types are named.

one additional advantage is that u can isolate platform dependent types. when a prg is ported to another platform, u only need to change the platform dependent type once in the `typedef` definition.

## application: dynamic matrices

(715)

class Matrix

```c++

// matrix.h

```