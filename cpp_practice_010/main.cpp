#include <iostream>

using namespace std;

float BMI(float height, float weight);
float convert_feet2meter(int feet, int inch);

int main()
{
    cout << "Hello world!" << endl;

    int user_height_feet, user_height_inch, user_weight;
    const float lbs_per_kg     = 2.2f;

    cout << "Enter your height(feet): ";
    cin  >> user_height_feet;
    cout << "Enter your height(inch): ";
    cin  >> user_height_inch;
    cout << "Enter your weight(lbs) : ";
    cin  >> user_weight;

    float user_height_meter = convert_feet2meter(user_height_feet, user_height_inch);
    float user_weight_kg    = user_weight / lbs_per_kg;
    cout << "User height(m)  = " << user_height_meter << endl;
    cout << "User weight(kg) = " << user_weight_kg << endl;
    cout << "Your BMI = " << BMI(user_height_meter, user_weight_kg)
         << endl;

    return 0;
}

float BMI(float height, float weight)
{
    return weight / (height * height);
}

float convert_feet2meter(int feet, int inch)
{
    const int inch_per_foot    = 12;
    const float meter_per_inch = 0.0254f;
    return (feet * inch_per_foot + inch) * meter_per_inch;
}
