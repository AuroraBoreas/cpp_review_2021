#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    int degree, minute, second;
    const int min_per_degree = 60;
    const int sec_per_minute = 60;

    cout << "Enter a latitude in degrees, minutes, and seconds:" << endl;
    cout << "First, enter the degree: ";
    cin  >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin  >> minute;
    cout << "Finally, enter the seconds of arc: ";
    cin  >> second;
    cout << degree << " degrees, "
         << minute << " minutes, "
         << second << " seconds = "
         << degree + (float)minute /  min_per_degree + (float)second / (sec_per_minute * min_per_degree)
         << endl;

    return 0;
}
