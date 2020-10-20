// (351) multidim.cpp
#include <iostream>
#include <iomanip>

using namespace std;

char representative[2][20] = {"Armstrong, Wendy", "Beauty Eve"};
int articleCount[2][5] = {
                            {20, 51, 30, 17, 44},
                            {150, 120, 90, 110, 88}
                          };


int main()
{
    for(int i=0; i < 2; ++i)
    {
        std::cout << "\nRepresentative: " << representative[i];
        std::cout << "\nNumber of items sold: ";

        for(int j=0; j < 5; j++)
        {
            std::cout << std::setw(6) << articleCount[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
    return 0;
}
