#include <iostream>
#include <string>
using namespace std;

enum AccessLevel {GUEST, USER, MODERATOR, ADMIN};

int main() {
    string input;
    AccessLevel currentUser;

    cout << "Enter your access level (guest, user, moderator, admin): ";
    cin >> input;

    //Conversion to enum type
    if (input == "guest" || input == "GUEST") {
        currentUser = GUEST;
    } else if (input == "user" || input == "USER") {
        currentUser = USER;
    } else if (input == "moderator" || input == "MODERATOR") {
        currentUser = MODERATOR;
    } else if (input == "admin" || input == "ADMIN") {
        currentUser = ADMIN;
    } else if (input == "developer" || input == "DEVELOPER") {
        currentUser = DEVELOPER;
    } else {
        cout << "Invalid access level." << endl;
        return 1;
    }

    //switch case to display access 
    switch (currentUser) {
        case GUEST:
            cout << "Limited Access granted.\n";
        case USER:
            cout << "User dashboard access granted.\n";
            break;
        case MODERATOR:
            cout << "Moderator tools unlocked.\n";
            break;
        case ADMIN:
            cout << "Admin panel access granted.\n";
            break;
    }
    return 0;
}