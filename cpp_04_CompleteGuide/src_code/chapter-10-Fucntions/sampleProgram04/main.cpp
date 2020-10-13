#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

bool setrand = false;

inline void init_random()
{
    if(!setrand)
    {
        srand((unsigned int)time(NULL));
        setrand = true;
    }
}

inline double myRandom()
{
    init_random();
    return (double)rand() / (double)RAND_MAX;
}

inline int myRandom(int start, int _end)
{
    init_random();
    return (rand() % (_end+1 - start) + start);
}


int main()
{
    int i;
    cout << "5 random numbers between 0.0 and 1.0: " << endl;
    for(i=0; i<5; ++i)
    {
        cout << setw(10) << myRandom();
    }
    cout << endl;

    cout << "\nAnd now 5 integer random numbers "
            "between -100 and +100: " << endl;
    for(i=0; i<5; ++i)
    {
        cout << setw(10) << myRandom(-100, 100);
    }
    cout << endl;

    return 0;
}
