#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

class MathError
{
    private:
        string message;
    public:
        // constructor
        MathError(const string& s="")
        {
            message = s;
        }
        // getter
        const string& getMessage(void) const
        {
            return message;
        }
};

double calc(int, int) throw(MathError);

int main()
{
    int a, b; double res; bool flag=false;

    do
    {
        try
        {
            cout << "\nenter two integers: ";
            cin >> a >> b;
            res = calc(a, b);
            cout << a << "/" << b << " = "
                 << std::fixed << std::setprecision(2) << res;
            flag = true;
        }
        catch(MathError& err)
        {
            cout << err.getMessage() << endl;
            std::exit(1);
        }
        catch(...)
        {
            cout << "unexpected error!\n";
            std::exit(1);
        }
    } while(!flag);

    return 0;
}

double calc(int a, int b) throw(MathError)
{
    if(b<0)
    {
        MathError("b is negative!");
    }
    if(b==0)
    {
        MathError("b is zero!");
    }
    return ((double)a/b);
}
