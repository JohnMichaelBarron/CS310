//
// Created by Randy Easton on 5/2/2025.
//

#include <iostream>
#include <random>
#include <cmath>
#include <iomanip>

using namespace std;
class Driver {          //enum isn't for defining full class structures
    static int driverID_seed;
    int driverID;
    string fname;
    string lname;
    int dob;
    int issue;

    public:
        // Quick Set
        Driver(string f, string l, int d, int i) {  //capitalize driver 
            fname = f;
            lname = l;
            dob = d;
            issue = i;
            driverID = driverID_seed++;
        }

        // Get
        string getFullName() const { return fname + " " + lname; }
        int getDriverID() const { return driverID; }
        int getDOB() const { return dob; }
        int getIssueYear() const { return issue; }


};

 class Car {                 //change this to class Car
    static int vin_seed;
    int vin;
    string make;
    string model;
    int year;

    public:
        //Quick set
        Car(string m, string mo, int y) { // capitalize car
            make = m;
            model = mo;
            year = y;
            vin = vin_seed++;
        }

        // Get
        int getVIN() { return vin; }
        string getFullModel() { return make + " " + model; }
        int getYear() { return year; }
};
int Car::vin_seed = 99999999;
int Driver::driverID_seed = 9999999;  //capitalize class names
int main(){
    string fname;
    string lname;
    int dob = 0;
    int issue = 0;

    string make;
    string model;
    int year;

    // Create a driver
    cout << "Whats Your First name?" << endl;
    cin >> fname;
    cout << "Whats your Last name?" << endl;
    cin >> lname;
    cout <<  "What year were you born" << endl;
    cin >> dob;
    cout <<  "What year was your licensed issued?" << endl;
    cin >> issue;

    Driver d1(fname, lname, dob, issue); //missing argument , capitlize driver

    // Create a car
    cout << "What is the Make/Manufacture of your car" << endl;
    cin >> make;
    cout << "What is the Model of Your Car" << endl;
    cin >> model;
    cout <<  "What year was your car made?" << endl;
    cin >> year;
    Car c1(make, model, year); //capitalize car

    // Output Info
    cout << "Driver Info:\n";
    cout << "Name: " << d1.getFullName() << endl;
    cout << "Driver ID: " << d1.getDriverID() << endl;
    cout << "DOB: " << d1.getDOB() << " | License Issued: " << d1.getIssueYear() << endl;

    cout << "\nCar Info:\n";
    cout << "Model: " << c1.getFullModel() << endl;
    cout << "VIN: " << c1.getVIN() << endl;
    cout << "Year: " << c1.getYear() << endl;


    return 0;

} // remove semicolon 