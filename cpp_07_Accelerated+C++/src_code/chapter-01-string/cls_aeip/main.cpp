#include <iostream>
#include "car.h"
using namespace std;

int main()
{
    Car *pcCar = new PassCar(12345, "XiaoPeng", true),
        *tkCar = new Truck(54321, "XiaoMi", 4, 5.8);

    pcCar->display();
    tkCar->display();

    delete pcCar;
    delete tkCar;

    return 0;
}
