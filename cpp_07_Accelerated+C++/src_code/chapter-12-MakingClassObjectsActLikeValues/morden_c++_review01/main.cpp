/*
modern c++ 11 review @ZL, 20210107

- nullpointer

- auto
    - what: auto a = 1;
    - why : programmer friendly
    - how : compiler automatically, implicitly understands var type
            compiler infers var type from rvalue;

- foreach
    - what: for(T var: container){}
    - why : programmer friendly
    - how : sugar syntax

- user-defined literal
    - what: return_type operator"" _kg(T);
    - why : readability counts
    - how : sugar syntax

- delete function
    - what: cls_name(const cls_name&) = delete;
    - why : explicitly constrain
    - how : using keyword delete to constrain

- default function
    - what: cls_name() = default;
    - why : revive default constructor when it is disabled
    - how : using keyword default to constrain

- explicitly override
    - what: virtual void bark(int i) override {}
    - why : explicitly declaration
    - how : using keyword override to constrain

- explicitly final
    - what: virtual void bark(int i) final {}
    - why : forbid derived cls overriding
    - how : using keyword final to constrain

- delegate constructor
    - what: cls_name(){} // default constructor
            cls_name(T argv): cls_name() {} // delegate constructor
    - why : readability counts
    - how : using default constructor in between parameterized constructor

- move constructor
    - what: cls_name(T&& rhs)
            {
                data_member = rhs.data_member;
                rhs.data_member = nullpointer;
                // temporary generated rhs obj then will be destroyed
            }
    - purposes:
        - rvalue reference, vs lvalue reference
        - perfect forwarding
    - how : using similar form of copy constructor but differs a bit. mutex

- move assignment operator
    - what: cls_name(const T&& rhs){}
    - why : time and space saving
    - how : using similar form of copy assignment operator but differs a bit.

- uniform initialization
    - regular initialization, priority 1
    - list_initialization, priority 2
    - aggregation initialization {}, priority 3

- enum class(strong typed)
    - what: enum class [identifier] [T] {}
    - why : make even more stronger type
    - how : using keyword enum class

- constexpr
    - what: constexpr int add(int a, int b) { return a + b; }
    - why : time saving(compile time+, run time-)
    - how : using keyword constexpr

- static_assert
    - what: static_assert(expression, "result")
    - why : compile time assertion. comparing with assert() in run time
    - how : using keyword static_assert

- lambda function
    - what: auto f = [](int a, int b){ return a + b; }
    - why : one used function
    - how : using keyword [](){}

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum MyApple: int
{
    name,
    sexy,
};

enum MyOrange: int
{
    laugh,
    sex,
};


enum class Apple: int
{
    name,
    sexy,
};

enum class Orange: int
{
    name,
    sexy,
};

class MyClass
{
    public:
        MyClass(const MyClass& mc) = delete;
        MyClass() = default;
};

class Dog
{
    private:
        string name;
    public:
        virtual void bark(int i){};
        virtual void eat(float i) final {}; // not allow derived class to override
};

class YellowDog: public Dog
{
    public:
        // virtual void bark(float f) override {}; // explicitly override
        // virtual void eat(int i) override {};
};


template<class T>
class Cat
{
    private:
        vector<T> vt;
    public:
        Cat(const vector<T>& v) // copy constructor, deep copy
        {
            for(vector<T>::const_iterator Iter it = v.begin(); it != v.end(); ++it)
            {
                vt.push_back(*it);
            }
        }
};


class Date
{
    private:
        unsigned year, month, day;
    public:
        Date() { year = month = day; }
        Date(unsigned ye, unsigned mo, unsigned da): Date() {}
};

int main()
{
    // nullpointer
    int y = 1;
    int *x = &y;
    x = nullptr;

    // auto
    auto a = 1;             // int
    auto b = 2.718281828;   // double
    auto c = a;             // int

    // foreach
    vector<int> v = { 1, 2, 3 };
    for(int i: v)
    { cout << i << " "; }

    // user-defined literals
    constexpr long double operator"" _km(long double);

    // delete function
    MyClass mc;

    // raw enum vs enum class
    MyApple ma1 = MyApple::name;
    MyOrange mo1 = MyOrange::laugh;
    if(ma1 == mo1); // OK

    Apple a1 = Apple::name;
    Orange o1 = Orange::name;
    // if(a1 == o1); // not OK

    // static_assert
    static_assert(sizeof(void *) == 4, "64-bit code generation is not supported.");

    // uniform initialization
    vector<double> vd {3, 4, 5};
    vector<double> ve = {3, 4, 5};
    Dog d1{"John"}; // priority matters

    // lambda
    auto g = [](int a, int b){ return a + b; };
    g(3, 4);


    return 0;
}
