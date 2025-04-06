#include <iostream>
#include <string>
using namespace std;

int main() {
    string dayOfWeek;
    string daysOfWeek[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; //you missed sunday, which you declared later but still 
    int daysLeft = 0;   // added one too many equal signs

    // Input
    cout << "Enter the day of the week (i.e Monday, Tuesday, etc.): ";
    cin >> dayOfWeek;

    // Output1
    if (dayOfWeek == "Sunday") {     // didn't add enough equal signs! Use comparison ==
        cout << "Weekly assignments are due today, better get to it!" << endl;
    }
    // Repetition control
    else {
        for (int i = 0; i < 6; i++) {    //you used a colon instead of a semi colon 
            if (dayOfWeek == daysOfWeek[i]) {
                daysLeft = 7 - (i + 1);
                break;
            }
        }
        // Output2
        cout << daysLeft << " day(s) left until Sunday, you still have time to complete your weekly assignments!"; //missing semicolon or endl;
    }

    return 0;
}