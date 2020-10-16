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

the `<<` and `>>` operators used for stream input and output are examples of expressions that **return a reference to an object**.

example: operator `<<` of class ostream

```c++

cout << "Good morning" << '!';

// the expression is then equivalent to

(cout << " Good Morning ") << '!';

```

expressions using the `<<` operator are composed from left to right, as u can see from the table of precedence contained in appendix.

similarly, the expression `cin >> variable` represents the stream `cin`. this allows repeated use of the `>>` operator.

## other reference type operator

other commonly used reference type operators include:
- assignment operator `=`
- compound assignments, such as `+=`, `*=`

## pointers

a `pointer` is an expression that represents both the `address` and `type` of another object.

using the address operator, `&`, for a given object creates a pointer to that object.

`pointer types` are derived types. the general form is `T*`, where T can be any given type.

after  declaring a pointer variable, u **MUST** point the pointer at a memory address.

## references and pointers

references are similar to pointers: both refer to an object in memory.

however, a pointer is NOT merely an alias but an individual object that has an identity separate from the object it references.

a pointer has its own memory address and can be manipulated by pointing it at a new memory address and thus referecing a different object.

(https://www.educba.com/c-plus-plus-reference-vs-pointer/)

Table: refereces vs pointers

| items             | references                           | pointers                                                            |
|-------------------|--------------------------------------|---------------------------------------------------------------------|
| definition        | variable's address itself            | an independent variable which stores other variable's address       |
| declaration       | `T& rvar = var;`                     | `T* ptr = &var;    `                                                |
| reassignment      | N/A                                  | Allowed                                                             |
| memory address    | NOT have independent addr            | have independent addr                                               |
| NULL value        | NO                                   | YES. can be assigned to NULL                                        |
| as argument       | YES                                  | YES                                                                 |
| usage             | function parameters, reference types | implement data structures, functions, pointer arithmetic operations |


## indirection operator

example:

```c++

double x, y, *px;

px = &x;
*px = 12.3;
*px += 4.5;
y = sin(*px);

```

notes on addresses in a program

- each `pointer variables` occupies the same amount of space, independent of the type of object it references. it means, it occupies as much space as is necessary to store any address.
- the addresses visible in a program are normally `logic addresses` that are allocated and mapped to physical addresses by the system. merit: efficient storage management and the swapping of currently unused memory blocks to the hard disk.
- C++ guarantees that any valid address will NOT be equal to 0.

## using pointers to access objects

the `indirection operator *` is used to access an object referenced by a pointer.

given a pointer, `prt`, `*ptr` is the object referenced by `ptr`.

as a programmer, u MUST ALWAYS distinguish between the pointer `ptr` and the address object `*ptr`.

example:

```c++

long a = 10, b, *ptr;

ptr = &a; // address of variable a
b = *ptr; // b = 10;

```

the start character `*` used for defining pointer variables is NOT an operator but **merely imitates the later use of the pointer in expressions**.

thus, the definition `long *ptr` has the following meaning:

`ptr` is `long*` type; and `*ptr` is a long type.

the indirection operator `*` has high precedence, just like the address operator `&`. both operators are unary, that is, they have only one operand.

## L-values

an expression that identifies an object in memory is known as an `L-value` in C++.

the `left` operand of the `=` operator MUST ALWAYS deisgnate a memory address.

expressions other than an `L-value` are often referred to as `R-value`.

## objects as arguments

if an object is passed as an argument to a fucntion, two possible situations occur:

- the parameter in question is the same type as the object passed to it.
- the paramater in question is a reference.

in the first case, the argument passed to the function can NOT be manipulated by the function. this is NOT true for passing by reference.

however, there is a third way of passing by referece--passing pointers to the function.

## pointers as arguments

how to pass an address to function as an argument?

answer is simple: the parameter MUST be declared as a `pointer variable`

example:

```c++

long func(int* iPtr)
{
    // function block
}

```

if a function knows the address of an object, it can of course use the indirection operator to access and manipulate the object