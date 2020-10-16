#include "date.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Date::init(int i_month, int i_day, int i_year)
{
    month = i_month;
    day   = i_day;
    year  = i_year;
}

void Date::init()
{
    struct tm *ptr;
    time_t sec;
    time(&sec);
    ptr = localtime(&sec);

    month = ptr->tm_mon + 1;
    day   = ptr->tm_mday;
    year  = ptr->tm_year + 1900;
}

void Date::print()
{
    cout << month << "-"
         << day   << "-"
         << year  << endl;
}
