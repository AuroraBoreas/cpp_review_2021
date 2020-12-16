#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef list<int> INTLIST;

int display(const INTLIST& c);

int main()
{
    // random seed
    time_t sec; time(&sec);
    srand(sec);

    int max_size = 3;

    INTLIST ls, sls;
    int i;
    for(i=1; i<max_size; ++i)
    {
        ls.push_back(rand()%10);
    }
    ls.push_back(ls.front());
    ls.reverse();
    ls.sort();

    for(i=1; i<max_size; ++i)
    {
        sls.push_back(rand()%10);
    }

    INTLIST::iterator pos = ls.end();
    ls.splice(--pos, sls, sls.begin());
    cout << "original(sls): \n";
    display(sls);

    cout << "original(ls): \n";
    display(ls);
    ls.sort();
    cout << "after sort(ls): \n";
    display(ls);
    sls.sort();
    ls.merge(sls);
    cout << "after merge(ls): \n";
    display(ls);
    ls.unique();
    cout << "after unique(ls): \n";
    display(ls);

    return 0;
}

int display(const INTLIST& c)
{
    list<int>::const_iterator pos;
    for(pos=c.begin(); pos != c.end(); ++pos)
        cout << *pos << " ";
    cout << endl;
    return 0;
}
