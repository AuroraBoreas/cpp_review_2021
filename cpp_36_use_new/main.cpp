#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    int nights = 1001;
    int * pt = new int;
    *pt = 1001;

    cout << "nights value = " << nights
         << ": location " << &nights << endl;
    cout << "int ";
    cout << "value = " << *pt
         << ": location = " << pt << endl;

    double * pd = new double;
    *pd = 10000001.0;

    cout << "double ";
    cout << "value = " << *pd
         << ": location = " << pd << endl;
    cout << "size of pt = " << sizeof(pt);
    cout << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof(pd);
    cout << ": size of *pd = " << sizeof(*pd) << endl;

    delete pt;
    delete pd;

    return 0;
}
