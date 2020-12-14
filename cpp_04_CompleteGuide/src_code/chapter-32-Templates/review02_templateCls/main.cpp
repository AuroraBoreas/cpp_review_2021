#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "time.h"
#include "stackn.h"
#include "date.h"
#include "datetime.h"
using std::cout;
using std::endl;

// initialize cls Stack
typedef Stack<unsigned, 250> USTACK;

void fill(USTACK&);
void clear(USTACK&);

int main()
{
    // test cls Stack
//    USTACK istk;
//    fill(istk);
//    USTACK ostk(istk);
//    cout << "\nthe copy: " << endl;
//    clear(ostk);
//    cout << "\nthe original: " << endl;
//    clear(istk);

    // test cls Time
//    Time t1, t2(8, 30, 10), t3(11, 30, 05),
//         arr[] = { t1, t2, t3 };
//    for(int i=0; i<3; ++i)
//    {
//        std::cout << arr[i] << " == " << t3  << " is "
//                  << std::boolalpha << (arr[i] == t3) << std::endl;
//    }

    // test cls Date
//    Date d1, d2(2020, 12, 14), d3(2021, 1, 1),
//         arr_d[] = { d1, d2, d3 };
//    for(int i=0; i<3; ++i)
//    {
//        std::cout << arr_d[i] << " < " << d3 << " is "
//                  << std::boolalpha << (arr_d[i] < d3) << std::endl;
//    }

    // test cls DateTime
    DateTime dt1, dt2(2020, 12, 14, 13, 30, 10), dt3(2021, 1, 1, 8, 0, 0),
             arr3[] = { dt1, dt2, dt3 };
    for(int i=0; i<3; ++i)
    {
        cout << arr3[i] << " == " << dt3 << " is "
             << std::boolalpha << (arr3[i] == dt3) << endl;
    }

    return 0;
}

void fill(USTACK& stk)
{
    std::cout << "\nEnter positive integers: ";
    std::cout << "(quit with 0)";

    unsigned int x;
    while(std::cin >> x && x != 0)
    if(!stk.push(x))
    {
        std::cerr << "Stack is full";
        break;
    }
}

void clear(USTACK& stk)
{
    unsigned n;
    if(!stk.empty())
    {
        while(stk.pop(n))
            std::cout << std::setw(8) << n << " ";
        std::cout << std::endl;
    }
    else
    {
        std::cerr << "Stack is empty" << std::endl;
    }
}
