/*

cast

dynamic_cast<T*>(&var); // pointer only.
static_cast<T>(var);    // known type conversion
const_cast<T>(var);     // remove or add const
reinterpret_cast<T*>(var);
(T)var;                 // C-Style cast

5 categories of iterator in STL

input_iterator
output_iterator

forward_iterator;
bidirectional_iterator;
back_iterator;




*/

#include <iostream>     // input, output
#include <vector>       // random access
#include <list>         // bi-directional
#include <algorithm>    // copy, sort
#include <iterator>     // distance, advance, pre, next
#include <forward_list>
#include "shapes.h"

using namespace std;

class Fractional
{
    private:
        int m_num, m_dem;
    public:
        // constructor
        Fractional(int num, int dem)
        : m_num(num), m_dem(dem) {}
        double getDouble(void)
        {
            return static_cast<double>(m_num) / m_dem; // quotient
        }
};

void print(const Fractional& f)
{
    Fractional* frc = const_cast<Fractional*>(&f); // remove const w/o changing class
    cout << frc->getDouble() << endl; // not OK. compiler complains;
}


int main()
{
    Fractional f(3, 4); // parenthesis initializer
    cout << f.getDouble() << endl; // know how exact type conversion

    Fractional f1(4, 11);
    print(f1);

    list<int> v{1, 2, 4, 5, 7, 8, 9};
    // auto it = v.begin();
    //it += 4; // not OK. "jump" is not allowed
//    for(int i=0; i<4; ++i)  // using loop to forward pointer
//    {
//        it++;
//    }
//    cout << "using loop to walk, " << *it << endl;

//    advance(it, 4);
//    cout << "using advance to walk, " << *it << endl;
    auto it = v.rbegin(); // reverse begin
    for(; it != v.rend(); ++it)
    {
        cout << "using loop to walk, " << *it << endl;
    }

    int x1 = 1;
    int* p = &x1;
    cout << *p << endl;
    p = 0;


    return 0;
}
