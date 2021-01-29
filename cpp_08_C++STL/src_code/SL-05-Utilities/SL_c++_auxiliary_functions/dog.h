#ifndef DOG_H_INCLUDED
#define DOG_H_INCLUDED

#include <iostream>
#include <string>

class Dog
{
private:
    // seems it is the only way to do const data member initialization
    // this syntax works, C++ >= 11

    int m_age;
public:
    const std::string m_name = "ZL";

    Dog(int age);
    void display(void) const;
};

//const std::string Dog::m_name = "ZL"; // static data member initialization is not working on const..
inline Dog::Dog(int age)
{
    m_age = age;

    // in ctor?
//    m_name = "ZL";    // nope
}

inline void Dog::display(void) const
{
    std::cout << "\nName: " << m_name
              << "\nAge:  " << m_age
              << std::endl;
}


#endif // DOG_H_INCLUDED
