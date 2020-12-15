#include <iostream>
#include "quadmat.h"
#include <cstdlib>
#include <iomanip>
using namespace std;

template class QuadMatrix<long double, 5>;

int main()
{
    QuadMatrix<long double, 5> m;
    try
    {
        for(int i=0; i<m.dim(); ++i)
        {
            for(int j=0; j<m.dim(); ++j)
            {
                m[i][j] = i * j; // write
                cout << setw(2) << m[i][j] << " "; // read
            }
            cout << endl;
        }
    }
    catch(out_of_range& err)
    {
        cerr << err.what() << endl;
    }
    return 0;
}
