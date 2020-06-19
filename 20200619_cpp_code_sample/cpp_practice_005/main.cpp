#include <iostream>

using namespace std;
double celtofah(double);

int main()
{
    double c;
    cout << "Please enter a Celsius value: ";
    cin >> c;
    cout << c
         << " degrees Celsius is "
         << celtofah(c)
         << " Fahrenheit." << endl;
    return 0;
}

double celtofah(double c)
{
    return 1.8 * c + 32.0;
}
