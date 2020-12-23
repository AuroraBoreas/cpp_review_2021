#include <iostream>
#include <vector>
#include <iomanip>
#include "account.h"

using namespace std;

typedef vector<Account> AccVec;
typedef AccVec::const_iterator AccIter;

int main()
{
    // insert
    AccVec ac;
    ac.push_back(Account());
    ac.push_back(Account(12345, "ZL", 999.99));
    ac.push_back(Account(12312, "LE", 3912));
    ac.push_back(Account(54321, "SCY", 1.0));

    // update, search
    AccIter aiter;
    for(aiter=ac.begin(); aiter != ac.end(); ++aiter)
    {
        cout << *aiter << endl;
    }

    // delete
    ac.erase(ac.begin(), ac.end());
    cout << "\nthe container is empty: " << boolalpha << ac.empty() << endl;

    return 0;
}
