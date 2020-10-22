// (371) textPtr.cpp

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Demonstrating arrays of char "
         << "and pointers to char. \n"
         << endl;

    char text[] = "Good morning!",
         name[] = "Bill!";
    char* cPtr  = "Hello ";

    cout << cPtr << name << '\n' << text << endl;

    cout << "the text \"" << text
         << "\" starts at address " << (void*)text // (void*)text is equivalent to &text ..
         << endl;

    cout << text + 6
         << endl;

    cPtr = name;

    cout << "this is the " << *cPtr << " of " << cPtr
         << endl;

    *cPtr = 'k';
    cout << "Bill can not " << cPtr << "!\n" << endl;

    // experiment
    cout << endl;
    char town[] = "Beijing"; // {'B', 'e', 'i', 'j', 'i', 'n', 'g', '\0'}
    cout << town << endl;
    cout << &town[0] << endl;
    cout << *town << endl; // array name is the pointer to the index 0 element

    char* iPtr = &town[0];
    // or:
    iPtr = town;
    // display value
    for(int i=0; i < 7; ++i)
    {
        cout << *iPtr << endl;
        iPtr++;
    }
    // display address of each element
    for(int i=0; i < 7; ++i)
    {
        // cout << &town << endl;
        // &town++; // exception. array_name is an pointer to array_name[0] element, BUT it is constant, can NOT be moved like this.
        cout << (void*)iPtr << endl;
        iPtr++; // OK. pointer variable can be moved.
    }

    cout << endl;

    // more experiments
    cout << endl;
    int a(10);
    int numbers[] = {1, 3, 5};
    int* aPtr = &a;
    cout << "int variable a's address = " << &a << endl;
    cout << "aPtr points to a, a's address = " << (void*)aPtr << endl; // or: aPtr
    // or:
    cout << "aPtr's address = " << &aPtr << endl; //?

    // pointer points to integer array
    aPtr = numbers; // or: Ptr = &numbers[0];
    cout << "array numbers' address: " << aPtr << endl; // not work as expected
    cout << "array numbers' address: " << (void*)aPtr << endl;
    cout << "pointer variable Ptr's address: " << &aPtr << endl;

    // pointer points to char array
    char hello[] = "hello world";
    char* hPtr = hello;
    cout << "char array address: " << hPtr << endl;
    cout << "char array address: " << (void*)hPtr << endl;
    cout << "pointer var hPtr address: " << &hPtr << endl;

    // string?
    string strings[] = {"hello world", "are u ok"};
    string* sPtr = strings;
    cout << sPtr << endl;
    cout << (void*)sPtr << endl;
    cout << &sPtr << endl;

    // float?
    float floats[] = {1.1, 1.2, 1.3};
    float* fPtr = floats;
    cout << fPtr << endl;
    cout << (void*)fPtr << endl;
    cout << &fPtr << endl;


    return 0;
}
