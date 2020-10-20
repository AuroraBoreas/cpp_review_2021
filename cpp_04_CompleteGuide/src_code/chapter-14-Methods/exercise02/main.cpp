#include <iostream>
#include <sstream>
#include <iomanip>
#include "date.h"

using namespace std;
const string& intToString(int);

int main()
{
    cout << "Hello world!" << endl;
    cout << endl;

    Date d1(10, 19, 2020),
         d2(11, 31, 2020);
    cout << "d1 < d2 = " << boolalpha << d1.isLess(d2) << endl;
    d1.print();
    d2.print();

    int m(10);
    cout << intToString(m) + " hello world" << endl;

    return 0;
}

const string& intToString(int i)
{
    static string str;
    stringstream iostream;
    iostream << setw(10) << i;
    iostream >> str;
    return str;
}
