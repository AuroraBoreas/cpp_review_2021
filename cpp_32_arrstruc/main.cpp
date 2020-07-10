#include <iostream>

using namespace std;

//i wanna a stuct
struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    cout << "Hello world!" << endl;

    inflatable guests[3] =
    {
        {"Zhang Liang", 1.1, 59.99},
        {"hello world", 2.2, 99.99},
        {"hello cplusplus", 3.3, 30.99},
    };

    cout << "The guests are "
         << guests[0].name << " "
         << guests[1].name << " "
         << guests[2].name << endl;

    cout << "The prices are "
         << guests[0].price << " "
         << guests[1].price << " "
         << guests[2].price << endl;

    return 0;
}
