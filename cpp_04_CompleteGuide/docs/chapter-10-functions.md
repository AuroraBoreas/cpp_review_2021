# functions

topics

- passing arguments
- definition of inline functions
- overloading functions and default arguments
- the principle of recursion

## libraries

a C++ program will be made up of

- language elements of the C++ code
- global functions and classes from the C++ stdlib
- functions and classes u have programmed yourself and other libraries.

## definition

general form of a function

```c++

[type] name([declaration_list])
{
    ...;
    what will be done; // function block
    ...;
}

```

## prototype and definition

design pattern

- prototype [type] name([declaration_list])
- return    ...


## passing by value

passing by value does, however, offer some important advantage:

- function arguments can be any kind of expression, even const
- the called function cannot cause accidental modificatino of the arguments in the calling function
- the parameters are available as suitable variable within the functions. additional indirect memory access is unnecessary.


however, the fact that copying larger objects is difficult can be a major disadvantae, and for this reason vectors are passed by reference to their starting address.

## jumping to sub-routines

when a function is called, the program jumps to a sub-routine, which is executed as follows:

- the function parameters are placed on the stack and initialized with appropriate arguments
- the so-called return address, that is, the place where the function was called, is stored on the stack and program flow branches to the function
- after executing the function the program uses the return address it stored previously to return to the calling function. the part of the stack occupied by the function is then released.
  
all this jumping-back-and-forth can affect the runtime of your program, especially if the function contains only a few instructions and is called quite often.

the time taken to branch to a small function can be greater than the time needed to execute the function itself.

however, u can define `inline` functions to avoid this problem.

## in-line definition

example

```c++

inline int max(int x, int y) { return (x >= y ? x : y); }

```

the program code will expand each time an `inline` function is called.

this is why `inline` functions should **contain no more than one or two instructions**.

if an `inline` function contains too many instructions, the compiler may ignore the inline keyword and issue a warning.

NOTE: an inline functino must be defined in the source file in which it is called.

you can NOT simply supply a prototype of the function.

the code containing the instructions must also be available to the compiler.

it therefore makes sense to define inline functions in header files, in contrast to "normal" functions. this means the function will be available in several source files.

## inline functions and macros

(P201)

**inline functions are an alternative to macros with parameters**.

with a macro is called, the preprocessor simply replaces a block of text.

in contrast, an inline function behaves like a normal function, although the program flow is NOT interrupted by the function branching. the compiler performs a type check too.

## possible calls

- you must first supply any arguments that do not have default values
- you can supply arguments to replace the defaults
- if you omit an argument, you must also omit any following arguments

## overloading functions

example

```c++

int max(int x, int y);
double max(double x, double y);

```

## function signatures

a function signatuer comprises:

- the number of parameters
- the type of parameters 

the compiler uses a function's signature to differentiate btwn overloaded functons.

```c++

int search(string key);
string search(string name);

```

both functions have the same signature and can NOT be overloaded.

why?

the signature does not contain the function type, since u can NOT deduce the type by calling a function.

it is therefore impossible to differentiate btwn overloaded functions by type.
