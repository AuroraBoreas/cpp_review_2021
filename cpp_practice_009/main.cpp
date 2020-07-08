#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    const int inch_per_foot = 12;
    int user_height;

    cout << "Enter your height(feet): ";
    cin  >> user_height;

    cout << "your height is "
         << user_height / 12 << " feet, "
         << user_height % 12 << " inches.\n";

    return 0;
}
