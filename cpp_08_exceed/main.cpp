#include <iostream>
#define ZERO 0
#include <climits>

using namespace std;

int main()
{
    short sam = SHRT_MAX;
    unsigned short sue = sam;

    cout << "Sam has " << sam << " dollars." << endl;
    cout << "Sue has " << sue << " dollars." << endl;
    cout << "add $1 to each account." << endl;
    sam = sam + 1;
    sue = sue + 1;

    cout << "Sam has " << sam << " dollars." << endl;
    cout << "Sue has " << sue << " dollars." << endl;

    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars." << endl;
    cout << "Sue has " << sue << " dollars." << endl;
    cout << "Take $1 from each account." << endl;
    sam = sam - 1;
    sue = sue - 1;

    cout << "Sam has " << sam << " dollars." << endl;
    cout << "Sue has " << sue << " dollars." << endl;
    return 0;
}
