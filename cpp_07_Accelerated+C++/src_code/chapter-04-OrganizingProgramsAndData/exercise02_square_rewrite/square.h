#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include <vector>
#define SQUARE(x) ((x) * (x))

using std::vector;

typedef vector<int> VecInt;

void populateVecInt(int, VecInt&, VecInt&);
std::ostream& display(std::ostream&, const VecInt&, const VecInt&);

void populateVecInt(int n, VecInt& v1, VecInt& v2)
{
    for(int i=0; i<n; ++i)
    {
        v1.push_back(i); v2.push_back(SQUARE(i));
    }
}

std::ostream& display(std::ostream& os, const VecInt& v1, const VecInt& v2)
{
    os << "val" << "\t" << "square\n";

    int size = v1.size();
    for(int i=0; i<size; ++i)
    {
        os << v1[i] << "\t" << v2[i] << std::endl;
    }
    return os;
}

#endif // SQUARE_H_INCLUDED
