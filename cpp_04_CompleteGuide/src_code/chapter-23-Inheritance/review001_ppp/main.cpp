#include <iostream>
#include "car.h"

using namespace std;

class Safe
{
    private:
        int topSecret;
    protected:
        int secret;
        // getter
        int getTopSecret(void) const { return topSecret; }
        int getSecret(void)    const { return secret; }
        // setter
        void setTopSecret(int n) { topSecret = n; }
        void setSecret(int n)    { secret = n; }
    public:
        int noSecret;
        Safe()
        {
            topSecret = 100;
            secret = 10;
            noSecret = 0;
        }
};

class Castle: public Safe
{
    public:
        Castle()
        {
            setTopSecret(10);
            secret = 1;
            noSecret = 0;
        }
        void test()
        {
            setTopSecret(200);
            secret = 20;
            noSecret = 2;
        }
};

int main()
{
    PassCar beetle("Beetle", false, 3421, "VM");

    beetle.display();
    beetle.Car::display();

    Castle treasure;
    //treasure.topSecret = 1;
    //treasure.secret = 2;
    //treasure.setTopSecret(5);
    treasure.noSecret = 10;

    return 0;
}
