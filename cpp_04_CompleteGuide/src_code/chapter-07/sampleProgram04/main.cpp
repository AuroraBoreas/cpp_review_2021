#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int number(0);
    string line;

    while(getline(cin, line))
    {
        cout << setw(5) << ++number << ": "
             << line << endl;
    }
    return 0;
}
