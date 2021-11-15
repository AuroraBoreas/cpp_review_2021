#include <iostream>
#include <vector>
#include <algorithm>
#include "graphic.h"
#include "visitor.h"


int main()
{
    std::cout << "Hello world!" << std::endl;

    Visitor v = Visitor();
    Shape s = Shape();
    Dot d = Dot();

    std::vector<Graphic*> g{&d, &s};

    std::for_each(g.begin(), g.end(),
                  [&](const Graphic* e){ e->accept(&v); });

    std::cin.get();

    return 0;
}
