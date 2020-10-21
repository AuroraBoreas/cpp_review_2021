#include <iostream>

using namespace std;

class Lights
{
    public:
        enum State { off, red, green, amber };
    private:
        State state;
    public:
        Lights(State s = off) : state(s) {}
        State getState() const { return state; }
        void setState(State s)
        {
            switch(s)
            {
                case off:   cout << "    OFF    "; break;
                case red:   cout << "    RED    "; break;
                case green: cout << "    GREEN  "; break;
                case amber: cout << "    AMBER  "; break;
                default:    return;
            }
            state = s;
        }
};

int main()
{
    cout << "Some statements with objects "
         << "of type Lights!\n";
    Lights A1, A2(Lights::red);
    Lights::State as;
    as = A2.getState();
    if(as == Lights::red)
    {
        A1.setState(Lights::red);
        A2.setState(Lights::amber);
    }
    cout << endl;

    return 0;
}
