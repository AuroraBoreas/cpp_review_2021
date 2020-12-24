#include <iostream>
#include <iomanip>
#include <vector>
#include "account.h"

typedef std::vector<Account> VecAcc;
typedef VecAcc::const_iterator VecAccIter;

int main()
{
    // test Account cls
    Account acc1,
            acc2(12345, "ZL", 9312939),
            acc3(12312, "LM", 312.10),
            acc4(53321, "HH", 89120.1),
            accArr[] = { acc1, acc2, acc3, acc4 };

    for(int i=0; i<4; ++i)
    {
        std::cout << accArr[i] << std::endl;
    }

    // vector
    VecAcc va;
    va.push_back(acc1);
    va.push_back(acc2);
    va.push_back(acc3);
    va.push_back(acc4);
    VecAccIter vaIter;
    for(vaIter=va.begin(); vaIter != va.end(); ++vaIter)
    {
        std::cout << *vaIter << std::endl;
    }
    //
    std::cout << std::endl;
    // clear
    va.erase(va.begin(), va.end());
    // state
    std::cout << std::boolalpha << va.empty() << std::endl;

    return 0;
}
