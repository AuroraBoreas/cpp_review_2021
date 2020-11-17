#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using std::cout;
using std::endl;

class Animal // base class
{
    public:
        void eat(void)
        //virtual void eat(void)
        { cout << "I'm eating generic food." << endl; }
};

class Cat: public Animal
{
    public:
        void eat(void)
        { cout << "I'm eating rat." << endl; }
};

class Dog: public Animal
{
    public:
        void eat(void)
        { cout << "I'm eating shit." << endl; }
};

#endif // ANIMAL_H
