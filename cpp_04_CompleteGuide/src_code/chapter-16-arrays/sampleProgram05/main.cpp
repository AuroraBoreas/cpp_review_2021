#include <iostream>
#include "account.h"

using namespace std;

Account giro("Lucky, Peter", 1234567, -1200.99);
Account accountTab[] =
{
    Account("Tang, Sarah", 123000, 2500.0),
    Account("Smith, John", 543001, 0),
    Account(),
    Account("Li Zhang", -1, 10000.0),
    Account("GSN SCY", 1100, 99.01),
    giro
};

int cnt = sizeof(accountTab) / sizeof(Account);

int main()
{
    // test Account class
//    Account a1,
//            a2("ZL", 1000001, 900.00),
//            a3(a1);
//
//    a1.print(); a2.print();
//
//    a3.setName("SCY");
//    a3.setState(100.00);
//    a3.print();
//
//    a1.setName("");
//    a1.print();

    // sample program in book
    // to set some values:
    accountTab[1].setState(10000.00);
    accountTab[2] = Account("Pit, Dave", 727003, 200.00);
    std::cout << "\nThe accounts in the table: " << std::endl;
    for(int i=0; i < cnt; ++i)
    {
        accountTab[i].print();
        if(i%3 == 2)
        {
            std::cout << "\nPress return to go on!\n";
            std::cin.get();
        }
    }
    std::cout << std::endl;


    return 0;
}
