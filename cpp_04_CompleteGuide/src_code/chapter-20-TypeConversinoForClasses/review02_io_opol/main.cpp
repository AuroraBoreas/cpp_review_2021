#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Euro
{
    private:
        long data;
    public:
        // --- constructors ---
        Euro(int euro=0, int cents=0)
        { data = 100L * (long)euro + cents; }
        Euro(double x)
        { x *= 100.0; data = (long)(x>0.0? (x+0.5) : (x-0.5)); }
        // --- repr ---
        string asString(void) const
        {
            stringstream ss;
            long temp = data;
            if(temp < 0) { temp=-temp; ss << '-'; }
            ss << (temp/100) << ',' << setw(2) << setfill('0') << (temp%100);
            return ss.str();
        }
        // --- member method overloads operator ---
        Euro& operator+=(const Euro& e)
        {
            this->data += e.data;
            return *this;
        }
        // --- global io operator overloading using friend techniques
        friend ostream& operator<<(ostream& os, const Euro& e)
        {
            os << e.asString() << endl;
            return os;
        }

        friend istream& operator>>(istream& is, Euro& e)
        {
            cout << "Euro amount (Format ...x,xx): ";
            int euro = 0, cents = 0; char c = 0;
            if(!(is >> euro >> c >> cents)) // input
                return is;
            if((c != ',' && c != '.') || cents>=100)
                is.setstate(ios::failbit);
            else
                e = Euro(euro, cents);
            return is;
        }

        // --- conversion function ---
        operator double() const
        { return (double)data/100.0; }
};


int main()
{
    Euro e1, e2;
    // test cout o operator overloading
    cout << e1 << endl;
    // test cin i operator overloading
    cout << "\nEnter something: ";
    cin >> e2;
    cout << e2 << endl;

    // test conversion
    Euro my(100),
         your(321.41);

    my = 987.12;

    your += 20;

    your = Euro(999.99); // explicit conversion(constructor style)

    my = (Euro)123.45; // explicit conversion(cast style)

    your = my;

    Euro salary(8888,80);
    double x(0.0);
    salary += 1000;     // implicit, int -> double -> Euro, using Euro(double) constructor
    salary += 0.10;     // implicit, double -> Euro, using Euro(double) constructor
    x = salary;         // implicit, Euro -> double, using conversion function technique
    x = (double)salary; // explicit, Euro -> double, using cast style
    x = salary.operator double(); // possible? yes
    x = double(salary); // explicit, Euro -> double using conversion function technique
    int i = salary;     // Euro -> double -> int

    cout << " salary = " << salary;
    cout << "      x = " << x << endl;
    cout << "      i = " << i << endl;

    Euro retail, wholesale;
    retail = wholesale + 46.9; // OK..
    cout << retail << endl;
    retail = 46.9 + wholesale; // OK
    cout << retail << endl;

    return 0;
}
