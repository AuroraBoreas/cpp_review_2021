#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <iostream>
#include <string>
using std::string;
using std::cout;

class Car
{
    private:
        long nr;
        string producer;
    public:
        // constructor
        Car(int n, const string& p)
        : nr(n), producer(p)
        {}
        // destructor
        virtual ~Car(){}
        // getter
        long getNr(void)            const { return nr; }
        const string& getProd(void) const { return producer; }
        // setter
        void setNr(int n)             { nr = n; }
        void setProd(const string& p) { producer = p; }
        // repr
        virtual void display(void) const
        {
            cout << "\n------------------";
            cout << "\nnumber   :   " << nr;
            cout << "\nproducer :   " << producer;
            cout << "\n";
        }
};

class PassCar:public Car
{
    private:
        string passCarType;
        bool   sunRoof;
    public:
        // constructor
        PassCar(const string& tp, bool b, int n = 0L, const string& p = "")
        : Car(n, p), passCarType(tp), sunRoof(b)
        {}
        // destructor
        ~PassCar(){};
        // getter
        // setter
        // repr
        void display(void) const
        {
            cout << "\n------------------";
            cout << "\nnumber   :   " << getNr();
            cout << "\nproducer :   " << getProd();
            cout << "\ncar type :   " << passCarType;
            cout << "\nsun roof :   ";
            if(sunRoof)
                cout << "yes \n";
            else
                cout << "no  \n";
        }
};


#endif // CAR_H_INCLUDED
