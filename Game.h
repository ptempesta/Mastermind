//
// Authored by Ishan Verma, Dean Wertz, and Peter Tempesta
//

#include <vector>
#include <string>
#include <iostream>

//#ifndef CS205MASTERMIND_GAME_H   //Default ifndef statement for Ishan and Dean's laptops
//#define CS205MASTERMIND_GAME_H
#ifndef GAME_H_INCLUDED            //ifndef statement for Peter's laptop
#define GAME_H_INCLUDED

using namespace std;

class Game {
public:
/**
* Requires: nothing
* Modifies: nothing
* Effects: Creates a mastermind game constructor that will be used for the game object
* @return: nothing
*/
    Game();


    /**
* Requires: an input string
* Modifies: a boolean that checks for valid input
* Effects: whether input is valid or not
* @return: boolean
*/
    bool checkValidInput(string inputString);

        /**
* Requires: an input string
* Modifies: a boolean that checks for valid input (used for setting up a code)
* Effects: whether input is valid or not
* @return: boolean
*/
    bool checkValidInputCodeMode(string inputString);

    /**
* Requires: nothing
* Modifies: nothing
* Effects: starts part of game where user comes up with an answer and computer guesses it
* @return: nothing
*/
    void answerPrompt();

    /**
* Requires: nothing
* Modifies: nothing
* Effects: starts part of game where user comes up with an answer and computer guesses it
* @return: nothing
*/
    void guessPrompt();

       /**
* Requires: nothing
* Modifies: nothing
* Effects: starts provides instructions on how to play the game
* @return: nothing
*/
    void instructions();

        /**
* Requires: nothing
* Modifies: nothing
* Effects: Displays peg guesses
* @return: nothing
*/
    void slotsDisplay();


//Vectors used by answer and guess
    vector<string> answer;
    vector<string> compGuess;
    vector<string> guessVector;
    vector<string> myVector();
    vector<string> slots;

//string variables for guess and answers
    string guess;
    string hintChar;
    string hintString;
    string playerAnswerString;

//int variables for guess and answers
    int compGuesses;
    int guesses;
    int hintInt;
    int hintsUsed;

};

//#endif //CS205MASTERMIND_GAME_H
#endif //GAME_H_INCLUDED

