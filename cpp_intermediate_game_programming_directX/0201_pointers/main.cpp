#include <iostream>

using namespace std;

// when to use pointers?
void swap(int*, int*);
void display(int, int);

int main()
{
    int a = 1, b = 2;
    display(a, b);
    swap(a, b);
    display(a, b);

    return 0;
}

void swap(int* a, int* b)
{
    int* temp = b;
    *b = *a;
    *a = *temp;

}
void display(int a, int b)
{
    std::cout << "\n------------\n";
    std::cout << "a = " << a << ", "
              << "b = " << b << "\n";
}
