#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
#include "account.h"

using namespace std;

typedef set<int> IntSet;
typedef IntSet::iterator IntSetIter;

typedef multiset<int> IntMultiSet;
typedef IntMultiSet::iterator IntMultiSetIter;

typedef set<Account> AccSet;
typedef AccSet::iterator AccSetIter;

void display(const AccSet& a);

int main()
{
    // random seed
    srand((unsigned)time(NULL));

    // fill set
    IntSet is;
    while(is.size()<5)
    {
        is.insert(rand()%10); // fill number between 0 and 10;
    }

    cout << "numbers in set are: ";
    IntSetIter pos;
    for(pos=is.begin(); pos != is.end(); ++pos)
        cout << *pos << "   ";

    cout << "\n\n";

    IntMultiSet ms;
    for(int i=0; i<10; ++i)
        ms.insert(rand()%10);

    cout << "\nand random numbers between 0 and 10 "
         << " are: ";
    IntMultiSetIter msPos;
    for(msPos=ms.begin(); msPos != ms.end(); ++msPos)
        cout << *msPos << " ";
    cout << endl;

    AccSet as;
    as.insert(Account(12345, "ZL", 999.99));
    as.insert(Account(54321, "SCY", 11));
    as.insert(Account(4566123, "ZZ", 100000000));
    as.insert(Account(1231231, "LL", 1230123));

    display(as);
    // delete
    as.erase(as.begin());
    display(as);
    as.erase(as.begin(), as.end());
    display(as);

    return 0;
}

void display(const AccSet& a)
{
    cout << endl;
    AccSetIter pos;
    for(pos=a.begin(); pos != a.end(); ++pos)
        cout << *pos << endl;
    cout << endl;
}
