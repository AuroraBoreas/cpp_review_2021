#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int arr[3] = {1, 2, 3},
        *iPointer = arr;

    for(int i=0; i < 3; ++i)
    {
        cout << arr+i << " = " << *(arr+i) << endl;

    }

    return 0;
}
