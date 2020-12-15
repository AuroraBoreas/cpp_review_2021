#include <iostream>
#include <iomanip>
#include "quadmat.h"

using namespace std;

// explicit declaration
template class QuadMatrix<long double, 5>;

int main()
{
    QuadMatrix<long double, 5> m;

    // write
    for(int i=0; i<m.dim(); ++i)
    {
        for(int j=0; j<m.dim(); ++j)
        {
            // write
            m[i][j] = i * j;
            // read
            cout << setw(2) << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
