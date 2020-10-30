# Type Conversino For Classes

(462)

Implicit type conversion occurs in C++ when an expression cannot be compiled directly but can be compiled after applying a conversion rule.

The programmer can stipulate how the compiler will perform implicit type conversion for classes by defining conversion constructors and functions.

Finally, we discuss ambiguity occurring due to type conversion and how to avoid it.

## conversion constructors

(463)

### possible type conversions

implicit and explicit type conversion is also performed for classes in C++.

any type conversion involving a class is defined either

- by a conversion constructor, `convert any-given-type -> the-type-of-current-class`.
- by a conversion function, `convert an-obj-of-current-class -> another type`

**a constructor with ONLY ONE parameter is referred to as a `conversion constructor`**. the `copy constructor` is an exception to this rule: it creates an obj of the same class and does NOT perform type conversion.

## conversion functions

example:

```c++
// type_conversion.cpp

#include <iostream>
#include <iomanip>
using namespace std;

class Euro
{
    // body
    private:
        long data;
    public:
        // ...
        operator double(void) const
        { return (double)data/100.0; }
};

int main()
{
    // test
    Euro salary(8888,88);
    double x(0.0);

    salary += 1000.00;              // double -> Euro
    salary += 10;                   // int -> double -> Euro
    x = salary;                     // Euro -> double using conversion function
    x = (double)salary;             // Euro -> double using cast style
    x = salary.operator double();   // possible? YES
    x = double(salary);             // Euro -> double using constructor style..
    int i = salary;                 // Euro -> double -> int

    return 0;
}

```

### defining conversion function

example:

```c++
operator int(void) const;
```

why no return_type in function definition?

this is because the return_type is implicitly defined by the target type in the name of the conversion function.

thus, conversion functions MUST be written to construct a target obj from the current object, `*this`, and return the target obj.

### standard type conversion

in addition to user-definable type conversions, the compiler also performs standard type conversions.

example: `int WholePart  = oneEuro;`

## ambiguities of Type conversions

(467)

### type conversion failure

defining a conversion function or conversion constructor can prevent u from compiling a program that is otherwise unchanged.

the compiler can only perform implicit type conversion if the technique is NOT ambiguous. if more than one choice is available, the compiler issues an error message.

### avoid implicit type conversion

in order to ensure that some kinds of type conversion are only performed explicitly, u can use the following techniques:

- u can use an `explicit` declaration for the conversion constructor.
- implicit type conversions by conversion functions can be prevented by not defining the function, of course. instead, u can use a method of an appropriate name, like `asType()`. type conversion can only be performed by calling this function explicitly.

example:

```c++
// explicit type conversion constructor and function

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Euro
{
    private:
        long data;
    public:
        // --- explicit type conversion constructor ---
        explicit Euro(int euro=0, int cents=0)
        { data = 100L * (long)euro + cents; }
        explicit Euro(double x)
        { x *= 100.0; data = (long)(x >= 0.0? (x+0.5) : (x-0.5)); }
        string asString(void) const
        {
            stringstream ss; long temp = data;
            if(temp<0) { ss << '-'; temp = -temp; }
            ss << (temp/100) << ',' << setw(2) << setfill(2) << (temp%100);
            return ss.str();
        }
        // --- explicit type conversion function ---
        double asDouble(void) const
        { return (double)data/100.0; }
};


int main()
{
    // --- implicity type conversion for Euro obj is impossible..
    Euro e1, e2;
    
    e1 = e1 + 1000; // Error...

    return 0;
}


```
