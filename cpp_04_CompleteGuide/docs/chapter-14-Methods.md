# methods

here we go brrr

- how constructors and destructors are defined to create and destroy objects
- how inline methods, access methods, and read-only methods can be used
- the pointer `this`, which is available for all methods, and
- what u need to pay attention to when passing objects as arguments or returning objects
  
## constructor calls

unlike other methods, constructors can NOT be called for existing objects.

for this reason, a construtor does NOT have a return type. instead, a suitable constructor is called once only when an object is created.

syntax: `class object(initializing_list);`

during initialization the compiler looks for a constructor whose signature matches the initialization list. after allocating sufficient memory for the object, the constructor is called.

the values in the initialization list are passed as arguments to the constructor.

or syntax: `class object = initializing_value;`

example:

```c++

int i(0);   // copy constructor
int i = 0; // assignment

```

## default constructor

a constructor *without* parameter is referred to as a `default constructor`.

the default constructor is only called if an object definition does NOT explicitly initialize the object. A default constructor will use standard values for all data member.

if a class does NOT contain a constructor definition, the compiler will create a minimal version of the default constructor as a public member. however, this constructor will NOT perform initialization.

by contrast, if a class contains *at least* one constructor, a default constructor MUST be defined explicitly, if it needed.

## destructors

objects that were created by a constructor MUST also be cleaned up in an orderly manner. the tasks involved in cleaning up include `releasing memory` and `closing files`, AKA, `resource management`.

objects are cleaned up by a special method call a `destructor`, whose name is made up of the class name preceded by `~` tilde.

syntax: `~class_name(void);`

yeah, just an opposite syntax of `constructor`.

symbol `~` tilde is used as `flip` in bitwise operation too.

Table: constructor vs destructor

