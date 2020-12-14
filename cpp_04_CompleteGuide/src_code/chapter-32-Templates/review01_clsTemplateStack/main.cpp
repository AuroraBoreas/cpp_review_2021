#include <iostream>
#include "stack.h"
#include <cstdlib>
#include <iomanip>
using namespace std;
// template initialization
typedef Stack<unsigned> USTACK;

// funcs
void fill(USTACK& u);
void clear(USTACK& u);

int main()
{
    USTACK ustk(256);
    fill(ustk);
    USTACK ostk(ustk);
    cout << "the copy: " << endl;
    clear(ostk);
    cout << "the original: " << endl;
    clear(ustk);


    return 0;
}

void fill(USTACK& u)
{
    cout << "Enter positive integers (quits with 0):\n";
    unsigned x;
    while(cin >> x && x != 0)
    {
        if(!u.push(x))
        {
            cerr << "stack is full!\n";
            break;
        }
    }
}

void clear(USTACK& u)
{
    if(u.empty())
        cerr << "stack is empty!\n";
    else
    {
        unsigned x;
        while(u.pop(x))
            cout << setw(8) << x << " ";
        cout << endl;

    }
}
