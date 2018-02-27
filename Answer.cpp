#include "Game.h"
#include <cstdlib>
#include <ctime>
using namespace std;
// Author Dean Wertz
void Game::answerPrompt() {
    //random number generator
   srand((unsigned)time(0));
   //temporary random variables that will be used to get 2 of the user pins
   int tempAnswer1;
   int tempAnswer2;
   tempAnswer1 = rand()%2+1;
   tempAnswer2 = rand()%2+1;

   //declaring size of player and computer  arrays
   vector <string> playerAnswer(4);
   vector <string> compAnswer(4);

   //starts answer portion of game and converts input string to array of strings for user answer
   cout<< endl << "--------------Welcome, coder!------------------"<<endl;
   cout<<"----Enter these digits for different colors:---"<<endl;
   cout<<"0-Red 1-Orange 2-Yellow 3-Green 4-Blue 5-Violet"<<endl;
   cout << "Please enter your answer: ";
   while(playerAnswerString.length() != 4 || !checkValidInputCodeMode(playerAnswerString)){
       cin >> playerAnswerString ;
       playerAnswer[0] = playerAnswerString[0];
       playerAnswer[1] = playerAnswerString[1];
       playerAnswer[2] = playerAnswerString[2];
       playerAnswer[3] = playerAnswerString[3];
       if(playerAnswerString.length() != 4 || !checkValidInputCodeMode(playerAnswerString)){
            cout << endl << "Please try again. You must enter four digits" << endl;
            cout << "between 0 and 5 corresponding to their colors." << endl << endl;
       }
   }
   //initializes computer guesses
   compGuesses = 0;
//while the computer hasn't guessed ten times yet and the computer hasn't guessed the right answer
   while(compAnswer != playerAnswer && compGuesses < 10){
       if(tempAnswer1== 1){
           compAnswer[0] = playerAnswer[0];
           compAnswer[1] = to_string(rand()%7+0);
       }
       if(tempAnswer1== 2){
           compAnswer[0] = to_string(rand()%7+0);
           compAnswer[1] = playerAnswer[1];
       }

       if(tempAnswer2== 1){
           compAnswer[2] = playerAnswer[2];
           compAnswer[3] = to_string(rand()%7+0);
       }
       if(tempAnswer2== 2){
           compAnswer[2] = to_string(rand()%7+0);
           compAnswer[3] = playerAnswer[3];
       }

// adds a guess to the guess counter for computer
       compGuesses = compGuesses + 1;

//prints out information after each guess
       cout<< "Computer Guess ";
       cout << compGuesses;
       cout << ": ";
       cout << compAnswer[0];
       cout << compAnswer[1];
       cout << compAnswer[2];
       cout << compAnswer[3]<< endl;

   }
//if the computer wins you are told that you lose
   if (compAnswer == playerAnswer){
     cout <<  "Sorry to say it, but you got beaten!" << endl;
   }

//if the computer can't win in ten turns then you win
   if (compGuesses >= 10){
       cout << "You beat the computer player!" << endl;
   }

}

