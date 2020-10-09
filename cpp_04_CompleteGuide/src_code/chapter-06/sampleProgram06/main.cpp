#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    float limit, speed, toofast;
    cout << "\nSpeed limit ";
    cout << "and Speed: (separated by whitespace)";

    if (cin >> limit && cin >> speed)
    {
        if((toofast = speed - limit) < 10)
        {
            cout << "u were lucky!" << endl;
        }
        else if(toofast < 20)
        {
            cout << "fine payable: 40,-. Dollars" << endl;
        }
        else if(toofast < 30)
        {
            cout << "Fine payable: 80,-. Dollars" << endl;
        }
        else
        {
            cout << "Hand over your driver's license!" << endl;
        }
    }
    else
    {
        cout << "Invalid Input!" << endl;
    }

    return 0;
}
