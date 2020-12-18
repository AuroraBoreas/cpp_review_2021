#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using std::ostream;
using std::stringstream;
using std::string;
using std::cout;
using std::endl;

class Car
{
private:
    unsigned long nr;
    string        name;
public:
    // constructor
    Car(unsigned long n, const string& s)
    : nr(n), name(s) {}
    // destructor
    virtual ~Car(){}
    // getter
    unsigned long getNr(void) const { return nr; }
    const string& getName(void) const { return name; }
    // setter
    void setNr(unsigned long n)   { nr = n; }
    void setName(const string& s) { name = s; }
    // repr
    string asString(void) const
    {
        stringstream ss;
        ss << "\nnumber :   " << nr;
        ss << "\nname   :   " << name;
        return ss.str();
    }
    friend ostream& operator<<(ostream& os, const Car& c)
    {
        os << c.asString();
        return os;
    }
    virtual void display(void) const = 0;
};

class PassCar: public Car
{
private:
    bool sunRoof;
public:
    // constructor
    PassCar(unsigned long n=0L, const string& s="", bool b = false)
    : Car(n, s), sunRoof(b){}
    // destructor
    ~PassCar(){}
    // getter
    bool getSunRoof(void) const { return sunRoof; }
    // setter
    void setSunRoof(bool b) { sunRoof = b; }
    // repr
    void display(void) const
    {
        stringstream ss;
        ss << Car::asString();
        ss << "\nSunRoof:   ";

        if(sunRoof)
            ss << "Yes";
        else
            ss << "No";
        cout << ss.str() << endl;
    }
};

class Truck: public Car
{
private:
    double weight;
    unsigned int seats;
public:
    // constructor
    Truck(unsigned long n=0L, const string& s="", double w = 0.0, unsigned int se=4)
    : Car(n, s), weight(w), seats(se){}
    // destructor
    ~Truck() {}
    // getter
    double getWeight(void)      const { return weight; }
    unsigned int getSeats(void) const { return seats; }
    // setter
    void setWeight(double w)       { weight = w; }
    void setSeats(unsigned int se) { seats = se; }
    // repr
    void display(void) const
    {
        stringstream ss;
        ss << Car::asString();
        ss << "\nweight :   " << std::fixed << std::setprecision(2) << weight;
        ss << "\nseats  :   " << seats;
        cout << ss.str() << endl;
    }
};

class Van: public PassCar, public Truck
{
public:
    // constructor
    Van(unsigned long n=0L, const string& s="",
        bool b = false,
        double w = 0.0, unsigned int se=4)
    : PassCar(n, s, b), Truck(n, s, w, se){}
    // destructor
    ~Van() {}
    // repr
    void display(void) const
    {
        PassCar::display();
        Truck::display();
    }
};

#endif // CAR_H_INCLUDED
