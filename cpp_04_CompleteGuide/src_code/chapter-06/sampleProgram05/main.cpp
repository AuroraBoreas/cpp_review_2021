#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    long double x, y, mini;
    cout << "Enter two different numbers: \n";
    if(cin >> x && cin >> y)
    {
        if(x < y)
        {
            mini = x;
        } else {
            mini = y;
        }
        cout << "\nThe smallest number is: " << mini << endl;
    } else {
        cout << "\nInvalid Input!" << endl;
    }

    return 0;
}
