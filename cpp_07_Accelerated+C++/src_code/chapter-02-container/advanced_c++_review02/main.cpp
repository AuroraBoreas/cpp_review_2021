#include <iostream>
#include <string>
#include <vector>

using std::string;

namespace ZL
{
    class Person
    {
        private:
            string* pName_;
        public:
            // constructor
            Person(const string& s)
            {
                pName_ = new string(s);
            }
            // destructor
            virtual ~Person(){ delete pName_; }
            // getter
//            // clone technique
//            Person clone(const Person& p)
//            {
//                return Person(*p.pName_);
//            }

            string* getName(void) const { return pName_; }
            // setter
            // repr
            void display(void) const
            {
                std::cout << *pName_ << std::endl;
            }
    };
}

typedef std::vector<ZL::Person> PersonVec;
typedef PersonVec::const_iterator personIter;

int main()
{
    PersonVec persons;
//    ZL::Person clone = ZL::Person("ZL").clone();

    persons.push_back(ZL::Person("ZL"));
    // step1. construct an obj of "ZL"
    // step2. a copy of "ZL" occurs when passing to vector.push_back() method
    // step3. the obj of "ZL" is destroyed
    persons.back().display(); // bugged af. why?

    return 0;
}
