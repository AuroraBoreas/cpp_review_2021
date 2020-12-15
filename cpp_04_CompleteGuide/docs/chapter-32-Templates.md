# templates

(742)

templates allow u to construct both functions and classes based on types that have not yet been stated. thus, templates are a powerful tool for automating program code generation.

topics:

- how to define and use function and class templates
- in addition, special options, such as default args, specialization, and explicit instantiation are covered.

## functions and class templates

(743)

template and instantiation

### motivation

c++ allows u to define templates -- parameterized families of related functions or classes:

- a `function template` defines a group of statements for a function using a parameter instead of a concrete type
- a ``class template`` specifies a class definition using a parameter instead of a concrete type.

### advantage of templates

templates are powerful programming tools

- a template need only be coded once
- a template offers uniform solution for similar problems allowing type-independent code to be tested early in the development phase
- errors caused by multiple encoding are avoided
  
### templates in the standard library

skip

## defining templates

(745)

`class template` `Stack`

```c++

// stack.h

class Stack
{
    private:
        T* basePtr;
        int max;
        int tip;
    public:
        // constructor
        Stack(int n)
        {
            basePtr = new T[n];
            max = n;
            tip = 0;
        }
        // destructor
        virtual ~Stack(){ delete[] basePtr; }
        // getter
        // setter
        // other
        bool empty(void) const { return (tip==0); }
        bool push(const T& t);
        bool pop(void);
};

template<class T>
bool Stack<T>::push(const T& x)
{
    if(tip < max - 1)
    {
        basePtr[tip++] = x; return true;
    }
    return false;
}

template<class T>
bool Stack<T>::pop(T& x)
{
    if(tip > 0 )
    {
        x = basePtr[tip--]; return true;
    }
    return false;
}

```

### defining function templates

the definition of a template is always prefixed by

`template<class T>`

where the parameter T is a type name used in that definition that follows. although **u MUST state the `class` keyword**(really? `typename` works too thou..), T can be any given type, such as an int or double.

example:

```c++

template<class T>
void exchange(T& a, T& b)
{
    T temp(a); a = b; b = temp;
}

```

the name T is common but NOT mandatory.

### defining `class template`

example:

```c+

template<class U>
class Demo
{
    U elem; .... // etc.
};

```

this defines the `class template` `Demo<U>`. both `U` and `Demo<U>` are treated like normal types in the class definition. u simply need to state the name of the template, Demo, within the class scope.

the methods of a `class template` are also parameterized via the future type. each method in a class template is a function template. if the deinition is external to the `class template`, `function template` syntax is used. the method name is prefixed by the `class template` type and the scope resolution operator.

the method of a class template are normally defined in the same header file. this ensures that the definition will be viable to the compiler, since it requires the definition to generate machine code for concrete template args.

## template instantiation

(747)

defining a template creates neither a concrete function nor a class. **the machine code for functions or methods is NOT generated until instantiation**.

developing templates will NOT reduce the amount of machine code required for a program. however, it does spare the programmer's extra work required to develop multiple versions of functions and classes.

**templates are double checked for `errors` by the compiler.**

- once when the template definition is compiled. it recognizes errors that are independent of the template parameters.
- and again during instantiation. errors in parameterization can NOT be detected until instantiation.

## template parameters

(749)

the `Stack` template with two **template parameters**

```c++

template<class T, int n>
class Stack
{
    private:
        T basePtr[n];
        int max;
        int tip;
    public:
        Stack(){ max = n; tip = 0; }
        bool empty(void) { return (tip==0); }
        bool push(const T& x);
        bool pop(T& x);
};

template<class T, int n>
bool Stack<T, n>::push(const T& x)
{
    if(tip < max - 1)
    {
        basePtr[tip++] = x;
        return true;
    }
    return false;
}

template<class T, int n>
bool Stack<T, n>::pop(T& x)
{
    if(tip > 0)
    {
        x = basePtr[--tip];
        return true;
    }
    return false;
}

```

