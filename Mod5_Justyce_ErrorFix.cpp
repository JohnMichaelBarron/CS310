#include <iostream>
using namespace std;

// Function prototype (fixes Error #1)
float circleArea(float radius);

int main()
{
    float radius;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    float area = circleArea(radius);

    cout << "The area of the circle is " << area << "." << endl; //line break - maybe a little cleaner

    return 0;
}

// Correct return type (fixes Error #2)
float circleArea(float radius)
{
    float pi = 3.1415;

    float area = pi * radius * radius;

    return area;
}
