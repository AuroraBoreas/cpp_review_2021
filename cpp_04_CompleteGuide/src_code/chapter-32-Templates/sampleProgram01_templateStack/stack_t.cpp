#include "stack.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef Stack<unsigned> USTACK; // template initialization

void fill(USTACK& stk);
void clear(USTACK& stk);

int main()
{
    USTACK ustk(10); // create
    fill(ustk);
    USTACK ostk(ustk); // copy
    cout << "The copy: " << endl;
    clear(ostk);
    cout << "The original: " << endl;
    clear(ustk);


    return 0;
}

void fill(USTACK& stk)
{
    unsigned x;
    cout << "Enter positive integers (quits with 0): \n";
    while(cin >> x && x != 0)
    {
        if(!stk.push(x))
        {
            cerr << "Stack is full!\n"; break;
        }
    }
}

void clear(USTACK& stk)
{
    if(stk.empty())
        cerr << "Stack is empty!" << endl;
    else
    {
        unsigned x;
        while(stk.pop(x))
            cout << setw(8) << x << " ";
        cout << endl;
    }
}
