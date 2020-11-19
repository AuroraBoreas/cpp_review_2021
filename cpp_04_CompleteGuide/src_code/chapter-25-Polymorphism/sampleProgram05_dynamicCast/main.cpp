#include <iostream>
#include "car.h"

using namespace std;

bool inspect(PassCar*),
     inspect(Truck*);
bool separate(Car*);

int main()
{
    Car *carPtr = new PassCar("BMW", false, 12345, "Mes");
    Truck* truckPtr = new Truck(8, 7.5, 5437, "Volvo");

    separate(carPtr);
    separate(truckPtr);

    delete carPtr;
    delete truckPtr;

    return 0;
}

bool separate(Car* carPtr)
{
    PassCar* passCarPtr = dynamic_cast<PassCar*>(carPtr);   // using dynamic_cast to down cast, Car -> PassCar
    if(passCarPtr != NULL)
        return inspect(passCarPtr);
    Truck* truckPtr = dynamic_cast<Truck*>(carPtr);         // using dynamic_cast to down cast, Car -> Truck
    if(truckPtr != NULL)
        return inspect(truckPtr);
    return false;
}

bool inspect(PassCar* passCarPtr)
{
    cout << "\nI inspect a passenger car!" << endl;
    cout << "\nhere it is: ";
    passCarPtr->display();
    return true;
}

bool inspect(Truck* truckPtr)
{
    cout << "\nI inspect a truck!" << endl;
    cout << "\nhere it is:";
    truckPtr->display();
    return true;
}
