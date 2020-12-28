#include <iostream>
#include <string>
#include <iomanip>
#define SQUARE(x) ((x) * (x))
using std::string;
using std::cout;
using std::endl;
using std::cin;

float final_score(float, float, float);

namespace ZL
{
    char c = 'a', *cPtr = &c;
    int* a = reinterpret_cast<int*>(cPtr);

    void display(void)
    {
       char cArr[] = "Bonjour Tout le Monde!";
       char* ptr = cArr;
       for(; *ptr != '\0'; ++ptr)
       {
           cout << *ptr << ' ';
       }
    }
}


int main()
{
    cout << "\nEnter your first name: ";
    string prenome;
    cin >> prenome;
    cout << "\nHello " << prenome << endl;
    cout << "\nEnter your final exam score: ";
    float fes;
    cin >> fes;
    cout << "\nEnter your midterm exam score: ";
    float mes;
    cin >> mes;
    cout << "\nEnter your homework grades: ";
    float hwg;
    cin >> hwg;

    cout << "\nyour final score is : "
         << std::fixed << std::setprecision(1)
         << final_score(fes, mes, hwg) << endl;


    // unittest
    cout << "\na = " << *ZL::a << endl;
    ZL::display();

    // macro
    cout << "\n\nSQUARE(10) = " << SQUARE(10) << endl;

    return 0;
}

float final_score(float final_exam, float midterm_exam, float homework)
{
    return (final_exam * 0.4 + midterm_exam * 0.2 + homework * 0.4);
}
