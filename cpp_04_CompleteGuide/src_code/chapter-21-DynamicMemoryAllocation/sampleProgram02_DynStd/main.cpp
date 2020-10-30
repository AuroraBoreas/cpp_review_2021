#include <iostream>

using namespace std;

int main()
{
    cout << "\nTesting dynamic storage allocation! " << endl;
    // --- allocate storage ---
    double width = 23.78;
    double* ptrWidth = &width;             // static allocation
    double* ptrLength = new double(32.54); // dynamic allocation with initialization
    double* ptrArea = new double;          // dynamic allocation w/i initialization
    // --- calculate ---
    *ptrArea = *ptrWidth * *ptrLength;
    delete ptrLength;   // Error: the obj is still in use?
    // --- display ---
    cout << "\nWidth    : " << *ptrWidth
         << "\nLength   : " << *ptrLength
         << "\nArea     : " << *ptrArea
         << endl;
    // --- free storage ---
    //delete ptrWidth;    // Error: the obj has not been dynamically reserved
    delete ptrLength;   // OK
    delete ptrArea;     // OK

    ptrLength = new double(19.45);
    // --- name a dynamic obj ---
    double& length = *ptrLength;    // store double-type value to double-type var
    cout << "\nNew length   : " << length
         << "\nCircumference: " << 2 * width * length
         << endl;

    return 0;
}
