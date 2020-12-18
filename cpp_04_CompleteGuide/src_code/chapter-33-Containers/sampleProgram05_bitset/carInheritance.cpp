#include <iostream>
#include "car.h"

using namespace std;

int main()
{
    // derived class
    cout << "\n---------cls Van--------\n";
    Van v1, v2(1234, "Toyota", true, 3.2, 8);

    v1.display();
    v2.display();

    // upcasting
    cout << "\n---------upcasting--------\n";
    Truck *pcv1 = dynamic_cast<Truck*>(&v1),
          *pcv2 = dynamic_cast<Truck*>(&v2);
    pcv1->display();
    pcv2->display();

    return 0;
}
