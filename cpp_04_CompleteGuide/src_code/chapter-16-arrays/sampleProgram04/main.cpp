#include <iostream>
#define MAX_ROW 2
#define MAX_COL 5

using namespace std;

char names[2][20] = { "Zhang, Liang",
                      "Hello, world!"
                    };
int numbers[2][5] = {
                      {44, 50, 60, 74, 81},
                      {32, 64, 120, 69, 22}
                    };


int main()
{
    for(int i=0; i < MAX_ROW; ++i)
    {
        std::cout << names[i] << std::endl;
        for(int j=0; j < MAX_COL; ++j)
        {
            std::cout << numbers[i][j] << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}
