// Computes the final capital with interest and
// compound interest.
// Formula: capital = k0 * (1.0 + p/100)n
// where k0 = start capital, p = rate, n = run time
// ----------------------------------------------------

#include <iostream>
#include <math.h>

using namespace std;

double capital(double k0, double p=3.5, double n=1.0);

int main()
{
    double endcap;
    endcap = capital(100.0, 3.5, 2.5); // OK
    endcap = capital(2222.20, 4.8); // OK
    endcap = capital(3030.00);  // OK

    // endcap = capital(); // not OK
    // endcap = capital(100.0, , 3.0); // not OK
    // endcap = capital(, 5.0); // not OK

    return 0;
}

double capital(double k0, double p, double n)
{
    return (k0 * pow(1.0+p/100, n));
}
