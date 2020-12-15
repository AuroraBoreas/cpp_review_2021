#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "stack.h"
using namespace std;

typedef Stack<unsigned> USTACK;

void fill(USTACK& stk);
void clear(USTACK& stk);

int main()
{
    USTACK istk(10);
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
    unsigned x;
    while(cin>>x && x != 0)
    {
        if(!stk.push(x))
        {
            cerr << "Stack is full" << endl;
            break;
        }
    }
}

void clear(USTACK& stk)
{
    unsigned x;
    if(!stk.empty())
    {
        while(stk.pop(x))
            cout << setw(8) << x << " ";
        cout << endl;
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
}
