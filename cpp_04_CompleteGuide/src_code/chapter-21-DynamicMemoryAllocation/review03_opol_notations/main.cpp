#include <iostream>
#include "euro.h"
#include "account.h"

using namespace std;

int main()
{
    Euro e1, e2(33, 10);
    cout << e1 << endl;
    cout << e2 << endl;

    cout << (e1 + e2) << endl;
    cout << (e2 + e1) << endl;

    cout << (e1 - e2) << endl;
    cout << (e2 - e1) << endl;

    cout << (double)e2 << endl; // C cast style
    //cout << double(e2) << endl; // bad

    return 0;
}
