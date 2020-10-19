#include <iostream>
#include <string>

using namespace std;

int count = 0;

class Demo
{
    private: string name;
    public: Demo(const string&);
            ~Demo();    // destructor
};

Demo::Demo(const string& str)
{
    ++count; name = str;
    cout << "I am the constructor of " << name << '\n'
         << "This is the " << count << ". object!\n";
}

Demo::~Demo()
{
    cout << "I am the destructor of " << name << '\n'
         << "The " << count << ". object "
         << "will be destroyed " << endl;
    --count;
}

// -- to initialize and destroy objects of class demo --

Demo globalObject("the global object");

int main()
{
    cout << "The first statement in main()." << endl;
    Demo firstLocalObject("the 1. local object");
    {
        static Demo staticObject("the static object");

        cout << "\nLast statement within the inner block"
             << endl;
    }

    cout << "Last statement in main()." << endl;

    // from here before end, implicitly call destructor to destroy all objects
    return 0;
}
