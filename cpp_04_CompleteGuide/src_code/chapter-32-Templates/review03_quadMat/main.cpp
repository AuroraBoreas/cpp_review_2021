#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "quadmat.h"

using namespace std;

//template class QuadMatrix<long double, 5>;
typedef QuadMatrix<long double, 5> M;

int main()
{
    M m;

    try
    {
        for(int i=0; i<m.dim(); ++i)
        {
            for(int j=0; j<m.dim(); ++j)
            {
                m[i][j] = i*j;
                cout << setw(2) << m[i][j] << " ";
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
