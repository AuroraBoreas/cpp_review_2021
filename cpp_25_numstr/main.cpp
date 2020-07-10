#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << "What year was your house built?\n";
    int year;
    cin  >> year;
    cin.get(); // or cin.get(ch);
    // or (cin >> year).get();
    cout << "What is its street address?\n";
    int len_address = 80;
    char address[len_address];
    cin.getline(address, len_address);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";

    return 0;
}
