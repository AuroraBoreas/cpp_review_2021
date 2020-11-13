#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Car
{
    private:
        int    nr;
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
            cout << "\n-------------------\n"
                 << "\nproducer :   " << producer
                 << "\nnumber   :   " << nr
                 << endl;
        }
};

class PassCar:public Car
{
    private:
        string passCarType;
        bool   sunRoof;
    public:
        // constructor
        PassCar(const string& tp, bool b, int n=0L, const string& p="")
        : Car(n, p), passCarType(tp), sunRoof(b) {}
        // getter
        const string& getPassCarType(void) const { return passCarType; }
        bool getSunRoof(void)              const { return sunRoof; }
        // setter
        void setPassCarType(const string& tp) { passCarType = tp; }
        void setSunRoof(bool b)               { sunRoof = b; }
        // repr
        void display(void) const
        {
            cout << "\n-------------------\n"
                 << "\nproducer :   " << getProd()
                 << "\nnumber   :   " << getNr()
                 << "\ncar type :   " << passCarType
                 << "\nsun roof :   ";
            if(sunRoof)
                cout << "yes " << endl;
            else
                cout << "no  " << endl;
        }
};

class Truck:public Car
{
    // ...
    private:
        int    seats;
        double weight;
    public:
        // constructor
        Truck(int len, double w, int n=0L, const string& p="")
        : Car(n, p), seats(len), weight(w) {}
        // getter
        int getSeat(void)      const { return seats; }
        double getWeight(void) const { return weight; }
        // setter
        void setSeat(int n)      { seats = n; }
        void setWeight(double w) { weight = w; }
        // repr
        void display(void) const
        {
            cout << "\nproducer :   " << getProd()
                 << "\nnumber   :   " << getNr()
                 << "\nseats    :   " << seats
                 << "\nweight   :   " << weight
                 << endl;
        }
};

#endif // CAR_H_INCLUDED
