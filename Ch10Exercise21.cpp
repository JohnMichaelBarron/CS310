/*
Written by John-Michael Barron 
Bank Accounts

This program was written to manage client bank accounts.
Usage of accessor, and mutator functionos to retrieve and display account 
details. Private data is only accessed in a controlled way.

*/


#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

class bankAccount {
private: 
    string name;
    int accountNumber;
    string accountType;  //checking/saving
    double balance;
    double interestRate;
    static int nextAccountNumber; //starting at 100
public:
    bankAccount() {
        name = "";
        accountType = "";
        balance = 0.0;
        interestRate = 0.0;
        accountNumber = nextAccountNumber++;
    }

    //mutator
    void glueAccount(string accName, string accType, double accBalance, double rate) {
        name = accName;
        accountType = accType;
        balance = accBalance;
        interestRate = rate;
    } 
    //accessor functions, getters, read only access to privates(const, do not modify!)
    string getName() const {return name;}
    int getAccountNumber() const {return accountNumber;}
    string getAccountType() const {return accountType;}
    double getBalance() const {return balance;}
    double getInterestRate() const {return interestRate;}

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully.\n";
        } else {
            cout << "Either you're broke, or that number wasn't a number.\n";
        } 
    
    }   

    //apply the interest rate to balance void function necessary?

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "$" << amount << " deposited successfully.\n";
        } else{
            cout << "Invalid deposit amount.\n";
        }
    }


    void displayAccountInfo() const {
        cout << fixed << setprecision(2);
        cout << "=========================\n";
        cout << "Name          : " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Type          : " << accountType << endl;
        cout << "Balance       : " << balance << endl;
        cout << "Interest Rate : " << interestRate << endl;
        cout << "============================\n\n";
        
    }
};

//input validation for the int/numbers
bool realNumber(const string& st) {
    if (st.empty()) {
        return false;
    }
    bool foundADecimal = false;
    for (char ch : st) {
        if (isdigit(ch)) {
            continue;
        }
        if (ch == '.' && !foundADecimal) {
            foundADecimal = true;
            continue;
        }
        return false;
    }
    return true;
}

//input validation for text 
bool realText(const string& st) {
    if (st.empty()) {
        return false;
    }
    for (char ch : st) {
        if (!isalpha(ch) && !isspace(ch)) {
            return false;
        }
    }
    return true;
}

//static member account number, changes per new client 
int bankAccount:: nextAccountNumber = 100;
int main() {
    bankAccount client[10];
    int numClients = 0;
    string tellerInput;

    while (numClients < 10) {
        string name;
        string type;
        string balanceString;
        string rateString;
        double balance;
        double rate;

        //get all the information about the client 
        cout << "Enter account holder's name(letters only): ";
        getline(cin, name);
        while (!realText(name)) {
            cout << "Please... enter a real name.. jeez.";
            getline(cin, name);
        }

        cout << "Enter account type (checking/saving): ";
        getline(cin, type);
        while (!realText(type) || (type != "checking" && type != "saving")) {
            cout << "Try again, checking or saving: ";
            getline(cin, type);
        }

        cout << "Enter your initial balance: ";
        getline(cin, balanceString);
        while (!realNumber(balanceString)) {
            cout << "Please, enter a real number. You can use a decimal point if you need to: ";
            getline(cin, balanceString);
        }
        //convert the string to a double
        balance = stod(balanceString);

        cout << "Enter the interest rate as a decimal: ";
        getline(cin, rateString);
        while(!realNumber(rateString)) {
            cout << "Please enter a valid rate(example .002, .04): ";
            getline(cin, rateString);
        }
        //convert rate string to double
        rate = stod(rateString);

        //add new object to array of the clients
        bankAccount newClient;
        newClient.glueAccount(name, type, balance, rate);
        client[numClients] = newClient;
        numClients++;

        cout << "Do you want to add another client? (y/n): ";
        getline(cin, tellerInput);
        if (tellerInput != "y" && tellerInput != "Y") {
            break;
        }
    
    }
    cout << "\nClient Accounts:\n";
    for (int i = 0; i < numClients; ++i) {
        client[i].displayAccountInfo();
    }
    
    
    return 0;
}