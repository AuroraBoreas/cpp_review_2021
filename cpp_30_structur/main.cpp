#include <iostream>

using namespace std;

struct myStruct
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    cout << "Hello world!" << endl;

    myStruct guest =
    {
        "Zhang Liang",
        1.88,
        29.99
    };

    myStruct pal =
    {
        "hello World",
        3.12,
        32.99,
    };

    cout << "guest list is "
         << guest.name
         << " and "
         << pal.name << endl;

    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "total volumes are "
         << guest.volume + pal.volume << endl;

    cout << "total price is "
         << guest.price + pal.price << endl;

    return 0;
}
