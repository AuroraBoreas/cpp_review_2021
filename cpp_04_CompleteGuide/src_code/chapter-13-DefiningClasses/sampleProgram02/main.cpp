// P277
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Representive // defining struct representive
{
  string name;
  double sales;
}; // struct semicolon can NOT be omitted.

inline void print(const Representive& v)
{
    cout << fixed << setprecision(2)
         << left  << setw(20) << v.name
         << right << setw(10) << v.sales << endl;
}

int main()
{
    Representive rita, john;
    rita.name   = "Strom, Rita";
    rita.sales  = 37000.37;
    john.name   = "Quick, John";
    john.sales  = 23001.23;

    rita.sales += 1700.11;
    cout << " Representative             Sales\n"
         << "-------------------------------" << endl;
    print(rita);
    print(john);

    cout << "\nTotal of sales: "
         << rita.sales + john.sales << endl;

    Representive *ptr = &john;
    if(john.sales < rita.sales)
        ptr = &rita;

    cout << "\nSalesman of the month: "
         << ptr->name << endl;

    return 0;
}
