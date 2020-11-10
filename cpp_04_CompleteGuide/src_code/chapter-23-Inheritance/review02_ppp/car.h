#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Car
{
    private:
        string producer;
        int nr;
    public:
        // constructor
        Car(const string& s_prod, int n=0L)
        { producer = s_prod; nr = n; }
        // getter
        const string& getProd(void) const { return producer; }
        int getNr(void)             const { return nr; }
        // setter
        void setProd(const string& s) { producer = s; }
        void setNr(int n)             { nr = n; }
        // repr
        void display(void) const
        {
            cout << "\n--------------------\n"
                 << "\nProducer:    " << producer
                 << "\nNumber  :    " << nr;
        }
};

class PassCar: public Car
{
    private:
        string passCarType;
        bool   sunRoof;
    public:
        PassCar(const string& prod, int n, const string& tp, bool b)
        : Car(prod, n), passCarType(tp), sunRoof(b)
        {}
        // getter
        const string& getCarType(void) const { return passCarType; }
        bool getSunRoof(void)          const { return sunRoof; }
        // setter
        void setCarType(const string& tp)  { passCarType = tp; }
        void setSunRoof(bool b)            { sunRoof = b; }
        // repr
        void display(void) const
        {
            cout << "\n--------------------\n"
                 << "\nProducer:    " << getProd()
                 << "\nNumber  :    " << getNr()
                 << "\nType    :    " << passCarType
                 << "\nSunRoof :    ";
            if(sunRoof)
                cout << "yes " << endl;
            else
                cout << "no  " << endl;
        }
};

#endif // CAR_H_INCLUDED
