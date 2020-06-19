#include <iostream>

using namespace std;
void format_time(int, int);

int main()
{
    int h;
    int m;

    cout << "Enter the number of hour(s): ";
    cin >> h;
    cout << "Enter the number of minute(s): ";
    cin >> m;
    format_time(h, m);
    return 0;
}

void format_time(int h, int m)
{
    cout << "Time: "
         << h
         << ":"
         << m << endl;
}
