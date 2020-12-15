#include <iostream>
#include <cstdlib>
#include <iomanip>
//#include "stack.h"
#include "stackn.h"
using namespace std;

const int n = 10;
typedef Stack<unsigned, n> USTACK; // not OK, OK now
typedef Stack<unsigned, 10> USTACK; // OK

void fill(USTACK&);
void clear(USTACK&);

int main()
{
    USTACK istk;
    fill(istk);
    USTACK ostk(istk);
    cout << "\nthe copy: " << endl;
    clear(ostk);
    cout << "\nthe original: " << endl;
    clear(istk);

    return 0;
}

void fill(USTACK& stk)
{
    cout << "\nEnter positive integers: "
         << "(quit with 0)";
    unsigned n;
    while(cin >> n && n != 0)
    {
        if(!stk.push(n))
        {
            cerr << "Stack is full" << endl;
            break;
        }
    }
}

void clear(USTACK& stk)
{
    unsigned n;
    if(!stk.empty())
    {
        while(stk.pop(n))
        {
            cout << setw(8) << n << " ";
        }
    }
    else
        cerr << "Stack is empty" << endl;
}
