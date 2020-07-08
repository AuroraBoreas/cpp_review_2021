#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    const int lbs_per_stn = 14;
    int lbs;

    cout << "Enter your weight in pounds: ";
    cin  >> lbs;
    int stone  = lbs / lbs_per_stn;
    int pounds = lbs % lbs_per_stn;
    cout << lbs << " pounds are " << stone
         << " stone, " << pounds << " pound(s)" << endl;

    return 0;
}
