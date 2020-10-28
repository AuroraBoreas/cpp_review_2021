# overloading operators

(432)

overloading operators allows u to apply existing operatiors to objects of class type.

topics:

1. various uses of overloaded operators
2. arithmetic operators, comparisons, the subscript operators, and the shift operators for input and output are overloaded to illustrate the appropriate techniques.
3. the concept of friend functions, is particularly important for overloading operators.

## generals

(433)

### rules

the following rules apply when overloading:

- u can NOT create "new operators" -- that is, u can only overload existing operators
- u can NOT redefine the operators for fundamental types
- u can NOT change the operands of an operator. a binary operator will always be binary and a unary operator will always be unary
- the precedence and the order of grouping operators of the same precedence remains unchanged.

**in one word, confers overloading concept to operators but can NOT change fundamental concepts.**

### overloading

an operator is said to be overloaded if it is defined for multiple types. in other words, **overloading an operator means making the operator significant for a new type**.

most operators are already overloaded for fundamental types.

### operators for classes

in addition to defining methods, C++ offers the interesting possibility of defining the functionality of a class by means of operators. thus, u can overload the + operator instead of, or in addition to, using the `add()` method.

example:

```c++

obj x, y;
x + y // is equivalent to x.add(y)

```

Table: operators can NOT be overloaded

| operator        | meaning                       |
|-----------------|-------------------------------|
| `::`            | scope resolution              |
| `Cls.member`    | member access                 |
| `?:`            | ternary operator              |

## operator function(1)

stitching monster

### naming operator functinos

to overload an operator, u just define an appropriate `operator function`. the operator function describes the actions to be performed by the operator. the name of an operator function MUST begin with **the `operator` keyword followed by the operator symbol**.

example:

```c++
// daytime.h

class DayTime
{
    private:
        // ...
    public:
        // ...
        bool operator<(const DayTime&) const;
        DayTime& operator++(void); // how to differentiate prefix vs postfix thou?
};

```

### operator functinos as methods

if u define the operator function of a `binary` operator as a method, 

- the left operand will always be an object of the class in question. 
- the operator function is called for this object. 
- the second, right operand is passed as an argument to the method.
- the method thus has a single paramter.

example:

```c++
// daytime.h
bool operator<(const DayTime&) const;

```

### calling an operator function

example:

```c++
// test.cpp

DayTime depart1, depart2(6, 30, 0);
depart1 < depart2;

// compiler will attempt to locate an applicable operator function for this expression and then call the function.
// the expression is equivalent to
depart1.operator<(depart2);

// although somewhat uncommon, u can call an operator function explicitly. the previous function call is therefore technically correct.

```

merit: programs that use an operators are easier to encode and read.

NOTE: u should be aware of the fact that an operator functino should perform a similar operation to the corresponding operator for the fundamental type. any other use can lead to confusion. consistency :^)

example:

```c++
// misleading operator function

class MyClass
{
    private:
        int a;
    public:
        MyClass(int i) : a(i) { }
        bool operator<(const MyClass& z) { return this->a != z.a; }; // ???
        int operator+(const MyClass& z)  { return this->a - z.a; };  // ???
};

```

## operator function(2)

(437)

### 

## using overloaded operators

## global operator functions

## friend functions

## friend classes

## overloading subscript operators

## overloading shift-operators for I/O