#include <iostream>
#include <cstring>
#define MAXL 200
const char terminate_ch('\0');

using namespace std;

void reverse_char1(const char[], char[]);
void reverse_char2(const char[], char[]);
void reverse_char3(const char*, char*);

int main()
{
    char ch1[MAXL], ch2[MAXL],
         *cPtr1 = ch1, *cPtr2 = ch2;

    while(true)
    {
        // get user input
        cout << "\nEnter something: ";
        // reverse
        if(cin.getline(ch1, MAXL))
        {
            //reverse_char1(ch1, ch2);
            //reverse_char2(ch1, ch2);
            reverse_char3(cPtr1, cPtr2);

            // display result
            cout << "\n--- Result (press CTRL+C to quit) ---\n";
            cout << "your input: " << ch1 << endl;
            cout << "i reversed: " << ch2 << endl;
        }
        else
            break;
    }

    return 0;
}

void reverse_char1(const char s1[], char s2[])
{
    int j(0), maxIndex = strlen(s1) - 1;
    for(int i=maxIndex; i>=0; --i, ++j)
        *(s2 + j) = *(s1 + i);   // using address notation
    *(s2 + j) = terminate_ch;    // fill terminate null character at end point
}

void reverse_char2(const char s1[], char s2[])
{
    int j(0), maxIndex = strlen(s1) - 1;
    for(int i=maxIndex; i>=0; --i, ++j)
        s2[j] = s1[i];          // using index notation
    s2[j] = terminate_ch;       // fill terminate null character at end point
}

void reverse_char3(const char* ptr1, char* ptr2)
{
    const char* tempPtr = ptr1;                // store initial state of ptr1
    for(; *ptr1 != terminate_ch; ++ptr1) { }   // move up to max index
    ptr1--;
    for(; ptr1 >= tempPtr; --ptr1, ++ptr2)
        *ptr2 = *ptr1;         // using pointer notation
    *ptr2 = terminate_ch;      // fill terminate null character at end point
}
