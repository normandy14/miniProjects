#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

string RESPONSES[] = {
    "If its in the stars",
    "Its defintely a maybe",
    "Probably, but not for sure",
    "Not quite, but close",
    "If, its good for you, it shall pass",
    "Its up to the stars",
    "Its not exactly in your favor",
    "Its uncertain",
    "Its defintely a maybe",
    "Take a walk on it",
};

string getQuestion() {
  string question;
  cout << "What is your question" << endl;
  getline(cin, question);
  return question;
}

void randomResponse() {
  int len = sizeof(RESPONSES)/sizeof(RESPONSES[0]);

  srand ( time (NULL) ); //initialize the random seed
  int randNum = rand() % len; // len of string
  cout << RESPONSES[randNum] << endl;
}

void askQuestion(string question) {
  if (question == "") {
    question = getQuestion();
    cout << "The question is " << question << endl;
    cout << "Thinking ..." << endl;
    randomResponse();
  }
  else {
    cout << "The question is " << question << endl;
    cout << "Thinking ..." << endl;
    randomResponse();
    // cout << "Not an empty Question!" << endl;
  }
}

int main() {
  cout << "Hello, I am a magic-8 ball" << endl;
  string question = "";

  askQuestion(question);
  // Output
  string input;

  while (input != "Quit") {
    cout << "Ask another question, or leave by typing Quit" << endl;
    // cin >> input;
    getline(cin, input);
    if (input == "Quit") {
      cout << "Good-bye" << endl;
      return 0;
    }
    else {
      askQuestion(input);
    }
  }

  return 0;
}
