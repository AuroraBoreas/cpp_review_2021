#include <iostream>
#include "car.h"

using namespace std;

template <typename T>
T square(T x)
{
    return x * x;
}

int main()
{
    std::cout << square<int>(5)     << std::endl;
    std::cout << square(5.5)        << std::endl;
    std::cout << square((double)5)  << std::endl;
    std::cout << square((float)5)   << std::endl;
    std::cout << square(5)          << std::endl;

    Car *myCar = new Car(12345, "VW"),
        *yourCar = new PassCar("Geo", true, 54321, "Toyota");

    myCar->display();
    yourCar->display();

    return 0;
}
