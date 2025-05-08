
#include <iostream>
using namespace std;

class Element {                              // Base
protected:                                   //protected(child classes can access these members)
    string name;
    string symbol;
    int atomicNumber;
public:
    Element(string n, string s, int a) {    //Constructor
        name = n;
        symbol = s;
        atomicNumber = a;
    }

    const explainElement() {
        cout << "Element: " << name << " (" << symbol << "), Atomic Number: " << atomicNumber << endl;
    }
};

class Metal: public Element {               //Derived
public:
    Metal(string n, string s, int a): explainElement(n, s, a) {}      //constructor

    void explainElement() {
        cout << name << " is a metal. It conducts electricity and has a symbol: " << symbol << "." << endl;
    }
};

class NonMetal : public Element {           //Derived
public: 
    NonMetal(string n, string s, int a) : Element(n, s, a) {}

    void explainElement() {
        cout << name << " is a non-metal. It is reactive and has a symbol: " << symbol << "." << endl;
    }
};

int main() {
    Metal sodium("Sodium", "Na", 11);        //Create metal
    NonMetal oxygen("Oxygen", "O", 8);       //create nonmental
    sodium.explainElement();                 //call metal:: explainElement
    oxygen.explainElement();                 //repeat
    return 0;
}