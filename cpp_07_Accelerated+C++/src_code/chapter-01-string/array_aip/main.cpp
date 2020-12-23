#include <iostream>
#include <cstdlib>
#include "account.h"

using namespace std;

int main()
{
    Account arr[] = {
                      Account(),
                      Account(12345, "SCY", 99.99),
                      Account(12312, "LM", 89.93),
                      Account(54321, "LL", 99213.1),
                      Account(23213, "ZL", 30123)
                    };

    // address notation
    int i;
    cout << "\n------------addr notation------------\n";
    for(i=0; i<5; ++i)
    {
        std::cout << *(arr + i) << std::endl;
    }
    // index notation
    cout << "\n------------index notation------------\n";
    for(i=0; i<5; ++i)
    {
        std::cout << arr[i] << std::endl;
    }

    // pointer notation
    cout << "\n------------pointer notation------------\n";
    Account *ptr = &arr[0];
    for(i=0; i<5; ++i)
    {
        std::cout << *ptr << std::endl;
        ptr++;
    }

    return 0;
}
