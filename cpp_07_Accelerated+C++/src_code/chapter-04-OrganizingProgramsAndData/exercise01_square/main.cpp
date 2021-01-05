#include <iostream>
#include <vector>
#include <iomanip>

#define SQUARE(x) ((x) * (x))

using std::vector;

typedef vector<int> VecInt;

int main()
{
    // two columns: the first list contains value, the second contains square
    VecInt vi1, vi2;

    int i;
    for(i=1; i<101; ++i)
    {
        vi1.push_back(i); // populate vale list
    }

    for(i=1; i<101; ++i)
    {
        vi2.push_back(SQUARE(i)); // populate square list
    }

    // display
    std::cout << std::setw(3) << "val"
              << "\t"
              << "square\n";
    for(i=1; i<101; ++i)
    {
        std::cout << std::setw(3) << vi1[i-1]
                  << "\t"
                  << vi2[i-1]
                  << std::endl;
    }

    return 0;
}
