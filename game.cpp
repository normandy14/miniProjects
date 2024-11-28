#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool DEBUG = false;
bool DEBUG2 = false;
bool DEBUG3 = false;
bool DEBUG4 = false;

int PL1SCORE = 0;
int PL2SCORE = 0;

string CHOICES[] = {"rock", "paper", "scissors"};

void greet() {
  cout << "Welcome to Rock Paper Scissors Game" << endl;
}

void printScore() {
  cout << "Player 1 score is " << PL1SCORE << endl;
  cout << "Player 2 score is " << PL2SCORE << endl;
}

int playerWin(string pl1Input, string pl2Choice) {
  if (DEBUG3) {cout << "Who wins?" << endl;}

  if (pl1Input == pl2Choice) {
    return 0; // return 0 for draw
  }

  if (pl1Input == "rock" && pl2Choice == "scissors") {
    return 1;
  }
  else if (pl1Input == "paper" && pl2Choice == "rock") {
    return 1;
  }
  else if (pl1Input == "scissors" && pl2Choice == "paper") {
    return 1;
  }
  else {
    return 2; // player 2 works
  }
  return 0;
}

string randomChoice() {
  srand ( time(NULL) ); //initialize the random seed
  int len = sizeof(CHOICES)/sizeof(CHOICES[0]);
  int randNum = rand() % len; // len of string
  string choice = CHOICES[randNum];
  return choice;
}

void incrementWinner(int winNum) {
  if (winNum == 1) {
    PL1SCORE += 1;
  }
  else if (winNum == 2) {
    PL2SCORE += 1;
  }
  return;
}

void game() {
  greet();

  cout << "Is it rock, paper, or scissors?" << endl;
  string input;
  string choice;

  while (input != "rock" && input != "paper" && input != "scissors") {
    cin >> input;
    if (DEBUG2) {cout << "input is " << input << endl;}
    if (input == "rock" || input == "paper" || input == "scissors") {
      if (DEBUG) {cout << "It really was a rock, paper, scissors" << endl;}

      // Random method
      string choice = randomChoice();
      if (DEBUG2) {cout << "choice is " << choice << endl;}
      int winNum = playerWin(input, choice);
      incrementWinner(winNum);
      cout << "input is " << input << " over " << choice << endl;
      if (DEBUG4) {cout << "winner is " << winNum << endl;}
      printScore();
      break;
    }
    cout << "Enter again! rock, paper, or scissors" << endl;
  }
}

int main() {
  string userInput;
  while (userInput != "Quit") {
    game();
    cout << "Quit?, or play again. To Quit, type 'Quit'. Type anything to play again" << endl;
    cin >> userInput;
  }
  return 0;
}
