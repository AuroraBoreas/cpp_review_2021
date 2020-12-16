#include <iostream>
#include <iomanip>
#include "quadmat.h"
#include "stackn.h"

using namespace std;

// explicit declaration
template class QuadMatrix<long double, 5>;

const int n = 10, m = 20; // template args: yes all or omit all
typedef Stack<unsigned long, n, m> USTACK; // OK

int main()
{
    QuadMatrix<long double, 5> m;

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
