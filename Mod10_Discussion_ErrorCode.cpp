/* 
John - Michael Barron 
Sliding Window with Pointers 

Ask the user to input a list of numbers, then slide a fixed window
across the array, return sum of window. 

*/



#include <iostream>
using namespace std;

void slidingWindowSum(int arr, int size, int windowSize) {
    if (windowSize > size) {
        cout << "Your window size can't be greater than the number of elements.\n";
        return;
    }

    int* start = arr;                                 //pointer to the start of the window 
    int* end = arr + windowSize;                      //pointer to the end of the window

    while (end <= arr + size) {
        int sum = 0;                                  // reset sum
        for (int* ptr = start; ptr < end; ++ptr) {    
            sum += *ptr;                              //add value pointed to by ptr
        }
        cout << "Window sum: " << sum << endl;
        ++start;                                      // move window one element forward
        ++end;
    }
}

int main() {
    int size;
    cout << "How many numbers do you wanna enter? ";
    cin >> size;

    int* data =  int[size];                      // dynamically allocate memory

    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> data[i];                            //store in array
    }

    int windowSize;
    cout << "Enter the sliding window size: ";
    cin >> windowSize;

    cout << "\nSliding window sums:\n";
    slidingWindowSum(data, size, windowSize);

    delete[] data;                               // free memory / destroy it! throw it into the flames! ... no
    return 0;
}