#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(NULL));

    vector<int> VecInt;
    for(int i=0; i<10; ++i)
        VecInt.push_back(rand()%10);

    // display
    VecInt::const_iterator it;
    it = VecInt.begin();
    for(; it != VecInt.end(); ++it)
        cout << *it << endl;

    // accumulate
    accumulate(VecInt.begin(), VecInt.end(),)

    return 0;
}
