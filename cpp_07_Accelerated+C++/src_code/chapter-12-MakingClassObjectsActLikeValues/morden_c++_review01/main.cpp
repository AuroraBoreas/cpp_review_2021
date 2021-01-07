/*
modern c++ 11 review @ZL, 20210107

- auto
- foreach
- user-defined literal
- delete function
- default function
- explicitly override
- explicitly final
- delegate constructor
- move constructor
    - rvalue reference, vs lvalue reference
    - perfect forwarding

- move assignment operator
- uniform initialization
    - regular initialization, priority 1
    - list_initialization, priority 2
    - aggregation initialization {}, priority 3

- enum class(strong typed)
- constexpr. time saving(compile time+, run time-)
- static_assert

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


    return 0;
}