| items         | constructor       | destructor               |
|---------------|-------------------|--------------------------|
| return type   | N/A               | N/A                      |
| parameter     | YES               | No(can't be overloaded)  |
| how many?     | as many as u like | only ONE                 |

if the class does NOT define a destructor, the compiler will create a minimal version of a destructor as public member, called `default destructor`.

it is important to define a destructor if certain actions performed by the constructor need to be undone. if the constructor opened a file, for example, the destructor should close that file.

the individual data members of an object are always removed in the order opposite of the order in which they were created.

(yeah, because data members are in `stack`)

## calling destructors

a destructor is called automatically at the end of an object's life:

- for local objects except objects that belong to the `static` storage class, at the end of the code block defining the object.
- for `global` or `static` objects, at the end of the program.

## inline methods

a class typically contains multiple methods that fulfill simple tasks, such as reading or updating data members. this is the only way to ensure data encapsulation and class functionality.

however, continually calling "short" methods can impact a program's runtime. in fact, saving a re-entry address and jumping to the called function and back into the calling functino can take more time than executing the function itself.

to avoid this overhead, u can define inline methods in a way similar to define inline global functions.

## explicit and implicit `inline` methods

methods can be explicitly or implicitly defined as `inline`. in the first case, the method is declared within the class, just like any other methods. u simply need to place the `inline` keyword before the method name in the function header when defining the method.

example:

```c++
//account.h

class Account
{
    private:
        //
    public:
        void display(void);
};

inline void Account::display() { ... };

```

since the compiler MUST have access to the code block of an `inline` function, the `inline` function should be defined in the header file containing the class definition.

(according to `inline` definition: **inline function is just an alternative to macro with parameters**, it makes sense.)

(P294)

short methods can be defined within the class. Methods of this type are known as implicit inline methods, although the inline keyword is NOT used.

example:

```c++
// account.h

class Account
{
    private:
        // ...
    public:
        // ...
        bool isPositive() { return state > 0; } // implicit inline methods. inline is NOT used though.
};

```

## constructor and destructor with `inline` definitions

constructors and destructors are special methods belonging to a class and, as such, can be defined as `inline`.

the constructor and the destructor are both implicit `inline`.

Table: class definition, declaration styles

| style       |  scope                |  effect                   | where                                                       |
|-------------|-----------------------|---------------------------|-------------------------------------------------------------|
| `inline`    | global                | reduce jump time          | in same header file(explicit), or inside of class(implicit) |
| `::`        | namespace resolution  | interface, jump time      | in same header file, or "xxx.cpp" source file               |

these styles apply on any class method members. the following is unique for **constructor**.

`cls_name(): initializer() {}`

## access methods

(P295)

similar as other languages do.

## `const` objects and methods

if u define an object as `const`, the program can only read the object. as mentioned earlier, the object MUST be initialized when u define it for this reason.

example: `const Account inv("YMCA, FL", 5555, 5000.0); `

the object inv can NOT be modified at a later stage. this is also means that methods such as `setName()` can NOT be called for this object. however, methods such `getName()` or `display()` will be similarly unavailable although they only perform read access with the private data members.

the reason for this is that the compiler cannot decide whether a method performs write operations or read-only operations with private data members unless additional information is supplied.

## read-only methods

<!-- what? -->
methods that perform read-only operations and that u need to call for constant objects MUST be identified as read-only.
<!-- how? -->
to identify a method as read-only, **append the `const` keyword in the method declaration and in the function header for the method definition**.

example: `unsigned long getNr() const;`

ofc, this does NOT prevent u from calling a read-only method for a non-constant object

```c++
// account.h

#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account
{
    private:
        // data members;
        string name;
        unsigned long nr;
        double state;
    public:
        // public methods;
        Account(const string& a_name = "X",
                unsigned long a_nr   = 1111111,
                double a_state       = 0.0)
        {
            name    = a_name;
            nr      = a_nr;
            state   = a_state;
        }
        ~Account() {};

        string& getName() const { return name; }
        bool setName(string& s)
        {
            if(s.size() < 1)
                return false;
            name = s;
            return true;
        }
        // accessing private data member
        unsigned long getNr() const { return nr; }
        void setNr(unsigned long n) { nr = n; }
        double getState() const { return state; }
        void setState(double x) { state = x; }
        // display account
        void display(void) const;
};

inline Account::display() const
{
    cout << fixed << setprecision(2)
         << "\n-------------------------" << '\n'
         << "account name:     " << name  << '\n'
         << "account number:   " << nr    << '\n'
         << "account state:    " << state << '\n'
         << endl;
}

#endif // ACCOUNT_H_INCLUDED

```

## `const` and non-`const` version of a method

since the `const` keyword is part of the method's signature, u can define two versions of the method: 

- a read-only method, which will be called for constant object by default
- a normal version, which will be called for non-const objects.

## standard methods

every class *automatically* contains 4 standard methods:

- the default constuctor
- the destructor
- the copy constructor and
- the assignment

[question]

why default constructor doesnt work sometime?

(https://blog.csdn.net/swagle/article/details/24936273?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param)

C++手册中说" 默认构造函数会在**需要的时候**被编译器产生出来”关键是需要的时候.

原因是，需要的时候这个有两层意思：
1. 一个是程序的需要. 程序如果需要，那就是程序员的责任, 所以就是设计该类的人负责设计初始化代码。
2. 另一个是编译器的需要。

example:

```c++

class foo
{
    public:
        int val;
        foo *pNext;
};

void test()
{
    foo f;
    if(f.val || f.pNext)
        cout << "in if" << endl;
}

int main()
{
    test();
    return 0;
}

```

<font color="red">补充</font>

上述代码在vs上编译会报错，说使用了未初始化的局部变量。而在gcc编译器上却是可以编译通过并可以运行的。在这方面看来vs还是严格遵守C++标准的。

C++新手一般有两个常见的**误解**：
1. 任何class如果没有定义default constructor，就会被合成出来一个。
2. 编译器合成出来的default constructor会显示设定“class内每一个data member的默认值

总结：

- 被合成出来的implicit nontrivial default constructors只能满足编器的需要。它之所以能够完成任务，是借着“调用member object或者baseclass的default constructor”或是“为每一个object初始化其virtualfunction机制或virtual base class机制”而完成

- 在合成的default constructor中，只有base class subobjects和member class objects会被初始化。所有其他的nonstatic data member(如整数、整数指针、整数数组等)都不会被初始化。

You can use your own definitions to replace these standard methods.

## `copy constructor`

the `copy constructor` initializes an object with another object of the same type. it is called automatically when a second, already existing object is used to initialize an object.

example:

```c++

Account myAccount("ZL", 1234567890, 11000.00),
        yourAccount(myAccount); // is equivalent to yourAccount = myAccount;

// under hood
yourAccount.name  = myAccount.name;
yourAccount.nr    = myAccount.nr;
yourAccount.state = myAccount.state;

```

the copy constructor is also called when an object is passed to a function `by value`.

## assignment

assignment has been used in several previous examples. an object can be assigned to another object of the same type.

example:

```c++

hisAccount = yourAccount; // yeah, mentioned in the previous comment

```

## `this` pointer

(301)

JavaScript says hi..

```c++
// daytime.h

#ifndef DAYTIME_H_INCLUDED
#define DAYTIME_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

using namespace std; // potential risk: causing namespace contaimination..

class DayTime
{
    private:
        // data members
        short hour, minute, second;
        bool overflow;
    public:
        // constructor, destructor
        DayTime(int h = 0, int m = 0, int s = 0)
        {
            overflow = false;
            if(!setTime(h, m, s))
                hour = minute = second = 0;
        }
        bool setTime(int hour, int minute, int second=0)
        {
            if(    hour   >= 0 && hour   < 24
                && minute >= 0 && minute < 60
                && second >= 0 && second < 60 )
            {
                this->hour   = (short)hour;
                this->minute = (short)minute;
                this->second = (short)second;
                return true;
            }
            else
                return false;
        }

        int getHour()   const { return hour; }
        int getMinute() const { return minute; }
        int getSecond() const { return second; }

        int asSeconds() const
        { return (60*60*hour + 60*minute + second); }

        bool isLess(DayTime t) const
        {
            return this->asSeconds() < t.asSeconds();
                    // asSeconds() < t.asSeconds();
        }
};

#endif // DAYTIME_H_INCLUDED

```

## accessing the current object

(302)

comparing with other languages like **Python** or **VB** etc, a class in **C++** can access class methods implicitly..

a method can access any member of an object w/o the object name being supplied in every case. because a method will always reference the object with which it was called.

BUT how does a method know which object it it currently working with? when a method is called, **it is passed a hidden argument containing the address of the current object**.

the address of the current object is available to the method via the constant pointer `this`.

given that actObj is the current object of type Class_id, for which a method was called, the pointer `this` has the following delcaration:

`Class_id* const this = &actObj;`

example:

```c++
// DayTime class in sampleProgram07 in chapter 14;

// daytime.h

class DayTime
{
    private:
        // data members
        short h, m, s;
    public:
        // public methods
        DayTime(int h,
                int m,
                int s)
        {
            this->h = (short)h; this->m = (short)m; this->s = (short)s;
            cout << "address of the current object: " << this << endl;  // display memory address
        };
        ~DayTime(){};
        // ...
}

// main.cpp

#include <iostream>
#include "daytime.h"

using namespace std;

int main()
{
    DayTime d1(10, 30, 0);
    cout << "d1 address(&actObj): " << &d1 << endl; // compile and run: same address appears.

    return 0;
}
```


The name this is a keyword. As this is a constant pointer, it cannot be redirected.

In other words, the pointer this allows you to access the current object only.

## using the `this` pointer

well, it is similar as using `self in Python`, `me in VB`, `this in JavaScript`..

example:

```c++

this->data;
this->func();

data = 12; // corresponds to this->data = 12;

```

the `this` pointer can be used explicitly to distinguish a method's local variables from class members of the same name.

the `this` pointer is always necessary to access the current object, `*this`, collectively. this situation often occurs when the current object needs to be returned as a copy or by reference. then the return statement is as follows:

`return *this;`

## passing objects as arguments

(P303)

as u alread know, passing by value copies and object that was passed as an argument to the corresponding parameter of a function being called. the parameter is declared as an object of the class in question.

example:

```c++

bool isLess(DayTime t) const;

```

when the method `isLess()` is called, the copy constructor executes and initializes the created object, `t`, with the argument.

```c++

depart1.isLess(depart2); // copy constructor

```

the function uses a copy of the object `depart2`. the copy is cleaned up when leaving the function, that is, the destructor is called.

## passing by reference

the overhead caused by creating and cleaning up objects can be avoid by passing arguments by reference. in this case, the parameter is declared as a reference or pointer.

example:

```c++

bool isLess(const DayTime& t) const;

```

this new declarationof the `isLess()` is preferable to the previous declaration. effectiveness now:

- there is no formal differencee to the way the method is called
- `isLess()` no longer creates an internal copy, but accesses directly the object being passed
- ofc, the object can NOT be changed, as the parameter was declared read-only

## methods vs global functions

ofc, it is possible to write a global function that expects `one` object as an argument. **this rarely makes sense since u would normally expect an object's functionality to be defined in the class itself**.

instead, u would normally define a method for the class and the method would perform the task in hand.

a different situation occurs when operations with at least `two` objects need to be performed, such as comparing or swapping.

the major advantage fo a globally defined function is its symmetry. the objects invovled are peers, since both are passed as arguments. this means that conversion rules are applied to both arguments when the function is called.

## returning objects

a function can use the following ways to return an object as a return_value: it can create a copy of the object, or it can return a reference or pointer to that object.

## returning a copy

returning a copy of an object is **time-consuming** and only makes sense of **small-scale objects**.

## returning a reference

ofc, it is more efficient to return a reference of an object. but be aware that the lifetime of the referenced object MUST NOT be local.

(aesmr: ae is mr)

## using pointers as return values

instead of returning a reference, a function can also return a pointer to an object. in this case, u MUST ensure that the object still exists after exiting the function.

example:

```c++

#include <ctime>

const DayTime* currentTime()
{
    static DayTime curTime;
    time_t sec; time(&sec);
    struct tm* time = localtime(&sec);
    curTime.setTime(time->tm_hour,
                    time->tm_min,
                    time->tm_sec);
    return &curTime;
}

```

Table: return_value

| return_value      | prerequisits         | merit              | attention                                     |
|-------------------|----------------------|--------------------|-----------------------------------------------|
| a copy of obj     | no                   | simple             | time-consuming for large-scale obj            |
| reference of obj  | `static`             | efficient          | must ensure referenced obj exits              |
| a pointer of obj  | `static`             | efficient          | must ensure referenced obj exits              |