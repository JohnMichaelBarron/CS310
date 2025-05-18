/*
Written by John-Michael Barron  
Ch12Exercise03 – Dynamic Candidate Tracker

This program asks the user for the number of election candidates,
dynamically allocates arrays to store their names and vote counts,
validates input, and calculates voting percentages and a winner.

Compiled with:
g++ -std=c++17 
*/

#include <iostream>
#include <string>
#include <iomanip> // for setprecision
using namespace std;

// Validate that the name contains only letters
bool validName(const string& name) {
    for (char ch : name) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return !name.empty(); // Ensure it's not blank
}

// Validate integer input for vote count
int validIntegerType() {
    string input;
    int vote;

    while (true) {
        getline(cin, input);
        bool isValid = true;

        for (char ch : input) {
            if (!isdigit(ch)) {
                isValid = false;
                break;
            }
        }

        if (!isValid || input.empty()) {
            cout << "Invalid input, please enter a whole number with no letters: ";
            continue;
        }

        vote = stoi(input);
        return vote;
    }
}

int main() {
    int numCandidates;
    cout << "Enter the number of candidates running: ";
    cin >> numCandidates;
    cin.ignore(); // flush newline

    // Dynamically allocate arrays
    string* candidates = new string[numCandidates];
    int* votes = new int[numCandidates];
    int total_votes = 0;

    // Gather candidate data
    for (int i = 0; i < numCandidates; ++i) {
        do {
            cout << "Enter the last name of candidate #" << (i + 1) << ": ";
            getline(cin, candidates[i]);

            if (!validName(candidates[i])) {
                cout << "That name is invalid, please use letters only.\n";
            }

        } while (!validName(candidates[i]));

        cout << "Enter number of votes for " << candidates[i] << ": ";
        votes[i] = validIntegerType();
        total_votes += votes[i];
    }

    // Output results
    cout << "\nElection Results:\n";
    cout << "Candidate\tVotes\t% of Total Votes\n";
    cout << "---------------------------------------\n";

    for (int i = 0; i < numCandidates; ++i) {
        double percentage = (static_cast<double>(votes[i]) / total_votes) * 100;
        cout << fixed << setprecision(2);
        cout << candidates[i] << "\t\t" << votes[i] << "\t" << percentage << "%\n";
    }

    // Determine winner
    int winner = 0;
    for (int i = 1; i < numCandidates; ++i) {
        if (votes[i] > votes[winner]) {
            winner = i;
        }
    }

    cout << "\nThe winner of the election is: " << candidates[winner] << "!\n";

    // Clean up memory
    delete[] candidates;
    delete[] votes;

    return 0;
}
