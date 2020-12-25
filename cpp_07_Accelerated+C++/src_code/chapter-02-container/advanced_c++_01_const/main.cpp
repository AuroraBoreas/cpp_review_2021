#include <iostream>
#include <string>

namespace ZL
{
    struct Person_t // default privilege: public
    {
        std::string name = "noname";
        std::string sex  = "nosex";
        double      height = 0.0;

        private:
            unsigned secrity_number = 1;
    };

    class Person    // default privilege: private
    {
        std::string name_;
        std::string sex_;
        double      height_;

        public:
            bool haveKids;

        /*
        why using xxx_ suffix underscore?
        _xxx prefix underscore is used by C++ built-in
        */
    };
}

namespace LL
{
    const int a = 1;                // a is const int, lvalue
    const int *ptr1 = &a;           // ptr1 is pointer to const int, lvalue
    const int* const ptr2 = &a;     // ptr2 is const pointer to const int, lvalue
    int const* const ptr3 = &a;     // ptr3 is const pointer to const int, lvalue
}

namespace SCY
{
    int i = 10;

    int func1(int i)
    {
        return ++i; // i = i + 1; return new i, i = 11, so func1 returns a deep copy of 11
    }

    int func2(int i)
    {
        return i++; // i = i + 1; return original i, so func2 returns a deep copy of 11
    }

    int x = func1(i);
    int y = func2(x);

    // question: what is y now?
    // answer  : 11
}



int main()
{
    ZL::Person_t pt;
    std::cout << pt.name << ", " << pt.sex << ", " << pt.height << std::endl;

//    ZL::Person p;
//    std::cout << p.name_ << std::endl; // not OK. its private member by default

    std::cout << "\na = " << LL::a << std::endl;
    std::cout << "\nptr1 = " << LL::ptr1 << std::endl;
    std::cout << "\nptr2 = " << LL::ptr2 << std::endl;
    std::cout << "\nptr3 = " << LL::ptr3 << std::endl;

    std::cout << "\ny = " << SCY::y << std::endl;
    return 0;
}
