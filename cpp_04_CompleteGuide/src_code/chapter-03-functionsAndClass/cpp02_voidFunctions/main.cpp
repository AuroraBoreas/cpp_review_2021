#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    unsigned int seed;
    int z1, z2, z3;
    cout << "   --- Random Numbers  --- \n" << endl;
    cout << "To initialize the random number generator, "
         << "\nplease enter an integer value: ";
    cin  >> seed;
    srand(seed); // by default, implicitly srand(1);

    z1 = rand();
    z2 = rand();
    z3 = rand();

    cout << "\nThree random numbers: "
         << z1 << " " << z2 << " " << z3 << endl;


    return 0;
}
