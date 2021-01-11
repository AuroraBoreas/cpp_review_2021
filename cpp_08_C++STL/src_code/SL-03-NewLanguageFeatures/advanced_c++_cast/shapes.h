#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include <iostream>

class Shape
{
    public:
        virtual void draw(void) = 0;
        virtual ~Shape(){};
};

class Rectangle: public Shape
{
    public:
        void draw(void) { std::cout << "draw rectangle" << std::endl; }
};

class Circle: public Shape
{
    public:
        void draw(void) { std::cout << "draw circle" << std::endl; }
};


#endif // SHAPES_H_INCLUDED
