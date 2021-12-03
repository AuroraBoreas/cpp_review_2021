#include "graphic.h"

Shape::~Shape(){}
void Shape::accept(const Visitor* v) const
{
    v->visit(*this);
}

Dot::~Dot(){}
void Dot::accept(const Visitor* v) const
{
    v->visit(*this);
}
