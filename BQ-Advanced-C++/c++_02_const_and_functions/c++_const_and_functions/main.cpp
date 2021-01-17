#include <iostream>
#include <string>

using namespace std;

//class Dog // version 0
//{
//    int age;
//    std::string name;
//public:
//    Dog(){ age = 3; name = "noname"; }
//    void setAge(int& a) { age = a; a++; }
//};

//class Dog   // version 1
//{
//    int age;
//    std::string name;
//public:
//    Dog(){ age = 3; name = "noname"; }
//    void setAge(const int& a) { age = a; }
//
//};

class Dog   // version 2
{
    int age;
    std::string name;
public:
    Dog(){ age = 3; name = "noname"; }
    void setAge(const int& a) { age = a; }

    // const return value
    const std::string getName(void) { return name; }
    // const function
    void print(void) const { std::cout << name << std::endl; }
    // const function calling non-const function is NOT allowed.
    // const function only calls const functions etc.
    // just like static functions call static members only.
    // void print(void) const { std::cout << this->getName << std::endl;  } // not OK
    // override
    void print(void) { std::cout << "non-const" << std::endl; }
};

int main()
{
    Dog d;
    int i = 9;
    d.setAge(i);
    std::cout << i << std::endl; // Dog obj function member changes local var
    d.print();  // call non-const function print

    const Dog d2;
    d2.print();  // call const function print
    // i dont wanna change local var i
    // then add const specifier to function member

    return 0;
}
