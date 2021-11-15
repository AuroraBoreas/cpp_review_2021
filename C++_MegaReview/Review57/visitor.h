#include <iostream>
#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

class Shape;
class Dot;

class Visitor
{
public:
    void visit(const Shape& s) const;
    void visit(const Dot& d) const;
};

#endif // VISITOR_H_INCLUDED
