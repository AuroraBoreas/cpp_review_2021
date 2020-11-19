#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Car
{
    private:
        int nr;
        string producer;
    public:
        // constructor
        Car(int n, const string& prod)
        {
            nr = n;
            producer = prod;
        }
        // getter
        int getNr(void)             const { return nr; }
        const string& getProd(void) const { return producer; }
        // setter
        void setNr(int n)             { nr = n; }
        void setProd(const string& p) { producer = p; }
        // repr
        virtual void display(void) const
        {
            cout << "\n-----------------";
            cout << "\nnumber   :   " << nr;
            cout << "\nproducer :   " << producer;
            cout << endl;
        }
};

class PassCar:public Car // inherit
{
    private:
        string passCarType;
        bool sunRoof;
    public:
        // constructor
        PassCar(int n, const string& p, const string& tp, bool b)
        : Car(n, p), passCarType(tp), sunRoof(b)
        {}
        // getter
        // setter
        // repr
        void display(void) const
        {
            cout << "\n-----------------";
            cout << "\nnumber   :   " << Car::getNr();
            cout << "\nproducer :   " << Car::getProd();
            cout << "\ncar type :   " << passCarType;
            cout << "\nsun roof :   ";
            if(sunRoof)
                cout << "yes " << endl;
            else
                cout << "no  " << endl;
        }

};

#endif // CAR_H_INCLUDED
