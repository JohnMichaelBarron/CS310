// Compiled in VS Code with g++ using default settings (C++17 standard)
// Note: This is my first crack at memory allocation, I know the assignment 
// didn't call for it. Just testing the waters

#include <iostream>
#include <string>
using namespace std;

string accountingFirm = "J&J Accounting";

//How many clients have been processed 
void clientCounter() {
    static int count = 0;
    count ++;
    cout << "Client number: " << count << " processed.\n";
}

//Calculate the billing 
double calcBilling(double rate, int time, bool lowIncome) {
    double billing = 0.0;
    int freeTime;
    double whichRate;

    if (lowIncome) {
        freeTime = 30;
        whichRate = 0.40;
    } else {
        freeTime = 20;
        whichRate = 0.70;
    }

    if (time > freeTime) {
        int extra = time - freeTime;
        billing = rate * whichRate * (extra / 60.0);
    }/* else {
        billing = 0.0
    }
    */
    return billing;
}

int main() {
    double rate;
    int time;
    char incomeAnswer;
    bool lowIncome;
    char loop;

    do {
        cout << "Welcome to " << accountingFirm << "'s tax helper!\n";

        //Input
        cout << "Enter the hourly rate: ";
        cin >> rate;

        cout << "Enter total consulting time in minutes: ";
        cin >> time;

        cout << "Does this individual have low income?(y/n): ";
        cin >> incomeAnswer;

        if (incomeAnswer == 'y') {
            lowIncome = true;
        } else {
            lowIncome = false;
        }
        
        
        // Memory allocation
        //Having trouble understanding if whether or not the memory allocation is working?

        //create a new spot in memory for double, and store the location of that spot in billingAmount
        double* billingAmount = new double;
        *billingAmount = calcBilling(rate, time, lowIncome);

        cout << "Billing amount: $" << *billingAmount << endl;
        cout << "Pointer Address: " << billingAmount << endl;

        clientCounter();

        delete billingAmount;
        //Hopefully this resets the pointer, not using NULL but nullptr 
        billingAmount = nullptr;
        

        cout << "Do you wish to process another client?(y/n): ";
        cin >> loop;

    } while (loop == 'y');

    cout << "Thank you for using " << accountingFirm << " see you next Friday!";
    
    return 0;
}
