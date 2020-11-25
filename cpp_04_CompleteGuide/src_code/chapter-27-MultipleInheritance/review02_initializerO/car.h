#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <iomanip>
#include <iomanip>
using std::cout;
using std::string;

class Car
{
    private:
        long nr;
        string producer;
    public:
        // constructor
        Car(long n, const string& prod)
        {
            nr = n; producer = prod;
        }
        // destructor
        virtual ~Car() {}
        // getter
        long getNr(void)            const { return nr; }
        const string& getProd(void) const { return producer; }
        // setter
        void setNr(long n)               { nr = n; }
        void setProd(const string& prod) { producer = prod; }
        // repr
        virtual void display(void) const = 0;
};

class PassCar:public virtual Car
{
    private:
        string passCarType;
        bool   sunRoof;
    public:
        // constructor
        PassCar(const string& tp, bool b, long n=0L, const string& prod="")
        : Car(n, prod), passCarType(tp), sunRoof(b){}
        // getter
        const string& getCarType(void) const { return passCarType; }
        bool getSunRoof(void)          const { return sunRoof; }
        // setter
        void setCarType(const string& tp) { passCarType = tp; }
        void setSunRoof(bool b)           { sunRoof = b; }
        // repr
        void display(void) const
        {
            cout << "\nnumber   : " << getNr()
                 << "\nproducer : " << getProd()
                 << "\ncar type : " << passCarType
                 << "\nsun roof : ";
            if(sunRoof)
                cout << "yes \n";
            else
                cout << "no \n";
        }
};

class Van:public virtual Car
{
    private:
        double capacity;
    public:
        // constructor
        Van(double w, long n=0L, const string& prod="")
        : Car(n, prod), capacity(w){}
        // getter
        double getCapacity(void) const { return capacity; }
        // setter
        void   setCapacity(double w) { capacity = w; }
        // repr
        void   display(void) const
        {
            cout << "\ncapacity :   " << std::fixed << std::setprecision(2) << capacity
                 << "\n";
        }
};

class SUV:public PassCar, public Van
{
    private:
        int seats;
    public:
        // constructor
        SUV(int s=1, double w=0.0,
            const string& tp="without type", bool b=false,
            long n=0L, const string& prod="")
        : Car(n, prod), PassCar(tp, b), Van(w), seats(s){}
        // getter
        int  getSeats(void) const { return seats; }
        // setter
        void setSeats(int s) { seats = s; }
        // repr
        void display(void) const
        {
            PassCar::display();
            Van::display();
            cout << "\nseats    : " << seats
                 << "\n";
        }
};

#endif // CAR_H_INCLUDED
