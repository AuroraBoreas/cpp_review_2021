#include <iostream>
#include <iomanip>
#include "quadMat.h"
#include <cstdlib>

using namespace std;

template class QuadMatrix<long double, 5>;


int main()
{
    QuadMatrix<long double, 5> m;
    try
    {
        for(int k=0; k < m.dim(); ++k)
        {
            for(int l=0; l<m.dim(); ++l)
            {
                m[k][l] = k*l;
                cout << setw(2) << m[k][l] << " ";
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
