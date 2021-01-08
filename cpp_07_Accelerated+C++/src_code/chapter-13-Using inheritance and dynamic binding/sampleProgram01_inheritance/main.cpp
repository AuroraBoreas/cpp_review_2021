#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;

int main()
{
    Time t1, t2(8, 0, 0);
    std::cout << "\nt1 = " << t1;
    std::cout << "\nt2 = " << t2;
    t1.setTime();
    std::cout << "\nt1 = " << t1;
    std::cout << "\nt1 < t2 = " << std::boolalpha << (t1 < t2) << std::endl;

    return 0;
}
