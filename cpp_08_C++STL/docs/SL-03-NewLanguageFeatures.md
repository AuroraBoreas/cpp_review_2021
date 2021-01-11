# new language features

(13)

## new c++11 language features

### important minor syntax cleanups

#### spaces in template expression

```c++
vector<list<int> > v;   // OK in each c++ version
vector<list<int>> v;    // OK since c++11

```

#### nullptr and std::nullptr_t

c++11 lets u use `nullptr` instead of `0` or `NULL` to specify that a pointer refers to no value(which differs from having an undefined value).

```c++

void f(int);
void f(void*);

f(0);       // calls f(int)
f(NULL);    // calls f(int) if NULL is 0, ambiguous otherwise
f(nullptr); // calls f(void*)

```

#### automatic type deduction with `auto`

```c++

auto i = 42;        // int
double f();
auto d = f();       // double

auto i;             // not OK. MUST be initialized when declaring, cause it is how `auto` deducts type from rvalue.

static auto vat = 0.19;     // OK

vector<strnig> v;
auto l = [](int x)->bool { //...; };

```

#### uniform initialization and initializer lists

three initializer operators: `()`, `=`, `{}`.

```c++

int values[] {1, 2, 3};         // OK
std::vector<int> v {2, 3, 4 };  // OK
std::vector<std::string> cities {"Berlin", "New York", "London"};

std::complex<double> c{4.3, 3.0}; // OK


// value initializer
int i;          // i is declared with undefined value
int j{};        // j is declared and initialized with 0
int* p;         // p is declared with undefined value
int* q{};       // q is declared and initialized with nullptr


// beaware of narrowing initializations are not possible with braces.

int x1(5.3);        // OK. narrowing, x1 = 5;
int x2 = 5.3;       // OK. narrowing, x2 = 5;
int x3{5.0};        // not OK. type is not exactly matching with type of rvales

int x4 = {5.3};     // not OK. same reason above

char c1{7};         // OK.

char c2{99999};     // not OK. out of range of char type.

std::vector<int> v1{1, 2, 4, 5};        // OK
std::vector<int> v2{1, 2.3, 4, 5.6};    // not OK

// narrowing always happens when type does NOT match with type of rvalue. @Bjarne Stroustrip

// std::initiaizer_list<> class template

void print(std::initializer_list<int> v)
{
    for(auto p=v.begin(); p != v.end(); ++p)
    { //...; }
}

print({1, 2, 2});

// braces work with cls
// priority is: initializer_list constructor -> regular constructor -> aggregate constructor

class P
{
    public:
        P(int, int);
        P(std::initializer_list<int>);
}

P p(77, 5);     // regular constructor
P q{77, 5};     // initializer_list constructor
P r{77, 5, 42}; // initializer_list constructor
P s = {77, 5};  // initializer_list constructor

/* confused af. 

to avoid confusion, using `explicit` to disable automatic, implicit type conversions from multiple values, which is also used when an initialization uses the = sytanx;

*/

class P
{
    public:
        P(int, int);
        explicit P(int, int, int);
}

P x(77, 5);         // OK
P y{77, 5};         // OK
P z{77, 5, 42};     // OK
P v = {77, 5};      // OK. using initializer_list to construct
P w = {77, 5, 42};  // not OK. due to explicit

void fp(const P&);

fp({47, 11});       // OK. OK implicit conversion is allowed for two parameters.
fp({47, 11, 3});    // not OK.MUST be explicit
fp(P{47, 11});      // OK. explicit conversion
fp(P{47, 11, 3});   // OK. explicit conversion

```

#### range-based `for` loops

syntax: `for(decl: coll){ statement; }`

```c++

// toy

for(int i: {2, 3, 5, 7})
{
    std::cout << i << std::endl;
}

// change element of a vector by 3

std::vector<double> v;
...
for(auto& i: v) // declaring i as ref is important. otherwise, it won't work.
// also, from effeciency perspective, declaring i as ref to avoid overhead of calling copy constructor and destructor for each element.
{
    i *= 3;
}

// thus, a generic func to print all elements of a collection should be implement as follows:

template<typename T>
void printElements(const T& coll)
{
    for(const auto& i: coll)
    {
        std::cout << i << std::endl;
    }
}

// in general

for(decl: col){ statement; }

// is equivalent to

for(auto _pos = coll.begin(); _pos != coll.end(); ++_pos)
{ decl = *_pos; statement; }

// or using a global begin() and end() taking coll as arg

for(auto _pos=begin(coll), _end=end(coll); _pos != _end; +++pos)
{
    decl = *_pos;
    statement;
}

```

