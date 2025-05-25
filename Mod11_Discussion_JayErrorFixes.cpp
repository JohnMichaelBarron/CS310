#include <iostream>
#include <conio.h>

using namespace std;

//  -----------------------------------------------------------------------------------------
//  Program that uses templates to take in different data types, find the max and print them out.
//  Letters are converted to their ASCII values.
//  There are three intentional errors in the code, now fixed below.
//  -----------------------------------------------------------------------------------------

//  FIX 1: Added missing 'typename' before Thing2
template <typename Thing1, typename Thing2>

//  FIX 2: Changed duplicate parameter name 'value1' to 'value2'
//  FIX 3: Corrected return expression to use 'value2' instead of the type name 'Thing2'
auto max(Thing1 value1, Thing2 value2) {
    return (value1 > value2) ? value1 : value2;
}

int main() {
    int a = 70;
    double b = 10.5;
    char c = 'A';
    float d = 3.14;

    cout << "\n\n            Welcome to the Max Value Finder Program!"
         << "\n  This program will find the max value of different data types."
         << "\n  -------------------------------------------------------------\n\n";

    cout << "  Max of integer " << a << " and double " << b << " is: " << max(a, b) << endl;
    cout << "  Max of char ASCII value of " << c << " and float " << d << " is: " << max(c, d) << endl;
    cout << "  Max of integer " << a << " and char ASCII value of " << c << " is: " << max(a, c) << endl;
    cout << "  Max of double " << b << " and float " << d << " is: " << max(b, d) << endl;

    cout << "\n  Press any key to continue...\n";
    (void)_getch();
    return 0;
}
