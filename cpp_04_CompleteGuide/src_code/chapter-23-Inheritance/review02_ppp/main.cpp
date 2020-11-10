#include <iostream>
#include "car.h"
using namespace std;

int main()
{
//    const Castle ca1;
//
//    ca1.noSecret;
//    //ca1.getSecret();      // protected
//    //ca1.getTopSecret();   // protected
//    ca1.

    PassCar beetle("VM", 3421, "Beetle", false);
    beetle.display();

    beetle.Car::display();

    return 0;
}
