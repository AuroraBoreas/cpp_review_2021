#include <iostream>

using namespace std;

struct inflatable
{
    char name[20];
    float volumn;
    double price;
};

int main()
{
    cout << "Hello world!" << endl;

    inflatable A = {"A", 0.2, 12.49};

    cout << "bouquet: " << A.name
         << " for $" << A.price
         << endl;

    inflatable B = A;
    cout << "choice: " << B.name
         << " for $" << B.price
         << endl;

    return 0;
}
