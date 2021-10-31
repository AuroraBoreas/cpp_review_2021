#pragma once

class Shape; // technic: forward declaration
class Dot;   // technic: forward declaration

class Visitor
{
public:
    void visit(Shape s) const;
    void visit(Dot d) const;
};
