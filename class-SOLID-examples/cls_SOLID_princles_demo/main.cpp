#include <iostream>
#include "shape.h"
using namespace std;

int main()
{
    ShapeMaker sm = ShapeMaker();

    sm.drawCircle();
    sm.drawRectangle();
    sm.drawSquare();

    return 0;
}
