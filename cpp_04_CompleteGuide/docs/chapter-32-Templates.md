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

where the parameter T is a type name used in that definition that follows. although **u MUST state the `class` keyword**, T can be any given type, such as an int or double.

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

the methods of a `class template` are also parameterrized via the future type. each method in a class template is a function template. if the deinition is external to the `class template`, `function template` syntax is used. the method name is prefixed by the `class template` type and the scope resolution operator.

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

the `Stack` template with two template parameters

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
