#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    long euro, maxEuro; // Amount in Euros
    double rate; // Exchange rate Euro <-> $
    cout << "\n* * * TABLE OF EXCHANGE "
         << " Euro ¨C US-$ * * *\n\n";
    cout << "\nPlease give the rate of exchange: "
            " one Euro in US-$: ";
    cin >> rate;
    cout << "\nPlease enter the maximum euro: ";
    cin >> maxEuro;
    // --- Outputs the table ---
    // Titles of columns:
    cout << '\n'
         << setw(12) << "Euro" << setw(20) << "US-$"
         << "\t\tRate: " << rate << endl;
    // Formatting US-$:
    cout << fixed << setprecision(2) << endl;
    long lower, upper,  // Lower and upper limit
         step;          // Step width
    // The outer loop determines the actual
    // lower limit and the step width:
    for( lower=1, step=1; lower <= maxEuro; step*= 10, lower = 2*step) // big brain
    {
        // The inner loop outputs a "block":
        for( euro = lower, upper = step*10; euro <= upper && euro <= maxEuro; euro+=step)
        {
            cout << setw(12) << euro << setw(20) << euro*rate << endl;
        }
    }

    return 0;
}
