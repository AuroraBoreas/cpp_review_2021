#include <iostream>
#include <iomanip>
#include "time.h"
#include "date.h"
#include "datetime.h"
using namespace std;

//int add(int, int);
//double add(double, double);

template<class T>
T add(T a, T b)
{
    return (a + b);
}

int main()
{
    int a = 5, b = 4;
    cout << add<int>(a, b) << endl;
    float c = .1, d = .2;
    cout << add<float>(c, d) << endl;

    cout << "\ntest Time cls\n";

    Time t1, t2(8, 3, 10), t3(11, 30, 5);
    Time arr[3] = { t1, t2, t3 };
    for(int i=0; i<3; ++i)
    {
        cout << arr[i] << endl;
        cout << std::boolalpha << (arr[i] < t1) << endl;
    }

    cout << "\ntest Date cls\n";

    Date d1, d2(2020,1,1), d3(2020,12,1);
    Date *ptr1 = &d1,
         *ptr2 = &d2,
         *ptr3 = &d3;

    Date** datePPtrs[3] = { &ptr1, &ptr2, &ptr3 };

//    for(Date* ptr = datePPtrs; ptr != NULL; ++ptr)
//        cout << *ptr->asString() << endl;

    for(int i=0; i<3; ++i)
        cout << (**datePPtrs[i]) << endl;


    cout << "\ntest DateTime cls\n";
    DateTime dt1, dt2(2020, 12, 10, 10, 30, 05);

    cout << dt1 << endl;
    dt1.setDateTime();
    cout << dt1 << endl;
    cout << boolalpha << (dt1 == dt2) << endl;

    return 0;
}
