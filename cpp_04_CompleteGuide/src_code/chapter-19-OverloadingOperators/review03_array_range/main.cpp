#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
#define MAX 200

class FloatArr
{
    private:
        float arr[MAX];
    public:
        // access elements of arr using operator overloading []
        float& operator[](int i)
        {
            // setup boundaries
            if(i<0 || i >= MAX)
            {
                cerr << "index is out of range! \n" << endl;
                exit(1);
            }
            return arr[i];
        }
        static int MaxIndex(void) { return MAX; }
};

int main()
{
    cout << "\n --- An array with range checking! --- \n" << endl;
    FloatArr fa;
    srand(time(NULL));

    for(int i=0; i < FloatArr::MaxIndex(); ++i)
    {
        // u r accessing the private data member of an obj here thou...
        // wtf?
        // my bad
        fa[i] = (rand() - RAND_MAX/2) / 100.0F;
    }

    cout << "\nEnter indices btwn 0 and " << FloatArr::MaxIndex() << "!"
         << "\n (quit by entering invalid input)" << endl;
    int i;
    while(cout << "\nindex: " && cin >> i) // order matters.. wtf?
        cout << i << ". element: " << fa[i];

    return 0;
}
