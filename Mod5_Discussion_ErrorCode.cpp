//This program takes the user's input of their youtube video length,
//and how fast they prefer playback. Then displays how long the video 
//truly is, with variable playback speed. 

#include <iostream>
#include <iomanip>
using namespace std;


playbackTime(double duration, double speed);


void showTime(double result) {
    cout << fixed << setprecision(2);
    cout << "Adjusted video length: " << result << " minutes" << endl;

    return 0;
}

int main() {
    double videoLength, playbackSpeed;

    cout << "Enter video length in minutes: ";
    cin >> videoLength;

    cout << "Enter playback speed (1.5 for 1.5x): ";
    cin >> playbackSpeed;

    double newTime = playbackTime(videoLength, playbackSpeed);
    showTime(newTime);

    return 0;
}

double playbackTime(double duration, double speed) {
    return duration / speed;
}
