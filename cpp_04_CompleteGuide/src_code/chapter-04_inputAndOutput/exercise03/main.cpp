#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string header("Article Number  Number of Pieces  Price per piece");

    int article_num, qty;
    float unit_price;
    cout << "article number(int): ";
    cin >> article_num;
    cout << "QTY(int): ";
    cin >> qty;
    cout << "unit price(float): ";
    cin >> unit_price;

    cout << header << endl;
    cout << setw(14) << right << article_num;
    cout << setw(18) << right << qty;
    cout << setw(15) << right << unit_price
                     << left << " Dollar" << endl;


    return 0;
}
