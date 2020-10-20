// (353) telList.h

#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "telList.h"
#define MAX_SIZE 10

using namespace std;

void print_array(int* arrPointer);

int main()
{
    int j(0);
    int arr_numbers[MAX_SIZE];

    do
    {

        /* what does time(NULL) mean?
        link: [https://stackoverflow.com/questions/7550269/what-is-timenull-in-c]
        explanation: The call to time(NULL) returns the current calendar time (seconds since Jan 1, 1970)
        also, time_t timer; time(&time); is equivalent to timer = time(NULL);
        */
        std::srand(time(NULL) + j);
        for(int i=0; i < MAX_SIZE; ++i)
            arr_numbers[i] = std::rand() % 100;

        // print array
       print_array(arr_numbers);
    } while(j++ < MAX_SIZE);

    return 0;
}

void print_array(int* arrPointer)
{
    std::cout << "--- generate random sequence ---" << std::endl;
    for(int i=0; i < MAX_SIZE; ++i)
        std::cout << std::setw(6) << arrPointer[i] << std::endl;
}
