#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    Date d1, d2(2010, 10, 16), d3(2020, 11, 1);
    cout << "d1 : " << d1 << endl;
    d1.setDate();
    Date arr[3] = { d1, d2, d3 };

    for(int i=0; i<3; ++i)
    {
        cout << "d" << (i+1) << " : " << arr[i] << endl;
        cout << "d" << (i+1) << "<d1? " << std::boolalpha << (arr[i] < d1) << endl;
    }

    return 0;
}
