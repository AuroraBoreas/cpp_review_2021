# exception handling

(628)

topics:

- how a c++ program uses error-handling techniques to resolve error conditions
- throwing and catching exceptions
- also examine how exception specifications are declared and exception classes are defined
- additionally looking into the use of standard exception classes.

## traditional error handling

(629)

error checking after leaving a function.

### error conditions

errors that occur at program runtime can seriously interrupt the normal flow of a program. some common causes of errors are

- division by 0, or values that are too large or small for a type
- no memory available for dynamic allocation
- errors on file access, for example, file not found
- attempt to access an invalid address in main memory
- invalid user input

anomalies like these lead to incorrect results and may cause a computer to  crash. both of these cases can have fatal effects on application.

**one of the programmer's most important tasks is to predict and handle errors**. u can judge a program's quality by the way it uses error-handling techniques to counteract any potential error, although this is by no means easy to achieve.

### traditional error handing

traditional structured programming lang use normal syntax to handle errors:

- errors in functinon calls are indicated by special return values
- global error variables or flags are set when errors occur, and then checked again later.

if a function uses its return value to indicate errors, the return value MUST be examined whenever the function is called, even if no error has occurred.

example:

```c++

if(func()>0)
    // ...
else
    // ...

```

error variables and flags MUST also be checked after **every** corresponding action.

in other words, u need to continually check for errors while a program is executing. if u do happen to forget to check for errors, the consequences may be fatal.

## exception handlings

(631)

using `throw` statement.

### exception handling concept

c++ introduces a new approach to error handling. `exception handling` is based on keeping the normal functionality of the program separate from error handling. **the base idea is that errors occuring in one particular part of the program are reported to another part of the program, known as the `calling environment`**. the calling environment performs central error handling.

an application program no longer needs to continually check for errors, because in the case of an error, control is automatically transferred to the calling environment. when reporting an error, specific information on the error cause can be added. this information is evaluated by the error-handling routines in the calling environment.

### the `throw` statement

an exception that occurs is recorded to the calling environment by means of a `throw` statement, this is why we also say that an exception has been *thrown*.

syntax: `throw fault;`

the expression `fault` is an ``exception obj`` that is thrown to the calling environment. it can belong to any type except `void`.

example: `throw "File!";`

### exception classes

normally, u define your own exception classes to categorize exceptions. in this case, u use the `throw` statement to throw an obj belonging to a specific exception class.

**an exception class need NOT contain data members or methods**. however, **the `type`, which is used by the calling environment to identify the error, is important**. generally, the exception class will contain members that provide more specific information on the cause of the errror.

## exception handlers

(633)

syntax of `try` and `catch` blocks

```c++
try
{ // ... }
catch(Type1 exc1)
{ // ... }
[ catch(Type2 exc2)
  { // ... }
]
[ catch( ... )
  { // ... }
]
```

### how exception handling works

the part of a program that performs central error handling in the calling environment is referred to as an `exception handler`. an exception handler catches the `exception obj` throw to it and performs error handling. the `exception obj` type determines which handler will catch it and consequently be executed.

this means that u need to specify two things when implementing exception handling:

- the part of the program that can throw exceptions
- the exception handlers that will process the various exception types.

c++ provides lang delements for this task, the keywords `try` and `catch`. each keyword precede a code block and thus they are often referred to as `try` and `catch` blocks. syntactically speaking, each `try` and `catch` block is a statement, however.

### `try` and `catch` blocks

a `try block` contains the program code in which errors can occur and exceptions can be thrown. normally, a `try block` will consist of a group of functions that can produce similar errors.

each `catch block` defines an exception handler, where the `expression declaration`, which is enclosed in parentheses, defines the type of exceptions the handler can catch. the `catch blocks` immediately follow the `try block`. a minimum of one `catch block` is required.

the exception handlers defined by the `catch blocks` catch the `exceptions` thrown within the `try block`. if there is no handler defined for a particular exception type, the program will NOT simply enter an undefined state but will be orderly terminated by a call to the standard function `terminate()`.

syntax:

```c++

catch(...)
{
    // ...
}

```

since the application program decides what reaction is applicable for certain error conditions, the `try block` and `catch block` are formulated in the application.

[reference]

```python

raise ValueError(...)
raise FileNotFoundError(...)
raise FileExistError(...)
raise IndexError(...)
raise ZeroDividedError(...)
...

```

## throwing and catching exceptions

(635)

```c++
// main.cpp

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

class Error
{
    //...
};

double calc(int, int);

int main()
{
    int x, y;
    double res;
    bool flag = false;

    do
    {
        try
        {
            cout << "Enter two positive integers: ";
            cin >> x >> y;
            res = calc(x, y);
            cout << x << "/" << y << " = " << std::fixed << std::setprecision(2) << res << endl;
        }
        catch(string& s)
        {
            cerr << s << endl;
        }
        catch(Error&)
        {
            cerr << "Division by 0" << endl;
        }
        catch(...)
        {
            cerr << "unexpected exception";
            exit(1);
        }
    } while(!flag);

    return 0;
}

double calc(int a, int b)
{
    return ((double)a/b);
}

```

