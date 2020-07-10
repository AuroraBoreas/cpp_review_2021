// ptrstr.cpp -- using pointers to strings
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char animal[20] = "bear";
    const char *bird = "wren"; // bird holds address of string
    char * ps;

    cout << animal << " and ";
    cout << bird << "\n";
    //cout << ps << "\n"; //may display garbage, my cause a crash

    cout << "Enter a kind of animal: ";
    cin  >> animal; // ok if input < 20 chars

    ps = animal;
    cout << ps << "!\n";

    cout << "Before using strcpy(): \n";
    cout << animal << " at " << (int*) animal << endl;
    cout << ps << " at " << (int*) ps << endl;

    ps = new char[strlen(animal) + 1];
    strcpy(ps, animal);
    cout << "After using strcpy():\n";
    cout << animal << " at " << (int*) animal << endl;
    cout << ps << " at " << (int*) ps << endl;
    delete [] ps;

    return 0;
}
