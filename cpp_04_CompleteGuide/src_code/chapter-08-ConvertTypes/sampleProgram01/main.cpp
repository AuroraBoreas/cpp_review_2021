#include <iostream>
#include <cmath>

using namespace std;

#define CLS (cout << "\033[2J")
#define LOCATE(z,s) (cout <<"\033["<<(z)<<';'<<(s)<<'H')
#define DOT(x,y) (LOCATE(y,x) << '*')

#define PI 3.1416
#define Mx 40 // The point (Mx, My) is the
#define My 12 // center of the ellipse.
#define A 25 // Length of main axis
#define B 10 // Length of subsidiary axis

int main()
{
    int x, y; // Screen coordinates.

    CLS;

    // 0 <= t <= PI/2 is a 1/4-circle:
    for( double t = 0.0 ; t <= PI/2 ; t += 0.03)
    {
        x = (int) (A * cos(t) + 0.5);
        y = (int) (B * sin(t) + 0.5);
        DOT( x+Mx, y+My);
        DOT( x+Mx,-y+My);
        DOT(-x+Mx, y+My);
        DOT(-x+Mx,-y+My);
    }
    LOCATE(24,0);

    return 0;
}
