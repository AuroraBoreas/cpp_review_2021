/*
TMP
static polymorphism(curious...)

Q: what is static polymorphism?
A: using cls template to simulate normal polymorphism

Q: why do we need static polymorphism?
A: trade-off. no thing is real free in the real world.

Q: how to do it?
A: just like cls template

what does polymorphism do?
1. is-a relationship (base cls and derived cls)
2. base cls has algorithm declaration and implementation
3. derived cls has variant implementation of the same algorithm

*/

#include <iostream>

using namespace std;

class Parser
{
    public:
        void Sort(bool b)
        {
            if(b)
            {
                parseName();
            }
        }
        virtual void parseName(void);
};

class PhysicParser: public Parse
{
    public:
        void parseName(void)
        {
            std::cout << "implemented algorithm.\n";
        }
};



int main()
{

    return 0;
}
