#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

//typedef Stack<unsigned> USTACK;
// or
template class Stack<unsigned>; // explicit declaration

void fill(Stack<unsigned>&);
void clear(Stack<unsigned>&);

int main()
{
//    USTACK istk(250);
    Stack<unsigned> istk(250);
    fill(istk);
//    USTACK ostk(istk);
    Stack<unsigned> ostk(istk);
    cout << "\nthe copy: ";
    clear(istk);
    cout << "\nthe original: ";
    clear(ostk);

    return 0;
}

void fill(Stack<unsigned>& stk)
{
    cout << "\nEnter positive numbers: "
         << "(quits with 0)" << endl;

    unsigned n;
    while(cin >> n && n != 0)
    {
        if(!stk.push(n))
            cerr << "Stack is full" << endl;
    }
}

void clear(Stack<unsigned>& stk)
{
    unsigned n;
    if(stk.empty())
        cerr << "Stack is empty" << endl;
    else
    {
        while(stk.pop(n))
            cout << n << " ";
    }
    cout << "\n";

}
