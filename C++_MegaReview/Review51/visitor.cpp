#include "visitor.h"
#include "graphic.h"

void Visitor::visit(Dot d) const
{
    std::cout << "visited dot" << std::endl;
}

void Visitor::visit(Shape s) const
{
    std::cout << "visited shape" << std::endl;
}
