#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
#include <iomanip>
using namespace std;

typedef list<int> INTLIST;
void display(const INTLIST& c);

int main()
{
    // rand
    srand((unsigned int)time(NULL));


    INTLIST ls, sls;
    int max_size = 10;

    int i;
    for(i=0; i<max_size; ++i)
    {
        ls.push_back(rand()%10);
    }
    // original ls
    display(ls);
    // sort
    ls.sort();
    display(ls);

    for(i=0; i<max_size; ++i)
    {
        sls.push_back(rand()%10);
    }
    // original sls
    display(sls);
    // sort sls
    // sls.sort();

    INTLIST::iterator pos;
    pos = ls.end();

    ls.splice(--pos, sls, sls.begin());

    // after splice
    display(ls);

    // after ls merge sls
    ls.merge(sls);
    display(ls);

    return 0;
}

void display(const INTLIST& c)
{
    cout << endl;
    list<int>::const_iterator pos;
    for(pos=c.begin(); pos != c.end(); ++pos)
    {
        cout << setw(2) << *pos << " ";
    }
    cout << endl;
}
