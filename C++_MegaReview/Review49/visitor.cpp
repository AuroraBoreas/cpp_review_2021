#include "visitor.h"
#include "graphic.h"
#include <iostream>

void Visitor::visit(Shape s) const
{
    std::cout << "Visited shape" << std::endl;
}
void Visitor::visit(Dot d) const
{
    std::cout << "Visited dot" << std::endl;
}
