/* 
   Code written by John-Michael Barron 
   2255-1
   Ch07Exercise04
   My approach to solving this was to create multiple functions handling
   vowel disection based upon input. (Valid/Invalid/VowelTerminator) Then one main function to execute.
*/


#include <iostream>
#include <string> 
using namespace std;

const string badLetters = "aeiouAEIOU";       // these are the bad bads, remove with force 


// function that removes vowels from users response to the prompt. one character at a time 
void theTerminator(string& response) {
    bool aeiou = false;                       //flip it if we catch a vowel 
    for (size_t i = 0; i < response.size(); ) {
        if (badLetters.find(response[i]) != string::npos) {
            response.erase(i, 1);             //take the vowel out of the word 
            aeiou = true;                     //gotcha
        } else {
            ++i;                              // move on incrimentally if no bad bads
        }
    }
    if (!aeiou) {
        cout << "Congrats! There were no vowels in your word!\n";
    }
}
//only letters and spaces please. If I find something wrong I send you back 
//you can borrow this string, but you're not allowed to write on it
//passes original string not copy(string& str), and can't modify it(const)
bool isItValidThough(const string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        char character = str[i];                //rejection if its not a letter or a space
        if (!(( character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character == ' '))) {
            return false; 
        }
    }
    return true;
}

int main() {
    string response;

    do {
        cout << "Enter a word or a sentence please!: ";
        getline(cin, response);      //full input, not just a single word, otherwise use cin << 

        if (response.empty()) {
            cout << "Hey you didn't enter anything, please enter SOMETHING: \n";

        } else if (!isItValidThough(response)) {
            cout << "No numbers or symbols allowed! Try again.\n";
            response.clear();       //clear up space from initial response 
        }
    }  while (response.empty());
   
    theTerminator(response);     //run response through the terminator to clean it up 

    cout << "Upon removing all the vowels, you new word/sentence is: " << response << endl;

    return 0;
}