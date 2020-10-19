# defining classes

classes are the language element in C++ most important to the support object-oriented programming(OOP).

a class defines the **properties** and **capacities** of an object.

- how to define classes
- how instances of classes are used.
- structs and unions

OOP class principles: SOLID

(注意：原则并不是规则，更不是教条，对智者来说是指导，对愚者来说是遵从。)

- SRP
- OCP
- LSP
- ISP
- DIP

```

(https://blog.csdn.net/prohorse/article/details/62929400)

DIP(依赖反转原则)
高层次的模块不应该依赖于低层次的模块，两者都应该依赖于抽象接口；
抽象接口不应该依赖于具体实现，而具体实现则应该依赖于抽象接口

解读

为了解释清楚这个应用非常广泛的原则，有必要先解释清楚几个与之经常一起出现的或容易混淆的概念：依赖注入（Dependency Injection），控制反转（Inversion of Control），面向接口编程（Programming to Interfaces），还有依赖反转原则（Dependency Inversion Principle）自己。

首先要了解反转这个术语。方向相反即为反转。在这里，依赖关系当然是有方向性的，控制关系也有方向性，所以才有依赖反转，控制反转的说法。那么反转之前的正常方向又是如何确定的？是根据结构化分析与设计技术（SADT）而来。

简而言之SADT是一种自顶向下的拆分设计方法。欲解决大问题A(设计一个大模块A)，拆分为B，C，D三个子问题（子模块），正常方式就是A依赖于（或调用）B，C，D；这个过程反过来就是反转。

依赖注入(DI)
依赖注入是关于一个对象是如何获取依赖的。常见的注入方式有：构造器注入，Setter注入，接口注入。

例如在“地产大亨”游戏里，玩家掷一对色子。在软件中，玩家对象需要向一对色子对象发出roll()消息。玩家对象如何取得对色子对象的引用？游戏系统需要告诉玩家takeATurn(:Dice)并且给玩家一对色子，这就是方法级别的依赖注入。

控制反转(IoC)
控制反转是关于谁发出调用的。也就是程序控制权的转变。如果是你写的代码发起了调用，那就不是IoC；反之，若一个容器/系统/库/框架，反过来调用你提供给它的代码，这就是控制反转。

依赖反转原则(DIP)
我们不会把台灯与墙上的电路直接焊接在一起。台灯是高层次，电路是低层次，两者依赖于插头和插座，而非直接交互。三针插头可以被台灯用，也可以被冰箱用，所以抽象接口（插头）并不依赖于具体实现（台灯/冰箱）。而冰箱因为功率较大一定用三针插头，所以具体实现依赖于抽象接口。

DIP主要目的是为了将高层模块对底层模块的依赖解耦，使得替换低层模块变得容易（即高层组件的复用性更强）。

注意：依赖反转并不是说让高层依赖低层变成了低层依赖高层，而是让高层与低层都依赖于抽象。

换言之，DIP的核心就是在高低层之间增加抽象层，而且这个抽象是由高层定义的。这里说抽象，就是指抽象这个概念，不指代任何编程技巧和方法。

```

## defining classes

definition scheme

```c++

class Demo
{
    private:
        // private data members and methods here
    
    public:
        // public data members and methods here
};

```

example of a class

```c++

// account.h
// Defining the class Account.
// ---------------------------------------------------
#ifndef _ACCOUNT_ // Avoid multiple inclusions.
#define _ACCOUNT_

#include <iostream>
#include <string>

using namespace std;

class Account
{
    private: // Sheltered members:
        string name; // Account holder
        unsigned long nr; // Account number
        double balance; // Account balance

    public: //Public interface:
        bool init(const string&, unsigned long, double);
        void display();
};

#endif // _ACCOUNT_

```

public members form the so-called `public interface` of the class

the labels `private:` and `public:` can be used at the programmer's direction within a class:

- u can use the labels as often as needed, or not at all, and in any order.
- the default value for member access is `private`. if u omit both the private and public labels, all the class members are assumed to be `private`.

methods of class Account

```c++

// account.cpp
// Defines methods init() and display().
// ---------------------------------------------------

#include "account.h" // Class definition
#include <iostream>
#include <iomanip>

using namespace std;

// The method init() copies the given arguments
// into the private members of the class.
bool Account::init(const string& i_name,
                    unsigned long i_nr,
                    double i_balance)
{
    if( i_name.size() < 1) // No empty name
        return false;
    name = i_name;
    nr = i_nr;
    balance = i_balance;
    return true;
}

// The method display() outputs private data.
void Account::display()
{
    cout << fixed << setprecision(2)
         << "--------------------------------------\n"
         << "Account holder:    " << name    << '\n'
         << "Account number:    " << nr      << '\n'
         << "Account balance:   " << balance << '\n'
         << "--------------------------------------\n"
         << endl;
}

```

