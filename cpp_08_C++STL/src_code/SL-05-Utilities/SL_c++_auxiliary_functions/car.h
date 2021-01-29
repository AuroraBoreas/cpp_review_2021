#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <iostream>

class Car
{
private:
    std::string m_name;
    double m_speed;

public:
    // constructors
    Car(double speed)
    {
        m_name = "noname";
        m_speed = speed;
    }

    Car(const std::string& name, double speed)
    : Car(speed)
    { m_name = name; }

    void display(void) const
    {
        std::cout << "\nName: "  << m_name
                  << "\nSpeed: " << m_speed
                  << std::endl;
    }

};

#endif // CAR_H_INCLUDED
