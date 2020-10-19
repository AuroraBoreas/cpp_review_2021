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

int i(0);
int i = 0;

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

(according to `inline` definition: inline function is just an alternative to macro with parameters, it makes sense.)

(P294)

short methods can be defined within the class. Methods of this type are known as implicit inline methods, although the inline keyword is NOT used.

example:

```c++
// account.h

class Account
{
    private:
        //
    public: 
        //
        bool isPositive() { return state > 0; } // implicit inline methods. inline is NOT used though.
};

```

## constructor and destructor with `inline` definitions

constructors and destructors are special methods belonging to a class and, as such, can be defined as `inline`.

the constructor and the destructor are both implicit `inline`.

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

using namespace std;

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

        int getHour() const { return hour; }
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

