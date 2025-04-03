
//WARNING
//be prepared to type Ctrl+C while in the terminal! 
#include <iostream>
using namespace std;

int main() {
    int i;

    for (; i <= 3; i++) { 
        cout << "This is a for loop and should print 3 times. Number: " << i << endl;
    }

    int j = 1;
    while (j <= 3) {
        cout << "While loop. Should print 3 times. Number: " << j << endl;
        j++;
    }

    int k = 1;
    do {
        cout << "Do-while loop. Should print 3 times. Number: " << k << endl;
        
    } while (k <= 3);

    return 0;
}
