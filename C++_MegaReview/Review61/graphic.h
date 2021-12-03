#pragma once
#ifndef GRAPHIC_H_INCLUDED
#define GRAPHIC_H_INCLUDED

#include "visitor.h"

class Graphic
{
public:
    ~Graphic(){};
    virtual void accept(const Visitor*) const = 0;
};

class Shape: public Graphic
{
public:
    ~Shape();
    void accept(const Visitor*) const;
};

class Dot: public Graphic
{
public:
    ~Dot();
    void accept(const Visitor*) const;
};

#endif // GRAPHIC_H_INCLUDED
