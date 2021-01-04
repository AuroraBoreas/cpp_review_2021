/*

normal cls vs composition cls

+ normal cls: AEIP
    - abstraction
    - encapsulation
    - inheritance
    - polymorphism

+ composition cls
    - naming is important for software engineers.
    - common activities -> segregation
    - other inheritance

*/

#include <iostream>
#include <string>

using namespace std;

class BaseDog{};

class YellowDog: public BaseDog{};

class GreenDog: public BaseDog{};

class SuperiorDog: public YellowDog, public BaseDog{};

int main()
{



    return 0;
}
