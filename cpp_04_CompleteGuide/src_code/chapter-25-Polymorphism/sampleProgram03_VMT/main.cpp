#include <iostream>
#include "car.h"

using namespace std;

int main()
{
    Car *myCar = new Car(12345, "Audi");
    Car *yourCar = new PassCar(54321, "Geo", "500", true);

    myCar->display();
    yourCar->display();

    return 0;
}
