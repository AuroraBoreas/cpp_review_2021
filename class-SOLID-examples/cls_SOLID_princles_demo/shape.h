#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <iostream>
class Shape
{
public:
    Shape(){}
    virtual ~Shape(){}
    virtual void draw()=0;
};

class Rectangle: public Shape
{
public:
    void draw()
    {
        std::cout << "Rectangle::draw()" << std::endl;
    }
};

class Square: public Shape
{
public:
    void draw()
    {
        std::cout << "Square::draw()" << std::endl;
    }
};

class Circle: public Shape
{
public:
    void draw()
    {
        std::cout << "Circle::draw()" << std::endl;
    }
};

// facade patterns

class ShapeMaker
{
private:
    Shape *circle;
    Shape *rectangle;
    Shape *square;
public:
    ShapeMaker()
    {
        circle    = new Circle();
        rectangle = new Rectangle();
        square    = new Square();
    }
    ~ShapeMaker()
    {
        delete circle;
        delete rectangle;
        delete square;
    }
    void drawCircle()    { circle->draw(); }
    void drawRectangle() { rectangle->draw(); }
    void drawSquare()    { square->draw(); }
};


#endif // SHAPE_H_INCLUDED
