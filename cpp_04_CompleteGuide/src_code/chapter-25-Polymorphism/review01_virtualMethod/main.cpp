#include <iostream>
#include "animal.h"

using namespace std;

void feed(Animal* a);


int main()
{
    Animal *animal = new Animal;
    Cat *cat = new Cat;
    Dog *dog = new Dog;

    // object itself do stuff
    animal->eat();
    cat->eat();
    dog->eat();
    // using func
    feed(animal);
    feed(cat);
    feed(dog);


    return 0;
}

void feed(Animal* a)
{
    (*a).eat();
}
