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

static vs extern


## namespace

using global names in large-scale projects can lead to conflict, especially when multiple class libraries are in operations.

C++ provides for the use of namespaces in order to avoid naming conflicts with global identifiers.

with a namespace, u can use identifiers w/o needing to check whether they have been defined previously in an area outside of the namespace. thus, the global scope is subdivided into isolated parts.

a normal namespace is identified by a name preceded by the namespace keyword.

the elements that belong to the namespaces are then declared within braces.

example:

```c++
namespace myLib
{
    int count;
    double calcualte(double, int);
    // ...
}

// outside of myLib
myLib::count = 7;

// not belonging to any namespace
::demo();

```

be aware of the following when using namespaces:
- namespaces do not need to be defined contiguously. u can reopen and expand a namespace u defined previously at any point in a program
- namespaces can be nested, that is, u can define a namespace within another namespace.

## `using` keyword

a `using` declaration makes an identifier from a namespace visible in the current scope.

u can simplify access to the element of a namespace by means of a `using declaration` or `using directive`. in this case, u do NOT need to repeatedly quote the namespace. just like normal declarations, `using` declarations and `using` directives can occur at any part of the program.

### `using` declarations

a `using` declaraction makes an identifier from a namespace visible in the current scope.

example:

```c++

using myLib::calculate; // declaration

```
### `using` directive

the using directive allows u to import **all** the identifiers in a namespace.

example:

```c++

using namespace myLib;

```

# understand `storage classes` in C++ with example

credit: geeksforgeets

link: https://www.geeksforgeeks.org/storage-classes-in-c-with-examples/

### what is `storage classes`

**storage classes** are used to describe the features of a variable/function. 

### why?

these features basically include the scope, visibility and life-time which help us to trace the existence of a particular variable during the runtime of a program.

### how?

to specify the storage class for a variable, the following syntax is to be followed:

syntax:

```c++

storage_class var_data_type var_name;

```

### details

C++ uses 5 storage classes, namely:

1. auto
2. register
3. extern
4. static
5. mutable

table: C++ storage class

| storage class | keyword   | Lifetime        | Visibility | Initial Value |
|---------------|-----------|-----------------|------------|---------------|
| Automatic     | auto      | function block  | Local      | Garbage       |
| External      | extern    | whole program   | Global     | Zero          |
| Static        | static    | whole program   | Local      | Zero          |
| Register      | register  | function block  | Local      | Garbage       |
| Mutable       | mutable   | class           | Local      | Garbage       |

#### auto

the `auto` keyword provides `type inference` capabilities, using which automatic deduction of the data type of an expression in a programming language can be done.

this consumes less time having to write out things the compiler already knows. as all the types are deduced in compiler phase only, the time for compilation increase slightly but it does NOT affect the runtime of the program.

this feature also extends to functions and non-type template parameters.

```
since C++14 for functions, the return type will be deduced from its return statements. 
since C++17, for non-type template parameters, the type will be deduced from the argument.
```

example:

```c++

#include <iostream>
using namespace std;

void autoStorageClass()
{
    cout << "Demonstrating auto class \n";
    // declaring an auto variable
    // no data-type declaration needed
    auto a = 32;
    auto b = 3.2;
    auto c = "geeksforgeeks";
    auto d = 'G';
    auto e = 1, f = 2.0, g = 'x'; // exception

    // printing the auto variables
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << d << "\n";
}


int main()
{
    // demonstrates auto Storage Class
    autoStorageClass();

    return 0;
}

```

#### extern

`extern` storage class simply tells us that the variable is defined elsewhere and not within the same block where it is used. basically, the value is assigned to it in a different block and this can be overwritten/changed in a different block as well.

so an `extern` variable is nothing but a global variable initialized with a legal value where it is declared in order to be used elsewhere. it can be accessed within any function/block.

also, a normal global variable can be made extern as well by placing the `extern` keyword before its declaration/definition in any function/block.

this basically signifies that we are NOT initializing a new variable but instead we are using/accessing the global variable only.

the main purpose of using extern variables is that they can be accessed between two different files which are part of a large program.

example:

```c++
#include <iostream>
using namespace std;

// declare the variable 
// which is to be made extern an initial value
// can also be initialized to x

int x;

void externStorageClass()
{
    cout << "Demonstrates extern class \n";

    /*
    telling the compiler that the variable z
    is an extern variable and has been defined elsewhere
    (above the main function)
    */
   extern int x;

   // printing the extern variables 'x';
   cout << "value of the variable 'x' "
           "declared, as extern: " << x << endl;
   // value of extern variable x modified
   x = 2;

   // printing the modified values of extern variables 'x'
   cout << "Modified value of the variable 'x'"
           " declared as extern: \n" << x;

}

int main()
{
    externStorageClass();
    
    return 0;
}

```

#### static

static storage class is used to declare static variables which are popularly used while writing programs in C++ language.

static variables have a property of preserving their value even after they are out of their scope!

hence, static variables preserve the value of their last use in their scope. 

<font color="blue">so we can say that they are initialized only once and exist until the termination of the program</font>. thus, no new memory is allocated because they are NOT re-defined.

their scope is local to the function to which they were defined.

globa static variables can be accessed anywhere in the program.
by default, they are assigned the value 0 by the compiler.

example

```c++

#include <iostream>
using namespace std;

int staticFunc()
{
    cout << "For static variables: ";
    static int count = 0;
    count++;

    return count;
}

int nonStaticFunc()
{
    cout << "For non-static variables: ";
    int count = 0;
    count++;

    return count;
}

int main()
{
    // calling the static parts
    cout << staticFunc() << "\n"; // 1
    cout << staticFunc() << "\n"; // 2

    // calling the non-static parts
    cout << nonStaticFunc() << "\n"; // 1
    cout << nonStaticFunc() << "\n"; // 1

    return 0;
}


```

#### register

register class declares register variables which have the same functionality as that of the auto variable. 

the only difference is that the compiler tries to store these variables in the register of the microprocessor if a free register is available.

this makes the use of register variables to be much faster than that of the variables stored in the memory during the runtime of the program.

if a free register is not available, these are then stored in the memory only.

usually, a few variables which are to be accessed very frequently in a program are declared with the register keyword which improves the running time of the program.

an important and interesting point to be noted here is that we cannot obtain the address of a register variable using pointers.

example

```c++
#include <iostream>
using namespace std;

void registerStorageClass()
{
    cout << "Demonstrate register class \n";
    register char b = 'G';
    cout << "Value of the variable 'b' declared as register:"
         << b << endl;
}

int main()
{
    registerStorageClass();
    return 0;
}
```

#### mutable

sometimes there is a requirement to modify one or more data members of class/struct through const function even though u don't want the function to update other members of class/struct.

this task can be easily performed by using the mutable keyword.

the keyword mutable is mainly used to allow a particular data member of const object to be modified.

when we declare a function as const, this pointer passed to function becomes const.

adding mutable to be a variable allows a const pointer to change members.

example

```c++
#include <iostream>
using std::cout;

class Test{
    public: int x;
    // defining mutable variable y
    // now this can be modified
    mutable int y;

    test()
    {
        x = 4;
        y = 10;
    }
}

int main()
{
    // t1 is set to const
    const Test t1;
    
    // trying to change the value
    t1.y = 20;
    cout << t1.y;

    // uncommenting below lines
    // will throw error
    // t1.x = 8;
    // cout << t1.x;

    return 0;
}

```