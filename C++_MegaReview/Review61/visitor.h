#ifndef VISITOR_H_INCLUDED
#define VISITOR_H_INCLUDED

class Shape;
class Dot;

class Visitor
{
public:
    ~Visitor();
    void visit(const Shape&) const;
    void visit(const Dot&) const;
};

#endif // VISITOR_H_INCLUDED
