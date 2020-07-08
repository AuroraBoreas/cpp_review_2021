#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << "Enter the world's population: ";
    long long world_population, us_population;
    cin  >> world_population;
    cout << "Enter the population of the US: ";
    cin  >> us_population;
    cout << "The population of the US is "
         << static_cast<float>(us_population) / world_population * 100
         << "% of the world population." << endl;

    return 0;
}
