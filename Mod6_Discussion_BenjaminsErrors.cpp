#include <iostream>

enum Color { BLACK, GREY, ORANGE };

int main() {
    Color favoriteColor = GREY; 

    if (favoriteColor == BLACK) {
        std::cout << "Your favorite color is black!" << std::endl;
    } else if (favoriteColor == GREY) {  
        std::cout << "Your favorite color is grey!" << std::endl;
    } else {
        std::cout << "Your favorite color is orange!" << std::endl;
    }

    return 0;
}