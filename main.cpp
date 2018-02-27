#include <iostream>
#include <vector>
#include "Game.h"

using namespace std;

int main() {

    Game gameInstance;
    string gameChoiceString;
    string playAgainString;
//Written by Ishan Verma
    cout << endl << "--------------Welcome to Mastermind!------------------" << endl;
    cout << "Would you like to break a code or set a code to break?" << endl;
    cout << "Enter '1' to break a code or '0' to set a code." << endl;
//Written by Ishan Verma
    cin >> gameChoiceString;
    while (gameChoiceString != "0" && gameChoiceString != "1") {
        cout << "Invalid input. Please enter '1' or '0.'" << endl;
        cin >> gameChoiceString;
    }
    //By Ishan Verma
    if (gameChoiceString == "1") {
        gameInstance.instructions();
        gameInstance.guessPrompt();
    }
    else {
        gameInstance.answerPrompt();
    }

    cout << "Enter '1' to play again or '0' to exit." << endl;

    cin>>playAgainString;
    while (playAgainString != "0" && playAgainString != "1") {
        cout << "Invalid input. Please enter '1' or '0.'" << endl;
        cin >> playAgainString;
    }
    if (playAgainString == "1") {
        main();
    }

    return 0;
}
