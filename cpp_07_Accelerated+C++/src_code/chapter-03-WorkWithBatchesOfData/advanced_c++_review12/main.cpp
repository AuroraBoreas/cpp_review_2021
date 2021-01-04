/*

core lang
- var
- func
- statement
- if
- loop
- cls

*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
inline void display(const char* c)
{
    std::cout << *c << std::endl;
}

struct Demo
{
    int a;
    float b;
};

class Dog
{
private:
    string name;
public:
    Dog(const string& s): name(s) { cout << "Dog say meow" << endl; }
};

class YellowDog: public Dog
{
public:
    YellowDog(const string& s): Dog(s) { cout << "yellow dog say oi" << endl; }
};


int main()
{
    // VAR, TNP: C S I L F D
    char c = 'a';
    std::cout << int(c) << std::endl;
    short a = 65538;
    std::cout << a << std::endl;
    unsigned b = 65538;
    std::cout << b << std::endl;
    // two's complement: in binary sys, flip then add one
    int d = 0xF;
    int e = 0b1111;
    std::cout << "d = " << d << "; "
              << "e = " << e << "; "
              <<  (d == e) << std::endl;
    // flip
    int e_flipped = ~e;
    int e_inverted = 0b0000;
    std::cout << "e_flipped = " << e_flipped << std::endl;
    std::cout << "e_inverted = " << e_inverted << std::endl;
    int e_minus = e_flipped + 1;
    std::cout << "e_minus   = " << e_minus << std::endl;

    // func, TNP: ref, pointer


    char prompt[] = "bonjour tout le monde!";
    std::cout << prompt << std::endl;
    // 1. rvalue(string) constructed
    // 2. convert the rvalue to char array
    // 3. destroy the rvalue
    char* cPtr = prompt;
    // or a const address in memory
    char* cPtr1 = &prompt[0];

    display(cPtr1);

    /*
    statement, ARLABACOO:
    - arithmetic
        - + - + - * / %
        - (prefix)++ --; ++ --(postfix)
        - op priority
    - relational
        - ==, !=
        - <, <=
        - >, >=
    - logic
        - &&
        - ||
        - !
    - assign
        - ()
        - =
    - bitwise
        - &
        - |
        - ^
        - NAND
        - NOR
        - XOR
        - XNOR
    - access
        - (*ptr).
        - ->
        - *->*
    - cast
        - dynamic_cast; pointer to an obj
        - const_cast; remove or add const
        - static_cast; anything
        - reinterpret_cast; "C style cast"
    - op for storage:
        - new; new T[];
        - delete; delete[] var;
    - op for other:
        - tenary op, ?:
        - namespace resolve, ::
        - comma, ,
        - sizeof,
        - typeid,
    */
    // arithmetic
    int x = 10, y = 12;
    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;
    std::cout << "x % y = " << x % y << std::endl;
    std::cout << "x++  = "  << x++ << std::endl; // original x, priority: high
    std::cout << "++x  = "  << ++x << std::endl; // new x, priority: lower than postfix
    std::cout << "x--  = "  << x-- << std::endl; // original x
    std::cout << "--x  = "  << --x << std::endl; // new x
    // logic
    std::cout << "x && y = " << (x && y) << std::endl; // shortcut
    std::cout << "x || y = " << (x || y) << std::endl; // shortcut
    std::cout << "x != x "   << (x != x) << std::endl; // shortcut
    // assign
    int s(123), // 0111 0001
        t = 31; // 0001 1111
    // bitwise
    s << 2; // b1100 0100 == 128 + 64 + 4 = d196
    t >> 2; // b0000 1111 == d15
    // access
    Demo f;
    f.a = 1;
    f.b = 3.1415926;
    Demo* fPtr = &f;
    fPtr->a;
    fPtr->b;
    // or
    (*fPtr).a;
    (*fPtr).b;
    // cast
    YellowDog* ydPtr = new YellowDog("john");
    Dog* dogPtr = dynamic_cast<Dog*>(ydPtr);

    const int i = 11;
    const int* ciPtr = &i;
    int* iPtr = const_cast<int*>(ciPtr);

    // op for storage
    // op for other

    return 0;
}
