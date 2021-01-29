#include "dog.h"
#include <iostream>

//const std::string Dog::m_name = "ZL"; // static data member initialization is not working on const..
Dog::Dog(int age)
{
    m_age = age;

    // in ctor? nope
//    m_name = "ZL";
}

void Dog::display(void) const
{
    std::cout << "\nName: " << m_name
              << "\nAge:  " << m_age
              << std::endl;
}
