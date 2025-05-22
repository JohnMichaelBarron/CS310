/* Note: I didn't account for input validation, just experimenting with template usage 
Compiled with:
g++ -std=c++17 in VScode
*/


#include <iostream>
#include <string>
using namespace std;

// Template to compare my pet's weights, my pets are fat :( 
template <class Type>                                          //compare any type(int, float, double) 
Type bigBoi(Type weight1, Type weight2) {
    return (weight1 > weight2) ? weight1 : weight2;           //return the greater of the two, with > operator 
}

int main() {
    cout << " Welcome to the Pet Weight Checker \n";

    string name1, name2;
    float weight1, weight2;                                   //float flexible for partial pounds

    // pet names and weights
    cout << "Enter the name of your first pet: ";
    getline(cin, name1);

    cout << "Enter " << name1 << "'s weight (in pounds): ";
    cin >> weight1;
    cin.flush(); // flush newline

    cout << "Enter the name of your second pet: ";
    getline(cin, name2);

    cout << "Enter " << name2 << "'s weight (in pounds): ";
    cin >> weight2;

    cout << "\n Comparing " << name1 << " and " << name2 << "...\n";

    float heavier = bigBoi(weight1, weight2);              // call template with float arguments


    if (heavier == weight1 & weight1 != weight2)
        cout << name1 << " is heavier at " << weight1 << " lbs.\n";
    else if (heavier == weight2 & weight1 != weight2)
        cout << name2 << " is heavier at " << weight2 << " lbs.\n";
    else
        cout << "Wow! Both " << name1 << " and " << name2 << " weigh the same: " << weight1 << " lbs.\n";

    return 0;
}