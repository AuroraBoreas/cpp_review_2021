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
        // method, array op ol
        float& operator[](int i)
        {
            if(i<0 || i>MAX)
            {
                cerr << "\nindex is out of range!" << endl;
                exit(1);
            }
            return v[i];
        }
        static int MaxIndex(void) { return MAX; }
};

int main()
{
    // initialize a FloatArr obj
    FloatArr randoms;
    // random seed
    srand(time(NULL));
    // populate floats into the FloatArr obj
    int i;
    for(i=0; i < FloatArr::MaxIndex(); ++i)
        randoms[i] = (rand() - RAND_MAX/2)/100.0;

    // output based on index from user-input
    cout << "\n--- Get Random Floats ---\n\n";
    while(cout << "Index: " && cin >> i)
        cout << randoms[i] << endl;

    return 0;
}
