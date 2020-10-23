#include <iostream>
#include <cstring>
#define MAX_SIZE 80

using namespace std;

void reverse_char(char[], char[]);

int main()
{
    while(true)
    {
        cout << "\nenter your words: ";

        char ch1[MAX_SIZE],
             ch2[MAX_SIZE];
        cin.getline(ch1, MAX_SIZE);

        reverse_char(ch1, ch2);

        cout << "\nyour words: " << ch1 << endl;
        cout << "reversed  : " << ch2 << endl;

        cout << "\n--- do u wanna play again? ---\n";
        cout << "(press CTRL+C to quit)" << endl;
    }
    return 0;
}

void reverse_char(char s1[], char s2[])
{
    // pointer version
    char *ptr1, *ptr2 = s2;
    // do u like which form? char* ptr; char* ptr2?
    int len1 = strlen(s1);

    for(ptr1 = s1 + len1 - 1; ptr1 >= s1; --ptr1) // why tf not working? // because s2 is overflowed. and NO FKING Error?!
    {
        // s2[i] = *ptr1;
        *ptr2 = *ptr1;
        ptr2++;
    }
    *ptr2 = '\0';

    // using index version
    /*
    int i(0), j(0);

    for(int i=strlen(s1)-1; i >= 0; --i)
    {
        s2[j] = s1[i]; j++;
    }
    s2[j] = '\0';
    */
}
