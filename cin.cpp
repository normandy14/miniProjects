#include <iostream>
using namespace std;


int main() {
  cout << "Hello World" << endl;
  string input;
  int num  = 5;
  while (num > 0) {
    getline(cin, input);
    cout << input << endl;
    num--;
  }

  return 0;
}
