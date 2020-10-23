#include <iostream>
using namespace std;

void print_sum(int[]);

int num[10] = {1, 2, 3},
    *ptr = num;


int main()
{
    print_sum(num);

    return 0;
}

void print_sum(int num[10])
{
    int sum(0);
    for(int i=0; i < 10; ++i)
        sum += num[i];
    cout << "total: " << sum << endl;
}
