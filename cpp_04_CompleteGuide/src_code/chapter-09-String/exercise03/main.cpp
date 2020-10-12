#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    long sec;
    time(&sec); // reads the present time (in seconds) into sec
    // or
    // sec = time();
    string tm = ctime(&sec); // convert the seconds to a string
    cout << "Date and time: " << tm << endl;

    string hr(tm, 11, 2); // substring of tm starting at 11, 2 char long
    string greeting("Have a wonderful ");
    string morning("<10"),
           day("<17");

    if(hr < morning)
    {
        greeting += "Morning";
    }
    else if(hr < day)
    {
        greeting += "Day";
    }
    else
    {
        greeting += "Evening!";
    }
    cout << greeting << endl;

    return 0;
}
