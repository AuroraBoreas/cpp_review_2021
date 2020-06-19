#include <iostream>

using namespace std;
long lightyear_to_astronomical_units(double);

int main()
{
    double au;
    cout << "Enter the number of light year(s): ";
    cin  >> au;
    cout << au
         << "light year(s) = "
         << lightyear_to_astronomical_units(au)
         << " astronomical units." << endl;
    return 0;
}

long lightyear_to_astronomical_units(double au)
{
    return au * 63240;
}
