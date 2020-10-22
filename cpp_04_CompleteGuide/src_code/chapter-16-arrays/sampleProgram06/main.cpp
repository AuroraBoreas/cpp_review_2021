#include <iostream>

using namespace std;

char names[2][20] =
{
    "Zhang, Liang",
    "GSN, SCY",
};

int numbers[2][5] =
{
    {10, 20, 30, 40, 60},
    {3, 5, 7, 11, 13},
};

int main()
{
    for(int i=0; i < 2; ++i)
    {
        std::cout << names[i] << std::endl;
        for(int j=0; j < 5; ++j)
        {
            std::cout << numbers[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
