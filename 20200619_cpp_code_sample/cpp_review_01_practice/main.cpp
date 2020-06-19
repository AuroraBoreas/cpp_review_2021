#include <iostream> // insert into this program
using namespace std; // freedom to explore all contents in this whole file
int froop(double);
void rattle(int);
int prune(void);

int main()
{
    cout << "Hello, world" << endl;

    int cheeses;
    cheeses = 32;

    cout << "How many cheeses do you have:" << endl;
    cin >> cheeses;

    cout << "We have " << cheeses
         << " varieties of cheese, " << endl;

    cout << "Let's continue... " << endl;
    int a = froop(5.0);
    cout << "froop(5) = " << a << endl;
    cout << "froop(6) = " << froop(6) << endl;
    cout << "froop(7) = " << froop(7) << endl;
    cout << "Can you figure out pattern of froop?" << endl;

    cout << "Let's continue... " << endl;
    int b;
    cout << "Enter an integer: " << endl;
    cin >> b;
    cout << "Your number is :" << endl;
    rattle(b);

    cout << "I got a number: " << prune() << endl;

    return 0;
}

int froop(double t)
{
    return t * 5;
}

void rattle(int n)
{
    cout << "n = " << n << endl;
}

int prune(void)
{
    return 10;
}
