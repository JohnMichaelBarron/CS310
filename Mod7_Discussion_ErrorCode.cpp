/* Created by John-Michael
Programming with C++ (2D arrays)
Program should display a gridded maze, 7 across, 5 down as a rectangle. 
hint: my endl; seems a bit impatient. 2 errors, 1 formatting flaw */

#include <iostream>
using namespace std;

const int row = 5;
const int col = 7;

int maze[row][col] = {
    {0, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 1, 1, 0},
    {1, 1, 0, 0, 0, 0, 0}    
}

void displayTheMaze() {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (maze[i][j] == 1){
                cout << "#";
            } else {
                cout << ".";
            }
            cout << endl;
        }
        
    }
}

int main() {
    cout << "This is my maze hope ya like it!\n";
    displayMaze();
    return 0;
}