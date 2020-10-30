#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAX 200
using namespace std;

class FloatArr
{
    private:
        float v[MAX];
    public:
        float& operator[](int i)
        {
            if(i<0 || i >=MAX)
            {
                std::cerr << "index is out of range.\n" << endl;
                exit(1);
            }
            return v[i];
        }
        static int MaxIndex(void) { return MAX-1; }
};


int main()
{
    srand(time(NULL)); // random seed
    // initialize an FloatArr obj
    FloatArr randoms;
    // populate array
    int i;
    for(i=0; i < FloatArr::MaxIndex(); ++i)
    {
        randoms[i] = (rand() - RAND_MAX/2) / 100.0;
    }
    // output based on user-chose-index
    cout << "\nEnter index btwn 0  and " << FloatArr::MaxIndex() << endl;
    while(cout << "index: " && cin >> i)
        cout << randoms[i] << endl;

    return 0;
}
