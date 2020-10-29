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

### notes on the sample class `euro`

```c++
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class Euro
{
    private:
        // data members; visible for all things inside this class
    public:
        //
    void print(ostream& os) const
    {
        os << asString() << " Euro\n";
    }
    string asString() const
    {
        stringstream ss;
        long temp = data;
        if(temp<0) { temp = -temp; ss << '-'; }
            ss << (temp/100) << ',' << (temp%100);
            return ss.str();
    }
};

// but what the fuck is this line?

Euro retail;
retial += 9.49; // wtf?

```

## using overloaded operators

(439)

[explanatino]

why tf `retail += 9.49` is valid?

the compiler attempts to locate an operator function that is defined for both `Euro` object and the double type for `+=`. since there is no operator function with these characteristic, **the compiler converts the `double` value to `Euro`** and calls the existing operator function for euros.

### symmetry of operands

the available constructors also allow u to call the operator functions of `+` and `-` with `int` or `double` type arguments.

example:

```c++

retail = wholesale + 10;
wholesale = retail - 7.99;

// are equivalent to

retail = whosale.operator+(Euro(10));
wholesale = retail.operator-(Euro(7.9));

```

## global operator functions

(441)

operators overloaded by methods only

| operators   | meaning                |
|-------------|------------------------|
| `=`         | assignment operator    |
| `()`        | function call          |
| `[]`        | subscript operator     |
| `->`        | class member access    |


### operator functions: global or method?

u can define an operator function as a global function instead of a method(local ofc). the four operators listed opposite are the only exceptions.

`+=     -=      *=      /=      %=`

[explanation]

why `+= -= *= /= %=` 4 operators are method only?

**these operators always require so-called `l-value` as their left operand**, that is, they require an object with an address in memory.

global operator functions are generally preferable if one of the following situations applies:

1. the operator is binary and both operands are **symmetrical**, e.g. the arithmetic operators `+` or `*`
2. the operator is to be overloaded for another class **without changing that class**, e.g. the `<<` operator for the `ostream` class.

### defining global operator functions

example:

```c++
// euro.h
#ifndef EURO_H_INCLUDED
#define EURO_H_INCLUDED
class Euro
{
    //...
};

inline Euro operator+(const Euro& e1, const Euro& e2)
{
    Euro temp(e1);
    temp.data += e.data;
    return temp;
}

inline Euro operator-(const Euro& e1, const Euro& e2)
{
    Euro temp(e2);
    temp.data -= e.data;
    return temp;
}
#endif // EURO_H_INCLUDED

```

using overloaded operators.

example:

```c++
// test.cpp

Euro net(30, 0);
net + 1.20;
1.20 + net;

// are equivalent to

operator+(net, 1.20) // and
operator+(1.20, net)

```

however, a global function can NOT access the private members of the class.

a global operator function can be declared as a `friend` of the class to allow it access to the private members of that class.

## `friend` functions

(444)

### the `friend` concept

if functions or individual classes are used in conjunction with another class, u may want to grant them accesss to the `private` members of the class. this is made possible by a `friend declaration`, which elimiates data encapsulation in certain case.

### declaring friend functions

a cass can grant any function a special permit for direct access to its private members. this is achieved declaring the function as a `friend`. the `friend` keyword MUST precede the function prototype in the class definition.

example:

```c++

class A
{
    // ...
    // --- global function ---
    // since these functions are NOT methods of class A, the `this` pointer is NOT available to them.
    // to resolve this issue, u will generally pass the object the function needs to process as an argument.
    friend void globFunc(A* objPtr);
    friend int  B::elFunc(const A& objRef);
};

```

**it is important to note that `the class itself` determines who its friends are**. if this were not so, data encapsulation could easily be undermined.

BUT, wait a second.

how can i differentiate a method vs friend functions in the first place?

## friend classes

(445)

### declaring friend classes

u can also make enture classes "friends" of another class. all the methods in this "friendly" class automatically become `friend` functions in the class containing the `friend` declaration.

this technique is useful if a class is used in such close conjunction with another class that `all` the methods in that class need access to the private members of the other class.

example:

```c++
// result.h
#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED

#include <string>
using namespace std;

class Result
{
    private:
        // ...
    public:
        // ...
        friend class ControlPoint;
};

class ControlPoint
{
    private:
        string name;
        Result measure[100];
    public:
        // ...
        bool statistic(); // can access the private members of measure[i]
};

#endif

```

it is important to note that the `ControlPoint` class has NO influence over the fact that it is a friend of the `Result` class. the `Result` class itself decides who its friends are and who has access to its private members.

it does NOT matter whether a `friend` declaration occurs in the `private` or `public` section of a class. however, **u can regard a `friend` declaration as an extension of the public interface**. for this reason, it is preferable to place a friend declaration in the public area of a class.

[when to use `friend` technique]

more specifically, u can utilize global `friend` functions where methods are NOT suited to the task in hand. some common uses are **global operator functions** declared as `friend` functions.

[explanation]

why should not abuse `friend` techniques?

extensive use of `friend` techniques diffuse the concept of data encapsulation. allowing external functions to manipulate internal data can lead to inconsistency, especially if a class is modified or extended in a later version. for this reason, u should take special care when using `friend` techniques.

(**Chees Queen** @Netflex is amazing. it touches my heart even though it's a heroin story.)

make summary to rule out confusion

Table: diff btwn **method** vs **global** vs **friend**

| item              | method                | global operator overload                | friend operator overload                    |
|-------------------|-----------------------|-----------------------------------------|---------------------------------------------|
| what              | member func of a cls  | as its name shows..                     | move global-op-ol to class                  |
| why               | do things             | make class acting like builtin type     | kankanbi..                                  |
| how               | N/A                   | using `inline` keyword on global func   | using `friend` to access private in class   |
| when to use       | anytime               | symmetrical op, or w/o class change     | access private data members of a class      |
| where             | in class              | global namespace                        | in class                                    |
| access private?   | YES                   | NO                                      | YES                                         |
| ol all operators? | No. especially:       | NO. except in-place op ol               | NO. ol most                                          |
|                   | `=, (), [], ->`       |                                         |                                             |
|                   | `+=, -=, *=, /=, %=`  |                                         |                                             |
| CAN NOT ol op?    | `::, cls.member, :?`  | `::, cls.member, :?`                    | `::, cls.member, :?`                        |

## overloading subscript operators

(447)

example:

```c++
// array_t.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define MAX 100;

class FloatArr
{
    private:
        float v[MAX];
    public:
        float& operator[](int i);
        static int getMaxIndex(void) { return MAX-1; }
};

float& FloatArr::operator[](int i)
{
    if(i<0 || i>=MAX)
    {
        cerr << "\nError, index is out of range!" << endl;
        exit(1);
    }
    return v[i];
}

```

### subscript operator []

the subscript operator[] is normally used to access a single array element. it is a binary operator and thus has two operands.

- unary operator `-, +` etc
- binary operator `+=` etc
- ternary operator `?:` etc

## overloading shift-operators for I/O