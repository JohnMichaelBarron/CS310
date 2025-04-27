#include <iostream>
#include <string> //string manip
#include <iomanip> //precision 
using namespace std;

const int candidate_amount = 5;

//valid name str type 
bool validName(const string& name) {
    for (char ch : name) {
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))) {
            return false;

        }
    }
    return true;
}

//valid integer for votes 
int validIntegerType() {
    string greatVariableName;
    int vote;

    while (true) {
        //cin >> vote;
        getline(cin, greatVariableName);  //full line grab
        bool isValid = true;

        for ( char ch : greatVariableName) {
            if (!isdigit(ch)) {
                isValid = false;
                break;
            }
        }
        if (!isValid || greatVariableName.empty()) {   //if its not valid or the input is empty
            cout << "\nInvalid input, please enter a whole number and no letters: ";
            continue;
        }
        vote = stoi(greatVariableName);   //str to int
        return vote;
    }
}


int main() {
    string candidates[candidate_amount];
    int votes[candidate_amount];
    int total_votes = 0;

    //ask for candidate names and the amount of votes per
    for (int i = 0; i < candidate_amount; ++i) {
        do {
            cout << "Enter the last name of candidate number " << (i +1) << ": ";
            cin >> candidates[i];
            cin.ignore(1000, '\n');    //flush out the leftover newline 

            if (!validName(candidates[i])) {
                cout << "That name is invalid, please use letters only.\n";
            }

        } while (!validName(candidates[i]));

        cout << "Enter number of votes for " << candidates[i] << ": ";
        votes[i] = validIntegerType();
        total_votes += votes[i];
    }

    cout << "\nElection Results:\n";
    cout << "Candidate\tVotes \t      Total Votes%\n";
    cout << "_________________________________________\n";

    for (int i = 0; i < candidate_amount; ++i) {
        double percentage = (static_cast<double>(votes[i]) / total_votes) * 100;     // convert int to float for % 
        cout << fixed << setprecision(2);
        cout << candidates[i] << "\t\t" << votes[i] << "\t\t" << percentage << "%\n";
    }

    int winnerWinner = 0;
    for (int i = 1; i < candidate_amount; ++i) {
        if (votes[i] > votes[winnerWinner]) {
            winnerWinner = i;
        }
    }

    cout << "\nThe winner of the election is: " << candidates[winnerWinner] << "!\n";

    return 0;
}