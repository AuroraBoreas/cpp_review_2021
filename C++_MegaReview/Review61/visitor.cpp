#include "graphic.h"
#include "visitor.h"
#include <iostream>

Visitor::~Visitor(){}

void Visitor::visit(const Shape& s) const
{
    std::cout << "visited shape;" << std::endl;
}

void Visitor::visit(const Dot& d) const
{
    std::cout << "visited dot;" << std::endl;
}
