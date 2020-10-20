#include <iostream>
#include "daytime.h"
#include <ctime>

using namespace std;

const DayTime& currentTime(void);

int main()
{
    cout << "Hello world!" << endl;
    DayTime d1(10, 30, 0),
            d2(15, 20, 11);

    cout << "d1 = ";
    d1.display();
    cout << "d2 = ";
    d2.display();

    d1.setHour(18);
    cout << "d1 = ";
    d1.display();
    cout << "d1 < d2 : " << std::boolalpha << d1.isLess(d2) << endl;

    cout << endl;
    DayTime cinema(20, 30);
    cout << "\nThe movie starts at ";
    cinema.display();

    DayTime now(currentTime());
    cout << "\nThe current time is ";
    now.display();

    cout << "\nThe movie has ";
    if(cinema.isLess(now))
        cout << "already begun!\n" << endl;
    else
        cout << "not yet begun!\n" << endl;


    return 0;
}

const DayTime& currentTime()
{
    static DayTime curTime;
    time_t sec; time(&sec);
    struct tm *time = localtime(&sec);
    curTime.setTime(time->tm_hour,
                    time->tm_min,
                    time->tm_sec);
    return curTime;
}
