#include <iostream>
#include <iomanip> // fixed and precision 
#include <locale> 
 
using namespace std;

int main() {
    double netBalance, payment, interestRate, averageDailyBalance, interest;
    int d1, d2;

    //Input
    cout << "Enter net balance: ";
    cin >> netBalance;
    cout << "Enter payment amount: ";
    cin >> payment;
    cout << "Enter the number of days in a billing cycle (d1): ";
    cin >> d1;
    cout << "Enter the number of days before billing cycle payment was made (d2): ";
    cin >> d2;
    cout << "Enter the monthly interest rate (Example: 0.15): ";
    cin >> interestRate;

    averageDailyBalance = (netBalance * d1 - payment*d2)/d1;
    interest = averageDailyBalance * interestRate;

    //Output

    /*
    
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);
    Could not get this to work on my windows system even with 
    en_US.UTF-8
    en_US

    Can write a function to write commas manually but I don't 
    think we're there yet...

    */

    cout << fixed << setprecision(2);
    locale loc("C");
    cout.imbue(loc); // only way it ran, doesn't show thousands separator 

    cout << "\n";
    cout << left << setw(30) << "Average Daily Balance: $" << averageDailyBalance << endl;
    cout << left << setw(30) << "Interest: $" << interest << endl;

    return 0;
    
}