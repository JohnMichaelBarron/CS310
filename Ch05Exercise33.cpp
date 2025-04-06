#include <iostream>
using namespace std;

int main() {
    int a; 
    int b; 
    int t;


    do {
        cout << "How much time does it take to make the first dish? (Numbers only): ";
        cin >> a;
        cout << "After the first dish, how much more time does she need to make each additional dish? (Numbers only): ";
        cin >> b;
        cout << "How much time does she have to make all dishes? (Numbers only): ";
        cin >> t;

        if (a <= 0 || b < 0 || t <= 0) { //input validation
            cout << "Invalid input. Please try again using positive values.\n";
        }
    } while (a <= 0 || b < 0 || t <= 0); // if this is true, we gotta go back to the do



    int dish1 = a;
    int runningTotal = 0;
    int dishes = 0;
    cout << "\nDishes prepared and their times: ";
    while (runningTotal + dish1 <= t) {
        cout << dish1;
        runningTotal += dish1;
        dishes++;
        dish1 += b;

        if (runningTotal + dish1 <=t) {
            cout << ", ";
        }
    }
    cout << "\n";

/*  cout << "\nBianca can prepare " << dishes << " dishes in " << t << " minutes.\n";
    cout << "\nBecause each additional dish takes " << a << " minutes, and each next dish takes " << b << " \n";
    cout << "\nmore minutes than the previous one,\n";
    cout << "\nthe total time needed increases like this: " << a << ", " << a + b << ", " << a + 2 * b << ", ....\n";
    cout << "\nand she only has " << t << " minutes in total.\n";
*/
    cout << "\nBianca can prepare " << dishes << " dishes in " << t << " minutes.\n"
         << "Because the first dish takes " << a << " minutes, and each next dish takes " << b << " more minutes than the previous one,\n"
         << "the total time needed increases like this: " << a << ", " << a + b << ", " << a + 2 * b << ", ...\n"
         << "but she only has " << t << " minutes in total.\n";


    return 0;
}
