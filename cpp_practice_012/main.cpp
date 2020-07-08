#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << "Enter the number of seconds: ";
    long long seconds;
    cin  >> seconds;
    const int hours_per_day  = 24;
    const int min_per_hour   = 60;
    const int sec_per_minute = 60;

    int days = seconds / (hours_per_day * min_per_hour * sec_per_minute);
    int hours = seconds % (hours_per_day * min_per_hour * sec_per_minute) / (min_per_hour * sec_per_minute);
    int minutes = (seconds % (hours_per_day * min_per_hour * sec_per_minute) % (min_per_hour * sec_per_minute)) / sec_per_minute;
    int sec = seconds % sec_per_minute;

    cout << seconds << " seconds = "
         << days << " days, "
         << hours << " hours, "
         << minutes << " minutes, "
         << sec << " seconds"
         << endl;

    return 0;
}
