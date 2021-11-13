#pragma once
#include "visitor.h"

class Graphic
{
public:
    virtual void accept(Visitor) const = 0;
};

class Shape: public Graphic
{
public:
    void accept(Visitor) const;
};

class Dot: public Graphic
{
public:
    void accept(Visitor) const;
};