### multiple template parameters

**a template parameter need NOT always be a type name**. normal function paramters are also permissible, particularly pointers and references.

example:

```c++

template<class T, int n>
class Stack{...};

```

this defines the `class **template`*Stack<T, n>* that is parameterized with the type T and an integer n.

this simplifies the definition of the stack template. the copy constructor, the assignment operator, and the destructor no longer need to be defined!

### restrictions

two restrictions apply to **template parameters** other than **type parameters**.

- they can NOT be modified
- they can NOT be floating-point or double types.

table: **template paramters** vs 

|  items        | type parameters   | template parameters              |
|---------------|-------------------|----------------------------------|
| restrictions  | N/A               | can NOT be modified              |
|               |                   | can NOT be float or double types |

## template args

(751)

### passing args

a template is instantiated when a template arg is passed to it. the arg types MUST exactly match to the types of the template parameters.

(wait, no implicit conversion available?)

**NOT even implicit type conversions are performed**, such as float to double.

example:

```c++

template<class T>
T min(T x, T y)
{
    return ((x < y)? x : y);
}

float x = 1.1,; double y = 7.7;
min(x, y); // not OK

```

would lead to an error message, since the template funtion can NOT be defined by the protoype: `void min(float, double);`

### restriction

there are several restrictions for template args other than types.

- if the template parameters is a **reference**, only a global or static obj can be passed as a template arg
- if the template parameter is a **pointer**, only the address of an obj or a function with gloabal scope can be stated
- if the template parameter is neither a reference nor a pointer, **only constant expressions** can be used as template args.

example:

```c++

int cnt = 256;
typedef Stack<short, cnt> ShortStack; // error

```

since only an int constant is permitted as template arg, this statement provokes an error.
`strings`, such as "Oktoberfest", are also invalid as template args, as their scope is static and not global.

example:

```c++

template<class T, char* s>class Demo{...}; // not OK

```

only gloabally defined strings can be used for instantiation

```c++

char str[] = "Oktoberfest"; // global
Demo<double, str>income; // OK

```

## specialization

(753)

function template `min()`

```c++

template<class T>
T min(T x, T y)
{
    return ((x < y)? x : y);
}

```

specializing the function template for C strings

```c++

#include <cstring>

const char* min(const char* s1, const char* s2)
{
    return ((strcmp(s1, s2) < 0)? s1 : s2);
}

```

### ANSI specialization

the ANSI standard does NOT differ btwn **template functions** and "normal" functions. the definition of a function template and a function with the same name, which can be generated by the function template, causes the compiler to output an error message(ex. "duplicate definition...")

this is why the ANSI standard provides its own syntax for defining specializations:

```c++
#include <cstring>

template<>
const char* min(const char* s1, const char* s2)
{
    return ((strcmp(s1, s) < 0)? s1 : s2);
}

```

### motivation

a **template function** can only be instantiated if all the statements contained in the function can be executed. if u call the template function `exchange()` with two obj of the same class, the copy constructor and the assignment MUST be defined for this class.

more specifically, all operators used in the **template function** MUST be defined for the current arg type. thus, the **function template** `min()`, which determines the lesser of two args, can only be instantiated if the operator < is defined for the arg type.

besides non-executable instructions there are other reasons to prevent a function template being instantiated for a particular type:

- the generic approach defined by the template does NOT return any useful results for a given type
- there are more efficient approaches for some types

the statement

example:

```c++

minStr = min(, "VIVIAN", "vivian");

```

only return the lower of the two addresses at which the C strings are stored.


### defining sepcialization

in cases like this, it makes sense to specialize the template function definition.

this also applies to the methods of a class template.

## default args of templates

(755)

a class template representing quadratic matrics

```c++
// quadMat.h

#include <iostream>
#include <stdexcept>

using namespace std;

template<class T, int cnt=10>
class QuadMatrix
{
    ...
};

```

