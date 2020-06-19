#include <iostream>
using namespace std;
int longtomile(long);

int main()
{
    long a;
    cout << "Enter your distance(unit: m): " << endl;
    cin >> a;
    cout << "Woah, it's "
         << longtomile(a)
         << " miles." << endl;
    return 0;
}

int longtomile(long n)
{
    return n * 220;
}
