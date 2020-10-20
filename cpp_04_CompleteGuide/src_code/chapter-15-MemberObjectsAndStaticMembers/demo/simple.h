#ifndef SIMPLE_H_INCLUDED
#define SIMPLE_H_INCLUDED

#include <string>
#include <iostream>
#include <iomanip>

#include "daytime.h"

class SimpleClass
{
private:
    std::string name;
    int age;
    DayTime dt;
public:
    // constructors
    SimpleClass(); // declaration of default constructor
    SimpleClass(const std::string&, int, DayTime&); // another constructor
    // SimpleClass(const string& s_name, int s_age = 1); // exception: against overload rule
    // destructor
    ~SimpleClass(){};
    // getter
    std::string getName(void) const { return name; }
    int getAge(void)          const { return age; }
    // setter
    void setName(const std::string& s_name) { name = s_name; }
    void setAge(int s_age)                  { age = s_age; }
    // print
    void print(void) const;

};

SimpleClass::SimpleClass()
{
    name = "hello world"; age = 5000; dt = DayTime(6, 0, 0);
    std::cout << "hello I'm default constructor" << std::endl;
}

SimpleClass::SimpleClass(const std::string& s_name, int s_age, DayTime& z)
{
    if(s_name.size() < 1 || s_age < 0)
        { name = "hello world"; age = 5000; dt = DayTime(6, 0, 0); }
    else
        { name = s_name; age = s_age; dt = z; }
    std::cout << "hello I'm specific constructor" << std::endl;
}

void SimpleClass::print() const
{
    std::cout << "name : " << std::setw(20) << std::left << name << '\t';
    std::cout << "age  : " << std::setw(10) << std::left << age  << '\t';
    std::cout << "time : ";
    dt.print();
}

#endif // SIMPLE_H_INCLUDED
