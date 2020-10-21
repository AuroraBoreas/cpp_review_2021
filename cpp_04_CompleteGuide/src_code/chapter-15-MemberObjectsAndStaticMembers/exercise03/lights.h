#ifndef LIGHTS_H_INCLUDED
#define LIGHTS_H_INCLUDED

#include <iostream>

class Lights
{
    public:
        enum State { off, red, amber, green };
    private:
        State state;
    public:
        Lights(State s = off):state(s){}; // constructor using enum cant be defined in SF?
        ~Lights() {}
        void wait(int);
};

inline void Lights::wait(int sec)
{
    std::cout << "wait " << sec << " seconds" << std::endl;
}

#endif // LIGHTS_H_INCLUDED
