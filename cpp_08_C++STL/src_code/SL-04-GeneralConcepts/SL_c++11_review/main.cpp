/*

new lang features

// + auto:     compiler automatically deduces type
        - using auto too often is gonna mislead yourself, btw

// + noexcept: functions throw no exception. and if it does, prg will terminate

// + constexpr:functions are compiled in compile time, reduce run time for ender users

// + delete:   user defines and forbid usage

// + default:  user defines and make functions default

// + override: explicitly override functions

// + final:    make functions can't be derived

// + user-defined literals: readability counts
    - constexpr long double operator "" _m(long double v);

// + uniform initializer: =, (), {}.
    - std::initializer_list<T> var, priority 1
    - regular constructor, priority 2
    - aggregate constructor, priority 3
    * narrowing always happens, as long as rvalue T differs lvalue T
    * {} does not allow narrowing

// + foreach: for(decl: coll){ //... }

// + lambda: []()mutable throw() -> return_type { //... };
    - v or ref, = or &
    - return_type using <functional> cls or auto
    - when //... >= 2, user must declare return_type
    * lambda can't have template

// + template: create generic func or cls
    - member template in cls
    - nested template in cls
    - template args

// + explicit: make functions explicit when using constructors

// + string: Unicode support, raw string, wchar_16, wchar_32
    - u8"..."
    - R"(...)"
    - u"..."
    - U"..."

// + typename: replace typeid which is inconsistent and incomplete

// + rvalue, lvalue; rvalue reference, lvalue reference
    - rvalue
    - lvalue
    - rvalue ref
    - lvalue ref

// + move semantics: resource management efficiency UP

*/

#include <iostream>
#include <vector>
#include <forward_list>
#include <functional>
#include <algorithm>
#include <string>

//#include <numbers> // >= c++20

using namespace std;

inline int add(int x, int y) noexcept
{
    return (x / y);
}

constexpr int square(int x)
{
    return (x*x);
}

class A
{
    public:
        // constructors
        A()
        { std::cout << "default constructor" << std::endl; }; // default if no user defined constructor at all
        explicit A(int i, int j)
        { std::cout << "regular constructor" << std::endl; }
        A(const A& a) = delete; // copy constructor
        A& operator=(const A& a) = default; // copy assignment constructor
        A(A&& a); // move constructor
        A& operator=(A&& a); // move assignment constructor

        virtual void print(void) const final
        { std::cout << "print member function" << std::endl; }

        int sub(int x, int y) const
        { return (x - y); }

        virtual void dance(void);
};

class B: public A
{
    template<typename T>
    T sub(float x, float y)
    { return (static_cast<T>(x) / y);}

    void dance() override
    {
        std::cout << "virtual member methods can be explicitly overrode only." << std::endl;
    }
};

struct Distance
{
private:
    explicit Distance(long double val): kilometers(val){}
    friend Distance operator"" _km(long double val);
    friend Distance operator"" _mi(long double val);
    long double kilometers{0}; // ???
public:
    const static long double km_per_mile;
    long double get_kilometers(){ return kilometers; }
    Distance operator+(Distance other)
    {
        return Distance(get_kilometers() + other.get_kilometers());
    }
};

const long double Distance::km_per_mile = 1.609344L;

Distance operator"" _km(long double val)
{
    return Distance(val);
}

Distance operator"" _mi(long double val)
{
    return Distance(val * Distance::km_per_mile);
}

constexpr long double operator"" _m(long double v)
{ return (v * 10); }

int main()
{
    // + auto:     compiler automatically deduces type
    auto i = 11; // OK. i is integer
    // auto j; // Error. rvalue is a must
    std::forward_list<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    auto p = v.begin(); // OK

    // + noexcept: functions throw no exception. and if it does, prg will terminate
    // std::cout << add(3, 0) << std::endl; // OK. but prg will crash at run time

    // + constexpr:functions are compiled in compile time, reduce run time for ender users
    std::cout << square(10) << std::endl; // OK

    // + delete:   user defines and forbid usage
    // see cls A

    // + default:  user defines and make functions default
    // see cls A

    // + override: explicitly override functions
    // see cls A

    // + final:    make functions can't be derived
    // see cls A

    // + user-defined literals: readability counts
    //    - constexpr long double operator "" _m(long double v);


    Distance d{402.0_km};
    std::cout << "Kilometers in d: " << d.get_kilometers() << std::endl;


    // + uniform initializer: =, (), {}.
    //    - std::initializer_list<T> var, priority 1
    //    - regular constructor, priority 2
    //    - aggregate constructor, priority 3
    //    * narrowing always happens, as long as rvalue T differs lvalue T
    //    * {} does not allow narrowing

    // + foreach: for(decl: coll){ //... }
    for(; p != v.end(); ++p)
    {
        std::cout << *p << std::endl;
    }
    for(auto i: v)
    {
        std::cout << i << std::endl;
    }

    // + lambda: []()mutable throw() -> return_type { //... };
    //    - v or ref, = or &
    //    - return_type using <functional> cls or auto
    //    - when //... >= 2, user must declare return_type
    std::function<int(int, int)> f = [](int x, int y){ return (x + y); };
    std::cout << f(3, 4) << std::endl;

    static double pi = 3.1415926;
    auto g = [&](int x){ return (pi * x); };
    std::cout << g(3) << std::endl;
    auto h = [](int x) mutable { return (pi * x); };
    std::cout << h(3) << std::endl;

    size_t c;
    c = std::count_if(v.begin(),
                      v.end(),
                      [](int x)->bool
                      {
                          int res = x % 2;
                          std::cout << "x = " << x << ", " << (res? "odd": "even") << std::endl;
                          return !res;
                      });
    std::cout << "\nresult: " << c << std::endl;

    // + template: create generic func or cls
    //    - member template in cls
    //    - nested template in cls
    //    - template args
    // see cls A

    // + explicit: make functions explicit when using constructors
    // see cls A

    // + string: Unicode support, raw string, wchar_16, wchar_32
    //    - u8"..."
    //    - R"(...)"
    //    - u"..."
    //    - U"..."
    string name1 = u8"ÄãºÃ£¡";
    string name2 = R"(¤³¤ó¤Ë¤Á¤Ï)";
    string name3 = R"(restez sur place, je reviandrez)";
    std::cout << name1 << std::endl;
    std::cout << name2 << std::endl;
    std::cout << name3 << std::endl;

    // + typename: replace typeid which is inconsistent and incomplete
    // see cls A


    return 0;
}
