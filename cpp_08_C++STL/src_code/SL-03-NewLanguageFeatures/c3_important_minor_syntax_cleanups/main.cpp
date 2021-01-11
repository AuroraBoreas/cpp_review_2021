/*

spaces in the template expressions

- space in template expressions

vector<list<int> >; // OK in each c++ version
vector<list<int>>; // OK since c++11

- nullptr and std::nullptr_t

void f(int);
void f(void*);

f(0);       // calls f(int);
f(NULL);    // calls f(int) if NULL is 0;
f(nullptr); // calls f(void*);

uniform initializer
we are using the following syntaxes to initialize var
- assignment operator, =
- parentheses, ()
- braces, {}

if the type of rvalue is exact type of var, no narrowing.
note that floating-point to integer conversions are always considered narrowing.

class template std::initializer_list<T>
- it can be used to support initializations by a list of values
- or in any other place where u wanna process just a list of values

then keyword explicit comes into the chat.

explicit disables implicit, automatic type conversions

keyword noexcept, specifies a function not to throw or prepare to throw exception.

variadic templates
- using recursion to handle each arg
- using non-template overload of the func to end the recursion


*/
#include <iostream>
#include <vector>
#include <list>
#include <bitset>

void print(std::initializer_list<int> v)
{
    for(auto p=v.begin(); p != v.end(); ++p)
    {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
}

class P
{
    public:
        P(int, int);
        P(std::initializer_list<int>);
};

template<typename T>
void printElements(const T& v)
{
    for(const auto& i: v)
    {
        std::cout << i << std::endl;
    }
}

class C
{
    private:
        std::string name;
    public:
        explicit C(const std::string& s) { name = s; }
};

template<typename T>
void _swap(T& x, T& y) noexcept(noexcept(x._swap(y)))
{
    x.swap(y);
}

// this non-template overload of print() is to end variadic templates recursion
void display(){}

template<typename T, typename... Types>
void display(const T& firstArg, const Types& ... args)
{
    std::cout << firstArg << std::endl;
    display(args...); // recursion
}


int main()
{
    int x1(5.3);        // ouch, implicit type conversion
    int x2 = 5.3;       // ouch, implicit type conversion
    // int x3{5.0};        // ERROR: narrowing
    // int x4 = {5.3};     // ERROR: narrowing
    char c1{7};         // OK
    // char c2{9999};      // ERROR: narrowing

    std::vector<int> v1{1, 2, 4, 5};    // OK
    // std::vector<int> v2{1, 2.3, 4, 5.6}; // ERROR: narrowing

    print({12,3,5,7,11,13,17});


//    P p1(77, 5);
//    P q{77, 5};
//    P r{77, 5, 42};
//    P s = {77, 7};
    const auto v = {1, 2, 3, 4, 5, 6};
    printElements(v);

    const C cs1{"ZL"};
    // C cs2 = "LL"; // ERROR: explicit disabled implicit, auto type conversion
    C cs3 = (C)"LL"; // explicit conversion

    display(7.5, "hello", std::bitset<16>(377), 42);

    return 0;
}
