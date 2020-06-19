#include <iostream>

using namespace std;
int agetomonths(int);

int main()
{
    int age;
    cout << "Enter your age: " << endl;
    cin >> age;
    cout << "Month(s): "
         << agetomonths(age) << endl;
    return 0;
}

int agetomonths(int yo)
{
    return yo * 12;
}
