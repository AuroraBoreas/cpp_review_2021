#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void printArrayAddr(int*, int);

int main()
{
    cout << "Hello world!" << endl;

    srand(time(NULL));

    int arr[10];

    for(int i = 0; i < 10; ++i)
    {
        arr[i] = rand() % 100;
    }

    for(int i = 0; i < 10; ++i)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // pointer of an array
    int* arrPointer = arr;
    cout << arrPointer << endl;
    cout << endl;

    printArrayAddr(arrPointer, 10);
    cout << endl;
    cout << "byte of int type: " << sizeof(int) << endl;
    cout << "MAX INT: " << INT_MAX << endl;

    return 0;
}

void printArrayAddr(int* arrayPointer, int num)
{
    for(int i = 0; i < num; ++i)
    {
        cout << arrayPointer << endl;
        arrayPointer++;
    }
}