#### move semantics and rvalue references

understand the concept of rvalue and lvalue.

using rvalue reference to avoid unnecessary copies and temporaries.

```c++

void createAndInsert(std::set<X>& coll)
{
    X x;        // create an obj of type X
    ...
    coll.insert(x); // set.insert(const T& v); // copy value of v
    ...
    coll.insert(x + x); // insert copy of temporary rvalue
    ...
    coll.insert(x); // insert copy of x
}

// std::move(var); it merely converts var into rvalue reference. it does NOT do anything else

class X
{
    public:
        X(const X& lvalue); // copy constructor
        X(X&& rvalue);      // move constructor
        X& operator=(const X& lvalue);  // copy assignment op
        X& operator=(X&& rvalue);       // move assignment op
}

// note 1): overloading rules for rvalue and rvalue references
// note 2): returning rvalue references

void foo(X);

void foo(X&);
void foo(X&&);
// or
void foo(const X&);
void foo(X&&);

// distinguish between dealing with rvalues and lvalues.


// returning rvalue references: NO, u dont have to and should not `move()` return values.

```

#### new string literals

since c++11, u can define raw string and multibyte/wide-character string literals.

##### raw string literals

syntax: `R"delim(...)delim"`;

```c++

string a = R"(你好)";       // raw string
string b = u8"こんにちは";  // UTF8 encoding
u"hello";                  // char16_t type
U"world";                   // char32_t type
L"HELLO";                   // wchar_t  


```

#### keyword `noexcept`

noexcept can be used to specify that a function cannot throw or is not prepared to throw.

if an exception is not handled locally inside of the function, thus, if the function does throw -- the program is terminated, calling `std::terminate()`, which by default calls `std::abort()`.

why: `noexcept` targets a lot of problems(empty) exception specifications have:

- runtime checking
- runtime overhead
- unusable in generic code

#### keyword `constexpr`

compile time, +
run time,     -

```c++

constexpr int square(int x)
{ return x*x; }

```

#### new template features

##### variadic templates

```c++

void print(){}; // stop template function's recursion

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    std::cout << firstArg << std::endl;
    print(args...);
}

print(7.5, "hello", std::bitset<16>(377), 42);

```

#### alias templates(Template Typedef)

```c++

template<typename T>
using Vec = std::vector<T, MyAlloc<T>>;

```

#### other template features

function templates may have default template args.

#### lambdas

syntax: `[](T args) mutable -> return_type { //statement };`

```c++
// type of lambda
#include <functional>
#include <iostream>

std::function<int(int, int)> returnLambda()
{
    return [](int x, int y){ return x*y; };
}

int main()
{
    auto f = returnLambda();
    std::cout << f(6, 7) << std::endl;
}

```

#### keyword `decltype`

using keyword `decltype`, u can let the compiler find out the type of an expression. this is the realization of the often requested `typeof` feature.
h/e, the existing `typeof` implementations were inconsistent and incomplete, so c++11 introduced a new keyword.

```c++

std::map<std::string, float> coll;
decltype(coll)::value_type elem;

```

#### new function declaration syntax

```c++

template<typename T1, typename T2>
decltype(x + y) add(T1 x, T2 y);

// or 
auto add(T1 x, T2 y)->decltype(x + y);

```

#### keyword `typename`

pass

#### member templates

member functions of classes may be templates. however, member templates may not be virtual.

```c++

class MyClass
{
    ...
    template<typename T>
    void f(T);
};

// template constructor

template<typename T>
class Myclass
{
    public:
        // copy constructor with implicit type conversion
        // does NOT suppress implicit copy constructor
        template<typename U>
        MyClass(const MyClass<U>& x);
        ...
};

void f()
{
    MyClass<double> xd;
    ...
    MyClass<double> xd2(xd);    // calls implicit copy construtor
    MyClass<int> xi(xd);        // calls template constructor
    ...
}

// nested class templates

template<typename T>
class MyClass
{
    ...
    template<typename T2>
    class NestedClass;
    ...
};


```

