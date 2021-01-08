#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Dog
{
    private:
        std::string name;
        std::string breed;
        std::vector<double> v;
    public:
        // default constructor
        Dog(const std::string& s="noname",
            const std::string& b="unknown",
            const std::vector<double>& vec = {3.14, 2.718})
        : name(s), breed(b)
        {
            for(auto i: vec)
            {
                v.push_back(i);
            }
        }
        // more constructors
        // copy constructor
        explicit Dog(const Dog& d) = delete;
        // copy assignment operator
        Dog& operator=(const Dog& d) = delete;
        // boolean operator
        explicit operator bool(void) { return true; }
        // move constructor
        // destructor
        virtual ~Dog() { } // resource management
        // getter
        const std::string& getName(void) const
        { return name; }
        const std::string& getBreed(void) const
        { return breed; }
        // setter
        void setName(const std::string& s)  { name = s; }
        void setBreed(const std::string& b) { breed = b; }
        // repr
        friend std::ostream& operator<<(std::ostream& os, const Dog& d)
        {
            os << "\nname  : " << d.name
               << "\nbreed : " << d.breed
               << "\nvalues: ";
            for(auto i: d.v)
            {
                os << i << '\t';
            }
            return os;
        }
};


int main()
{
    std::cout << "Hello world!" << std::endl;

    Dog d1;
    std::cout << d1 << std::endl;
    std::cout << "\nbool(d1) : " << std::boolalpha << bool(d1) << std::endl;

//    std::cout << (void*)NULL == 0 << std::endl;

    return 0;
}
