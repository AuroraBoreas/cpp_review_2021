#include "graphic.h"

void Shape::accept(Visitor* v) const
{
    v->visit(*this);
}

void Dot::accept(Visitor* v) const
{
    v->visit(*this);
}
