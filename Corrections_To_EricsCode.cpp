/*
 Original Code: https://github.com/EricZimmer87/CS310/blob/main/M2_Discussion/M2_Discussion.cpp
 The original program had the following two errors:
 1. Used 'cin << firstName;' instead of 'cin >> firstName;' to take input.
 2. Was missing the '<<' operator in the final course prompt output line.
 To fix the errors, I corrected the input operator and added the missing output operator.
 */

#include <iostream>
using namespace std;

int main() {
    string firstName;
    string lastName;

   
    cout << "What is your first name?" << endl;
    cin >> firstName; // Fix incorrect input operator

    
    cout << "What is your last name?" << endl;
    cin >> lastName;

    
    cin.ignore();

    
    string favoriteCourse;
    cout << "Hello, " << firstName << " " << lastName << "! What is your favorite course?" << endl; // Add missing output operator
    getline(cin, favoriteCourse);

    
    if (favoriteCourse != "Programming with C++") {
        cout << "Wrong! Your favorite course is Programming with C++!" << endl;
    }
    else {
        cout << "Correct!" << endl;
    }

    return 0;
}