## syntax

when u define a method, u MUST also supply the class name, separating it from the function name by means of the `scope resolution operation ::`.

sytax

```c++

type class_name::function_name(parameter_list)
{ ... }

```

Failure to supply the class name results in a global function definition.

within a method, *all* the members of a class can be designated directly using their names. the class membership is automatically assumed. in particular, methods belonging to the same class can call each other directly.

accessing to private members is only possible within methods belonging to the same class. thus, private members are completely controlled by the class.

defining a class does NOT automatically allocate memory for the data members of that class. to allocate memory, u MUST define an object. when a method is called for a given object, the method can then manipulate the data of the object.

## modular programming

a class is normally defined in several source files.

- place the class definition in a `header file`, for example, put `Account` class in `account.h`
- methods MUST ALWAYS be defined within a `source file`, for example, put methods in `account.cpp`
- (right-click project and add `source file` account.cpp when using **codeblock** before compilation)

alternative

- place the class definition, implementation of methods in `header file` works too.

check OOD's class creation principles: SOLID, choose what u want?

the source code of the application program, for example, the code contain the funtion `main`, is independent of the class and can be stored in separate source files. separate classes from application programs facilitates `re-use` of classes.

defining a class also defines a new type for which variables, that is, objects, can be defined. an object is also referred to as an `instance` of a class.

## defining objects

an object is defined in the usual way by supplying the type and the object name.

syntax:

```c++
class_name object_name1 [, object_name2, ...]
```

memory is now allocated for the data members of the current object. the current object itself contains the members name, nr and balance.

## object in memory

pass

## initializing object

pass

## class member access operator

an application program that manipulates the objects of a class can access only the public members of those objects. to do so, it uses the `class member access operator`(in short: `dot operator`).

syntax: `object.member`

## pointers to objects

an object of a class has a memory address -- just like any other object. u can assign this address to a suitable pointer.

exmple:

```c++

Account savings("Mac, Rita", 654321, 123.5);
Account *ptrAccount = &savings;

```

this defines the object savings and a pointer variable called `ptrAccount`. the pointer `ptrAccout` is initialized so that it points to the object savings. this makes `*ptrAccount` the object savings itself. u can then use the statement

example:

```c++
(*ptrAccount).display();

```

Parenthese MUST be used in this case, as the operator `.` has higher precedence than the `*` operator.

## arrow operator

u can use the class member access operator `->` (in short: arrow operator) instead of a combination of `*` and `.`

syntax: `objectPointer->member` is equivalent to `(*objectPointer).member`

the difference between the class member access operator`.` and `->` is that the left operand of the dot operator MUST be an object, whereas the left operand of the arrow operator MUST be a pointer to an object.

Table: `.` vs `->` operator

| difference        | `.`         | `->`                   |
|-------------------|-------------|------------------------|
| **left** operand  | an object   | a pointer of an object |

## struct

it is common practice to use the keyword `struct`, to define multiple data that belong together logically are put together.

example:

```c++

struct Date
{
    short month, day, year;
};

```

## class vs struct

u can also use the keyword `struct` to define a class, such as the class Account.

example:

```c++

class Date
{
    private:
        // ...
    public:
        // ...
};


struct Account
{
    private:
        // ...
    
    public:
        // ...
};

```

the keyword `class` and `struct` only vary with respect to data encapsulation; the default for access to members of a class defined as a `struct` is public.

in contrast to a class defined using the `class` keyword, all the class members are public.

## unions

in normal classes, each data member belonging to an object has its own separate memory space.

however, a `union` is a class whose members are stored in the same memory space. each data member has the same starting address in memory. ofc, a `union` can NOT store various data members at the same address `simultaneously`. however, a `union` does provide for more versatile usage of memory space.

## definition

syntacticall speaking, `union` is distinguished from a class defined as a `class` or `struct` only by the keyword `union`

example:

```c++

union Number
{
    long n;
    double x;
};

Number number1, number2;

```

unless a `private` label is used, all union members are assumed to be `public`. this is similar to the default setting for `struct`.

the programmer MUST ensure that the current content of the union is interpreted correctly. this is normally achieved using an additional type field that identifies the current content.

the `size` of a union type object is derived from the longer data member, as all data members begin at the same memory address.