#pragma once
#include "visitor.h"

class Graphic
{
public:
    virtual void accept(Visitor* v) const {};
};

class Shape: public Graphic
{
public:
    void accept(Visitor* v) const;
};

class Dot: public Graphic
{
public:
    void accept(Visitor* v) const;
};
