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


    PassCar cabrio("Spitfire", 1001, "Triumph", true);
    // pointer notation
    Car* carPtr = &cabrio;
    //cabrio = &cabrio;
    carPtr->display();  // display base members only

    // reference notation
    Car& carRef = cabrio;
    carRef.display();   // display base members only
    //carRef.setSunRoof(true); //error
    //PassCar _auto;
    //_auto = carRef;     // error. less can't always fill more

    return 0;
}
