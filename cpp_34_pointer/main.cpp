#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int update = 6;
    int *p_update;
    p_update = &update;

    cout << "update value = " << update << endl;
    cout << "update value = " << *p_update << endl;

    cout << "update address = " << &update << endl;
    cout << "update address = " << p_update << endl;

    return 0;
}
