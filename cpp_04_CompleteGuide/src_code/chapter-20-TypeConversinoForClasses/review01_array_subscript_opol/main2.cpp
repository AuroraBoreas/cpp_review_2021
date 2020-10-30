#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX 200

using namespace std;

class FloatArr
{
private:
    float v[MAX];
public:
    float& operator[](int i)
    {
        if(i<0 || i>=MAX)
        {
            std::cout << "index is out of range.\n" << std::endl;
            exit(1);
        }
        return v[i];
    }
    static int MaxIndex(void) { return MAX; }
};


int main()
{
    // generate random seed
    srand(time(NULL));
    // initialize FloatArr obj
    FloatArr randoms;
    // populate randoms obj with float numbers
    int i;
    for(i=0; i < FloatArr::MaxIndex() -1; ++i)
        randoms[i] = (rand() - RAND_MAX/2) /100.0;

    // output based on user-chose-index
    cout << "\nEnter an integer btwn 0 and " << FloatArr::MaxIndex() << endl;
    while(cout << "index: " && cin >> i)
        cout << randoms[i] << endl;

    return 0;
}
