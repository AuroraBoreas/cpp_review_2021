#include <iostream>

using namespace std;

const double pi = 3.1415926;

int main()
{
    cout << "Hello world!" << endl;

    double area, circuit, radius = 1.5;

    area = pi * radius * radius;
    circuit = 2 * pi * radius;

    cout << "\nTo evaluate a circle\n" << endl;
    cout << "Radius:        " << radius << endl
         << "Circumference: " << circuit << endl
         << "Area:          " << area << endl;

    return 0;
}
