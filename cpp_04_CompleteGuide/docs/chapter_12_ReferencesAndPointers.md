# reference and pointers

- what are references and pointers?
- how to use them as parameters and/or return values of functions.

in this context, passing by reference and read-only access to arguments are introduced.


## references

NOTE: a reference must be *initialized* when it is declared, and can NOT be modified subsequently.

in other words, u can NOT use the reference to address a different variable at a later stage.

syntax: 
```c++

// given that T is a type,
// T& denotes a reference to T.

float x = 10.7;
float& rx = x; 

// or

float &rx = x;

```

## read-only reference

a reference that addressses a const object must be a constant itself, that is, it must be defined using the const keyword to avoid modifying the object by referece.

however, it is conversely possible to use a `reference` to a constant to address a non-constant object.

example:

```c++

int a;
const int& cref = a;

```

## references as parameters

### passing by reference

a pass by reference can be programmed using references or pointers as function parameters. it is syntactically simpler to use references, although not always permissible.

a parameter of a reference type is an alias for an argument. **when a function is called, a reference parameter is initialized with the object supplied as an argument.**

the function can thus directly manipulate the argument passed to it.

example:

```c++

void test(int& a) { ++a; }

// based on this definition, the statement
test(var); // for an int variable var

// increments the variable var. 
// within the function, any access to the reference a
```

## comparison to passing by value

table: benefits of using references as parameters

| using references | benefits                                           |
|------------------|----------------------------------------------------|
| space            | arguments are not copied. memory-save              |
| return values    | return *multiple* values to the calling function.  |

if u need to read arguments, but not copy them, u can define a `read-only reference` as a parameter.

example:

```c++

void display(const string& str);

```

## returning references


example:

```c++

string& message()
{
    // why static?
    static string str = "today only cold cuts!";
    return str;
}

// this functino returns a reference to a static string, str.
// pay attention to the following point when returning reference and pointers

```

`the object referenced by the return value must exist after leaving the function`


it would be a <font color="red">critical error</font> to declare the string str as normal auto variable in the function message().

this would destroy the string on leaving the function and the reference would point to an object that no long existed.

```c++

string& message()
{
    string str = "today only cold cuts!"; // program will crash!
    return str;
}

```

## calling a reference type function

if u wanna avoid modifying the referenced object, u can define the function type as a read-only reference.

example:

```c++

const string& message(); // read-only!

```

references are commonly used as return types when overloading operators.

the operations that an operator has to perform for a user-defined type are always implemented by an appropriate function.


## expressions with reference type

example: operator `<<` of class ostream

```c++

cout << "Good morning" << '!';
```

