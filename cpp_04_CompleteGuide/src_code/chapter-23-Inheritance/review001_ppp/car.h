#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

class Car   // base class
{
    private:
        long nr;
        string producer;
    public:
        // constructor
        Car(long n=0L, const string& prod="")
        {
            nr = n;
            producer = prod;
        }
        // getter
        long getNr(void)            const { return nr; }
        const string& getProd(void) const { return producer; }
        // setter
        void setNr(long n)            { nr = n; }
        void setProd(const string& p) { producer = p; }
        // method
        void display(void) const
        {
            cout << "\n------------------------------\n"
                 << "\nCar number:    " << nr
                 << "\nProducer:      " << producer
                 << endl;
        }
};

class PassCar: public Car   // derived class
{
    private:
        string passCarType;
        bool sunRoof;
    public:
        PassCar(const string& tp, bool b, int n=0L, const string& h="")
        : Car(n, h)
        {
            passCarType = tp;
            sunRoof = b;
        }
        // getter
        const string& getType(void) const { return passCarType; }
        bool getSunRoof(void)       const { return sunRoof; }
        // setter
        void setType(const string& s) { passCarType = s; }
        void setSunRoof(bool b)       { sunRoof = b; }
        // repr
        void display(void) const
        {
            Car::display();

            cout << "Type:          " << passCarType;
            cout << "\nSunroof:       ";
            if(sunRoof)
                cout << "yes " << endl;
            else
                cout << "no  " << endl;
        }
};

#endif // CAR_H_INCLUDED
