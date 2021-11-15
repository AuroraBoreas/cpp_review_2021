#pragma once
#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED

#include "visitor.h"

class Graphic
{
public:
    virtual void accept(const Visitor* v) const = 0;
};

class Shape: public Graphic
{
public:
    void accept(const Visitor* v) const;
};

class Dot: public Graphic
{
public:
    [[deprecated("zl cao scy!")]]
    void accept(const Visitor* v) const;
};

#endif // GRAPHIC_H_INCLUDED
