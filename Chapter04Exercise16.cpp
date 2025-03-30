#include <iostream> 
#include <iomanip>
using namespace std;

int main() {
    //all variables
    double option2Rate = 0.125;
    double option3Rate1 = 0.10;
    double option3Rate2 = 0.14;
    int option3Cutoff = 4000;
    double option1Total = 5000 + 20000;

    double netPrice;
    int estimatedCopies;

    //input
    cout << "Enter the net price of each copy: ";
    cin >> netPrice;
    cout << "Enter the estimated number of copies to be sold: ";
    cin >> estimatedCopies;

    //Royalties
    double option2Royalty = netPrice * estimatedCopies * option2Rate;

    double option3Royalty;
    if (estimatedCopies <= option3Cutoff) {
        option3Royalty = netPrice * estimatedCopies * option3Rate1;
    }
    else {
        option3Royalty = (netPrice * option3Cutoff * option3Rate1) +
        (netPrice * (estimatedCopies - option3Cutoff) * option3Rate2);
    }

    //what's the best option
    double bestRoyalty;
    int bestOption;

    if (option1Total >= option2Royalty && option2Royalty >= option3Royalty) {
        bestRoyalty = option2Royalty;
        bestOption = 2;
    }

    else if (option2Royalty >= option1Total && option2Royalty >= option3Royalty) {
        bestRoyalty = option2Royalty;
        bestOption = 2;
    }

    else {
        bestRoyalty = option3Royalty;
        bestOption = 3;
    }

    //now i gotta display allll the options 
    cout << fixed << setprecision(2);
    cout << "\nOption 1 Royalty: $" << option1Total << endl;
    cout << "Option 2 Royalty: $" << option2Royalty << endl;
    cout << "Option 3 Royalty: $" << option3Royalty << endl;

    //switch
    switch (bestOption) {
        case 1:
            cout << "\nThe best option is Option 1 with a royalty of $" << bestRoyalty << "." << endl;
            break;
        case 2:
            cout << "\nThe best option is Option 2 with a royalty of $" << bestRoyalty << "." << endl;
            break;
        case 3:
            cout << "\nThe best option is Option 3 with a royalty of $" << bestRoyalty << "." << endl;
            break;

    }
    return 0;
}