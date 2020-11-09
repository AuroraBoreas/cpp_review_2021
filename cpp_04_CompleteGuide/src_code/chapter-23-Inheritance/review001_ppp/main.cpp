#include <iostream>
#include "car.h"

using namespace std;

int main()
{
    PassCar beetle("Beetle", false, 3421, "VM");

    beetle.display();
    beetle.Car::display();

    return 0;
}
