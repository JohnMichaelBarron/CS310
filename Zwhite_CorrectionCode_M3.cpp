#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;   // missing semicolon 

    if (number > 0) {
        cout << "The number is positive." << endl;
    }                // missing closing brace for if block
    else
        cout << "The number is zero or negative." << endl;

    return 0;        //added missing semicolon 
}