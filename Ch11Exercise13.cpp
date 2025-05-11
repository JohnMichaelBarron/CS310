/*
Written by John-Michael Barron  
Ch11Exercise13 – Bank Accounts

This program manages bank accounts using object-oriented programming.
It uses a base class (`bankAccount`) and two derived classes 
(`checkingAccount` and `savingsAccount`) to simulate real-world account types.

It demonstrates:
- Class inheritance and polymorphism
- Use of accessor and mutator functions to maintain data privacy
- Input validation for numerical and text fields
- Dynamic memory allocation using base class pointers
- Virtual functions and function overriding for specific account behaviors

Accounts are created based on user input and stored in a polymorphic array.
Each account is then displayed with its relevant info before memory is deallocated.

Compiled using:  
g++ -std=c++17 Ch11Exercise13.cpp -o Ch11Exercise13
*/


#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

class bankAccount {
protected: 
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

    virtual void withdraw(double amount) {
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


    virtual void displayAccountInfo() const {
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

//Checking account class
class checkingAccount : public bankAccount {
private:
    double minimumBalance;
    double serviceCharge;

public:
    checkingAccount() : minimumBalance(0.0), serviceCharge(0.0) {}
    //mutators / setters
    void setInterestRate(double rate) { interestRate = rate; }
    void setMinBalance( double min) { minimumBalance = min; }
    void setServiceCharge(double charge) { serviceCharge = charge; }

    //accessors / getters
    double getMinBalance() const { return minimumBalance; }
    double getServiceCharge() const { return serviceCharge; }

    void postInterest() {
        deposit(balance * interestRate);
    }

    bool belowMinimum() const {
        return balance < minimumBalance;
    }


    void writeCheck(double amount) {
        withdraw(amount);
        
    }

    void withdraw(double amount) override {
        if (belowMinimum()) {
            cout << "Your balance is below the minimum... You get a charge!\n";
            bankAccount::withdraw(amount);
        }
        bankAccount::withdraw(amount);
    }

    void displayAccountInfo() const override {
        bankAccount::displayAccountInfo();
        cout << "=====================\n";
        cout << "Minimum Balance     : " << minimumBalance << endl;
        cout << "Service Charge      : " << serviceCharge << endl;
        cout << "=====================\n\n";
    }   
    
};

//savings account 
class savingsAccount : public bankAccount{
public:
    savingsAccount() {}

    void setInterestRate(double rate) { interestRate = rate; }
    void postInterest(){
        deposit (balance * interestRate);
    }

    void withdraw(double amount) override{
        if (amount <= balance) {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully from savings.\n";
        } else {
            cout << "Either you're broke, or that number wasn't a number.\n";
        }
    }
    
    void displayAccountInfo() const override {
        bankAccount::displayAccountInfo();
        cout << "=========================\n\n";
    }
};

int main() {
    bankAccount* client[10];  //upgrade to add array of pointers to base class 
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

        //create the right account
        if (type == "checking") {
            string minimumString, chargeString;
            double minimumBalance, serviceCharge;

            cout << "Enter the minimum balance required: ";
            getline(cin, minimumString);
            while (!realNumber(minimumString)) {
                cout << "Now now let's enter a real minimum balance: ";
                getline(cin, minimumString);
            }
            minimumBalance = stod(minimumString);

            cout << "Enter the service charge for dropping below the minimum: ";
            getline(cin, chargeString);
            while (!realNumber(chargeString)) {
                cout << "Thats not a real charge, enter a real charge: ";
                getline(cin, chargeString);
            }
            serviceCharge = stod(chargeString);

            // Dynamically create the appropriate account type based on user input.
            // If the user selected "checking", create a checkingAccount, apply all relevant settings
            // (name, type, balance, interest, minimum balance, service charge), then store the pointer.
            // If "saving", create a savingsAccount, apply its settings, and store the pointer.
            // These are stored in a base-class pointer array (bankAccount*) using polymorphism.
            checkingAccount* cA = new checkingAccount();               
            (*cA).glueAccount(name, "checking", balance, rate);
            (*cA).setMinBalance(minimumBalance);
            (*cA).setServiceCharge(serviceCharge);
            (*cA).setInterestRate(rate);
            client[numClients] = cA;

        } else if (type == "saving") {
            savingsAccount* sA = new savingsAccount();
            (*sA).glueAccount(name, "saving", balance, rate);
            (*sA).setInterestRate(rate);
            client[numClients] = sA;
        }

        numClients++;


        cout << "Do you want to add another client? (y/n): ";
        getline(cin, tellerInput);
        if (tellerInput != "y" && tellerInput != "Y") {
            break;
        }
    
    }
    cout << "\nClient Accounts:\n";
    for (int i = 0; i < numClients; ++i) {
        (*client[i]).displayAccountInfo();
    }
    for (int i = 0; i < numClients; ++i) {
        delete client[i];  // deallocates the object dynamically created
    }
    
    return 0;
}