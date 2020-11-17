#include <iostream>
#include "Base.h"

using std::cout;

int main()
{
    Base *bPtr = new Derived("DEMO");
    cout << "\nCall to the virtual Destructor!\n";
    delete bPtr;

    return 0;
}
