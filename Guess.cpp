//
// Created by Dean Wertz on 2/4/18.
//

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

Game:: Game(){}
//Written by Ishan Verma
vector<string> Game:: myVector(){
    vector<string> answer;
    srand((unsigned)time(0));
    for (int i=0;i<4;i++){
        answer.push_back(to_string(rand()%6));
    }
    return answer;
}

//Boolean to test if a string is made up of numeric digits:
//Written by Peter Tempesta
bool Game::checkValidInput(string inputString){
    for (int s = 0; s < inputString.length(); s++){
        if (
        (inputString[s] != '0') &&
        (inputString[s] != '1') &&
        (inputString[s] != '2') &&
        (inputString[s] != '3') &&
        (inputString[s] != '4') &&
        (inputString[s] != '5') &&
        (inputString[s] != '6') &&
        (inputString[s] != '7') &&
        (inputString[s] != '8') &&
        (inputString[s] != '9')
        ) {
                return false;
        }
    }
    return true;
}
//Written by Peter Tempesta
bool Game::checkValidInputCodeMode(string inputString){
    for (int s = 0; s < inputString.length(); s++){
        if (
        (inputString[s] != '0') &&
        (inputString[s] != '1') &&
        (inputString[s] != '2') &&
        (inputString[s] != '3') &&
        (inputString[s] != '4') &&
        (inputString[s] != '5')
        ) {
                return false;
        }
    }
    return true;
}
//Written by Dean Wertz
void Game:: guessPrompt(){

//Sets size of guessing vector
    vector<string> guessingVector(4);
//sets the answer vector equal to the input vector
    vector<string> answer = myVector();
    //Show answer for debugging:
 //   for (int q = 0; q < answer.size(); q ++){
 //       cout << answer[q] << endl;
 //   }
    guesses = 0;
    //hintsUsed for the hints section
    //Written by Ishan Verma and Peter Tempesta (hints section)
    hintsUsed = 0;

//While loop that will keep looping until the turns are up or you have guessed the correct pattern
    while (answer != guessingVector && guesses < 10){
        cout << "Please enter your guess: ";
        cin >> guess ;
//allows the user to give up
//Added by Peter Tempesta
        if (guess == "giveup"){
            break;
        }
//This section , when a player enters 'hint,' will give a helpful hint, with
//up to three hints given. Written by Ishan Verma and Peter Tempesta
        else if (guess == "hint"){
            hintInt = rand()%4;
            hintChar = answer[hintInt];
            if (hintChar == "0"){hintString = "red";}
            if (hintChar == "1"){hintString = "orange";}
            if (hintChar == "2"){hintString = "yellow";}
            if (hintChar == "3"){hintString = "green";}
            if (hintChar == "4"){hintString = "blue";}
            if (hintChar == "5"){hintString = "violet";}
            if (hintsUsed < 2){
                cout << "There is a(n) " << hintString << " peg on the board." << endl;
                hintsUsed++;
            }
            else if (hintsUsed < 3){
                cout << "The peg in position " << hintInt+1 << " is " << hintString << "." << endl;
                hintsUsed++;
            }
            else {
                cout << "Sorry, you used up all of your hints!" << endl;
            }
        }
        else if (guess.length() == 4 && guess != "hint" && checkValidInput(guess)){
            guessingVector[0] = guess[0];
            guessingVector[1] = guess[1];
            guessingVector[2] = guess[2];
            guessingVector[3] = guess[3];
            //Debug(?) slots:
            //slots[guesses] = guessVector[0] + " " + guessVector [1] + " " + guessVector
            guesses = guesses + 1;
            cout << "Number of guesses used: " ;
            cout << guesses << endl;

            //Section to compare pegs and count keys:
            //Written by Peter Tempesta
            int blackKeyCount = 0;
            int whiteKeyCount = 0;
            vector<int> answerKeyFlagVector = {0, 0, 0, 0};

            //First, check for black pegs:
            for (int h = 0; h < 4; h++) {
                if (guessingVector[h] == answer[h] && answerKeyFlagVector[h] == 0) {
                    answerKeyFlagVector[h] = 1;
                    blackKeyCount += 1;
                }
            }
            //Second, check for white pegs:
            for (int h = 0; h < 4; h++) {
                for (int z = 0; z < 4; z++) {
                    if (guessingVector[h] != answer[h] && guessingVector[h] == answer[z] && answerKeyFlagVector[z] == 0 ) {
                        answerKeyFlagVector[z] = 1;
                        whiteKeyCount += 1;
                    }
                }
            }
            //Output of peg color count:
            cout << "Black Key Count: " << blackKeyCount << endl;
            cout << "White Key Count: " << whiteKeyCount << endl;
        }
        //Error handling to handle wrong string input length and wrong string content:
        //Logic by Dean Wertz, text by Ishan Verma and Peter Tempesta
        else if(guess.length() != 4 && checkValidInput(guess)){
            cout << "You must guess with the correct number of pegs!" << endl;
        }
        else{
            cout << "Invalid input, please try again." << endl;
        }
    }
    //Winning text:
    if (answer == guessingVector ){
        cout << "You Win. Whoop Whoop!" << endl;
    }
    //Losing Text:
    else if (guesses >= 10){
        cout << "You used too many guesses, you lose. Good try though!" << endl;
    }
    else {
        cout << "Aww, OK." << endl;
    }
}
//Created by Ishan Verma
void Game::instructions() {
    cout<< endl << "------------Welcome, code breaker!-------------"<<endl;
    cout<<"----Enter these digits for different colors:---"<<endl;
    cout<<"0-Red 1-Orange 2-Yellow 3-Green 4-Blue 5-Violet"<<endl;
    cout<<"----Enter 'hint' for a hint if you're stuck.---"<<endl;
    cout<<"--Enter 'giveup' if you would like to give up.-"<<endl << endl;
}

//Written by Ishan Verma
void Game:: slotsDisplay(){
    for (int i = 0; i < 10; i++){
        slots[i] = "_ _ _ _";
        cout << slots[i] << endl;
    }
}
