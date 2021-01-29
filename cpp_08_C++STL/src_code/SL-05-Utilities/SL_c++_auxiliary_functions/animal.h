#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <iostream>

class Animal
{
private:
    static int m_animalCounter;
public:
    Animal();
    ~Animal();
    static int GetCounter(void);

};

int Animal::m_animalCounter = 0;

inline Animal::Animal()
{
    std::cout << "Animal(" << ++m_animalCounter << ") is born." << std::endl;
}

inline Animal::~Animal()
{
    std::cout << "Animal(" << m_animalCounter-- << ") is destroyed." << std::endl;
}

inline int Animal::GetCounter(void)
{
    return m_animalCounter;
}


#endif // ANIMAL_H_INCLUDED
