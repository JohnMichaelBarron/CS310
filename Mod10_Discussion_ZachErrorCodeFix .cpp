#include <iostream>
#include <string>
using namespace std;

// Base class
class Character {
protected:
    string name;
    int level;
    string class_name;

public:
    Character(string n, int l, string c) : name(n), level(l), class_name(c) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Class: " << class_name << endl;
    }

    // Destructor to handle memory cleanup for derived classes
    virtual ~Character() {}                   // use virtual destructor. always want a virtual destructor when deleting derived class objects through a base class pointer
};

// Child class1
class Sorcerer : public Character {
public:
    Sorcerer(string n, int l) : Character(n, l, "Sorcerer") {}

    void displayInfo() override {
        Character::displayInfo();
        cout << "Primary Ability: Charisma" << endl;
    }
};

// Child class2
class Druid : public Character {
public:
    Druid(string n, int l) : Character(n, l, "Druid") {}

    void displayInfo() override {
        Character::displayInfo();
        cout << "Primary Ability: Wisdom" << endl;
    }
};

// Child class3
class Rogue : public Character {
public:
    Rogue(string n, int l) : Character(n, l, "Rogue") {}

    void displayInfo() override {
        Character::displayInfo();
        cout << "Primary Ability: Dexterity" << endl;
    }
};

int main() {
    // Pointers to the base class (Character) to allocate new variables
    Character* sorcerer = new Sorcerer("Zoey", 11);
    Character* druid = new Druid("Aine", 6);
    Character* rogue = new Rogue("Faye", 4);

    // Display character info using pointers
    cout << "\nCharacter Info:" << endl;
    sorcerer->displayInfo();               //<-  wrong way! use ->
    cout << endl;
    druid->displayInfo();
    cout << endl;
    rogue->displayInfo();
    cout << endl;

    // Destroy variable to deallocate its memory
    delete sorcerer;
    delete druid;
    delete rogue;

    return 0;
}