#include <iostream>
#include <cstdlib>  // for exit, system, random?
#include <ctime>
#define MAX 100
using namespace std;

class FloatArr
{
    private:
        float v[MAX];
    public:
        // no parameterized constructor..
        float& operator[](int i);
        static int MaxIndex() { return MAX-1; }
};

float& FloatArr::operator[](int i)
{
    if(i<0 || i>=MAX)
    {
        cerr << "\nFloatArr: outside of range!" << endl;
        exit(1);
    }
    return v[i];
}

int main()
{
    cout << "\n An array with range checking!\n" << endl;

    FloatArr random;
    int i;
    srand(time(NULL)); // random seed

    for(i=0; i <= FloatArr::MaxIndex(); ++i)
        random[i] = (rand() - RAND_MAX/2) / 100.0F;

    cout << "\nEnter indices btwn 0 and "
         << FloatArr::MaxIndex() << "!"
         << "\n (quit by entering invalid input)"
         << endl;

    while(cout << "\nIndex: " && cin >> i)
        cout << i << ". element: " << random[i];

    return 0;
}
