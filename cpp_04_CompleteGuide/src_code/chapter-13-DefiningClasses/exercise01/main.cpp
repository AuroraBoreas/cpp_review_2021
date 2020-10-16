#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    Date d1, d2, *ptrD = &d1;
    // test1
    ptrD->init(1, 1, 2020);
    ptrD->print();
    // test2
    ptrD = &d2;
    ptrD->init();
    ptrD->print();
    // more
    d1.init(1, 2, 2021);
    d1.print();
    d2 = d1;
    d2.print();

    cout << "stored address: " << ptrD << endl;
    cout << "ptrD's address: " << &ptrD << endl;


    cout << "Hello world!" << endl;
    return 0;
}