### backing out of an error condition

when the `throw` statement is executed, an `exception obj` is thrown. that is, a temporary obj of the same type and content as `throw` expression is created.

example: `throw "cyclone!";`

this creates a string as an `exception obj` and copies the string "cyclone!" to it. thus, if the `throw` expression is a class type, the copy constructor is executed.

### continuing the program

after executing a handler, the program continues with the first statement following the `catch blocks`, unless the handler throws another exception or terminates the program. after completing exception handling, the `exception obj` that was thrown is destroyed.

## nesting exception handling

(637)

nested `try block` and `catch block`

```c++

try
{
    // type1 exceptions are thrown here
    try
    {
        // type1 and type2 exceptions are thrown here
        //...
    }
    catch(Type2 e2)
    {
        // type2 exceptions are pre-handled here
        //...
        throw; // and thrown again
    }
}
catch(Type e1)
{
    // type1 exceptions are handled here
    //...
}
catch(...)
{
    // all remaining exceptions are handled here
    //...
}

```

### nested `try` and `catch` blocks

a program will normally contain multiple `try blocks` with appropriate exception handlers. this allows for various error handling in different parts of the program.

however, a `try block` can contain additional `try block`. this allows u to use the handers in a nested `try block` for special purpose error handling, leaving the handlers in the surrounding `try block` to deal with remaining errors. handlers in a nested `try block` can also pre-handle specific errors and then pass control to the `try block` wrapper for final handling.

### re-throwing exceptions

in the last of these cases an exception thrown by the nested `try block` has to be passed to the `try block` wrapper. this is achieved using a `throw` statement that does NOT expect an exception obj.

example: `thorw; // in a catch block`

this **re-throws** the pre-handled exception, which can then be processed by the handler in the surrounding `try block`. the statement is only valid within a nested `catch block` for this reason.

### exception specifications

the exceptions that a function can throw are features of that functions. the application programer MUST have knowledge of both the function prototype and the exceptions the function can throw to ensure that he or she will be capable of programming correct function calls and taking appropriate action in cause of errors.

the exceptions a function can throw can be stated in a so-called `exception specification` when u declare a function.

example: `int func(int) throw(BadIndex, OutOfRange);`

the list BadIndex, OutOfRange states the exceptions that the function `func()` can throw. if the list is empty, that is, if the list contains only the `throw()` statement, no exceptions are thrown. if the `throw` statement is also missing, there is no specific information about possible exceptions and any exception can be thrown.

## defining your own error classes

(639)

exception handling for numeric operations

### exception class members

when an exception is thrown, the exception obj type determines which exception handler will be executed. for this reason, an exception class does NOT need to have any members.

however, an exception class can contain data members and methods -- just like any other class. this make sense, as locally defined non-static obj are destroyed when an exception has been thrown and the stack is unwound. thus, the exception handler can no longer access the previously existing objects.

u can use the data members of error classes to rescue data threatened by an error condition.

### the exception class `MathError`

pass

### exception hierarchies

new exception classes can be derived from existing exception classes. **a base class will normally represent a general error type and specific errors will be represented by derived classes**.

ba aware of the following rules for exception handlers in this context:

- given that T is derived exception class, special errors of this type are handled by the exception handler
- if T is a base class, the handler will also catch the exception obj thrown by derived classes, thus providing similar handling for generic and specific errors

## standard exception classes

(641)

exception classes **derived from** `logic_error`

| exception class       | explanation                                 |
|-----------------------|---------------------------------------------|
| invalid_argument      | invalid argument                            |
| out_of_range          | argument value NOT in its expected range    |
| length_error          | length exceeds maximum capacity             |
| domain_error          | domain error reported by the implementation |

exception classes **derived from** `runtime_error`

| exception class       | explanation                                 |
|-----------------------|---------------------------------------------|
| range_error           | range error in internal computation         |
| underflow_error       | arithmetic underflow error                  |
| overflow_error        | arithmetic overflow error                   |

### hierarchy of standard exception classes

the c++ standard library contains various exception classes, which are used in the string and container libraries, for example. however, the standard exception classes can be used just like exception classes of your own. their definitions are to be found in the header file `stdexcept`.

the standard exception classes are organized in a hierarchy, the common base class being the `exception` class. in addition to a default constructor, a copy constructor, and an assignment, this class contains a virtual `public` method, `what()`, which returns a message on error cause as a C string.

### representing logic errors and runtime errors

the following exception classes are derived from the `exception` class:

table: `logic_error` and `runtime_error`

| derived classes       | usage                                                                                                                    |
|-----------------------|--------------------------------------------------------------------------------------------------------------------------|
| `logic_error`         | used to represent logic errors, caused by anomalies in the program's logic. these errors can be avoided.                 |
| `runtime_error`       | used to represent errors, such as under or overflows occurring in internal computations. there errors are unpredicatable.|
