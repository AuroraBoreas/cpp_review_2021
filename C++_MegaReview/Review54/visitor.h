#pragma once
#include <iostream>

class Dot;
class Shape;

class Visitor
{
public:
    void visit(Dot) const;
    void visit(Shape) const;
};
