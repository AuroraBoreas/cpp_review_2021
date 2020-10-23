#include <iostream>

using namespace std;

int arr[] = {1, 2, 3},
    *ptr;


int main()
{
    // index notation
    cout << "\nindex notation: " << endl;
    for(int i=0; i < 3; ++i)
        cout << &arr[i] << " = " << arr[i] << '\t';
    cout << endl;

    // address notation
    cout << "\naddress notation: " << endl;
    for(int i=0; i < 3; ++i)
    {
        cout << arr + i << " = " << *(arr + i) << '\t';
        // or:
        // cout << (void*)(arr + i) << " = " << *(arr + i) << '\t';
    }
    cout << endl;

    // pointer variable
    cout << "\npointer notation: " << endl;
    ptr = arr;
    for(int i=0; i < 3; ++i)
    {
        cout << ptr + i << " = " << ptr[i] << '\t'; // see line 29. hahaha
    }
    cout << endl;

    return 0;
}