### setting defaults

u can define default args for template args, just as for function parameters. if an arg required to instantiate a template is missing, the default value is then used.

u can specify default values in the template defintion or when u delcare a template in a module.

### the class template `QuadMatrix<T, n>`

example:

```c++

typedef QuadMatrix<> IntMat;
IntMat m;

```

**u can NOT omit the angle brackets since the `QuadMatrix` type does NOT exist**.

`QuadMatrix` is merely the name of a template.

the following definition

example:

```c++

typedef QuadMatrix<double> DoubleMat;
DoubleMat dm;

```

defines matrix `dm` of `double` values with 10 rows and 10 columns.

### rules

the same rules apply to the default args of templates as to the default args of functions:

- if u declare a default arg for  at least one parameter, u MUST define **default values** for all the remaining parameters
- if a template arg for which a default arg was declared is omitted during instantiation, all the remaining template args MUST be omit.

## explicit instantiation

(757)

sample program for the class template `QuadMatrix`

```c++

// quadmat.h
#include <stdexcept>
using namespace std;

template<class T, int cnt=10>
class QuadMatrix
{
    private:
        T arr[cnt][cnt];
    public:
        int dim() const  { return cnt; }
        T* operator[](int line) throw(out_of_range)
        {
            if(line<0 || line>=cnt)
            {
                throw out_of_range("Matrix: index out of range");
            }
            else
                return arr[line];
        }
        const T* operator[](int line) const throw(out_of_range)
        {
            if(line<0 || line>=cnt)
            {
                throw out_of_range("Matrix: index out of range");
            }
            else
                return arr[line];
        }
};

```

```c++

// main.cpp

#include "quadmat.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

template class QuadMatrix<long double, 5>;

int main()
{
    QuadMatrix(long double, 5) m;

    try
    {
        for(int i=0; i<m.dim(); ++i)
        {
            for(int j=0; j<m.dim(); ++j)
            {
                m[i][j] = i*j;
                cout << setw(2) << m[i][j] << " ";
            }
            cout << endl;
        }
    }
    catch(out_of_range& err)
    {
        cerr << err.what() << endl;
    }
    
}

```

in addition to implicit instantiation of templates, which occurs when a template function is called, for example, explicit instantiation is also possible. **this is important when u design libraries that contain template functions and classes for application programs**.

### syntax

explicit instantiation can be achieved by the following

syntax: `template declaration;`

where `declaration` contains the name of template and the template args.

explicit instantiation for the class template `Stack` would be performed as follows:

exmple: `template class Stack<long double, 50>;`

this declaration creates the **template class** `Stack<long double, 50>` with a maximum of 50 long double type elements.

function templates can also be instantiated explicitly.

example:

```c++

template short min(short x, short y);

```

### ANSI instantiation

the ANSI standard provides an additional technique for the explicit instantiation of function templates. `template args` are stated in the **angled brackets** that follow the function name, when the function is first called.

example: `min<long>(x, y);`

in this case, a template function `min()` for the long type is generated. this advanced syntax for `function templates` is **NOT supported by all C++ compilers**, however.

explicit instantiation of function templates extends their possible usage:

- `function templates` can be parameterized by types that can NOT be derived from the function args -- more specifically, `function templates` can be defined without function parameters.
- `function templates` can be defined with the function paramaters that are NOT template parameters themselves

## Summary

table: template parameters

| template parameter | catagory     |   default val     | Pointer               | Ref           | !Pointer or !Ref          |
|--------------------|--------------|-------------------|-----------------------|---------------|---------------------------|
| type               | `class`      | N/A               | N/A                   | N/A           | N/A                       |
| args               | "CSIL"       | behave like func arg | addr of func or obj with global or static | addr of global or static obj | a const expr |
|                    | !float,!double; !implicit conversion; string must be global or static | yes all or omit all  | -  | - | - |