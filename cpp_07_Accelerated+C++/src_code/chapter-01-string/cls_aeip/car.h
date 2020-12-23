#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

class Car
{
    private:
        unsigned int nr;   // car number
        string       name; // maker
    public:
        // constructor
        Car(unsigned int n=0L, const string& s="")
        : nr(n), name(s){}
        // destructor
        virtual ~Car(){}
        // getter
        unsigned int  getNr(void)   const { return nr; }
        const string& getName(void) const { return name; }
        // setter
        void setNr(unsigned int n)    { nr = n; }
        void setName(const string& s) { name = s; }
        // repr
        string asString(void) const
        {
            stringstream ss;
            ss << "\nnumber : " << nr
               << "\nname   : " << name;
            return ss.str();
        }
        virtual void display(void) const = 0;
};

class PassCar: public Car
{
    private:
        bool sunRoof;
    public:
        // constructor
        PassCar(unsigned int n=0L, const string& s="", bool b=false)
        : Car(n, s), sunRoof(b) {}
        // destructor
        ~PassCar(){}
        // getter
        bool getSunRoof(void) const { return sunRoof; }
        // setter
        void setSunRoof(bool b) { sunRoof = b; }
        // repr
        string asString(void) const
        {
            stringstream ss;
            ss << Car::asString();
            ss << "\nsunroof: ";
            if(sunRoof)
                ss << "yes\n";
            else
                ss << "no\n";
            return ss.str();
        }

        void display(void) const
        {
            std::cout << asString() << std::endl;
        }
};

class Truck: public Car
{
    private:
        unsigned int seats;
        double       weight;
    public:
        // constructor
        Truck(unsigned int n=0L, const string& s="",
              unsigned int se=1, double we=0.0)
        : Car(n, s), seats(se), weight(we){}
        // destructor
        ~Truck(){}
        // getter
        unsigned int getSeats(void)  const { return seats; }
        double       getWeight(void) const { return weight; }
        // setter
        void setSeats(unsigned int se) { seats = se; }
        void setWeight(double we)      { weight = we; }
        // repr
        string asString(void) const
        {
            stringstream ss;
            ss << Car::asString();
            ss << "\nseats  : " << seats;
            ss << "\nweight : " << weight;
            return ss.str();
        }
        void display(void) const
        {
            std::cout << asString() << std::endl;
        }
};

#endif // CAR_H_INCLUDED
