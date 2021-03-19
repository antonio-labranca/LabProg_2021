#include <iostream>

using namespace std;

struct wrongBPS_exception {};

int S();
int T();

//S -> Ɛ | TS
int S() {
    char character;
    cin >> character;
    cin.putback(character);
    if(character != '(')
        return 0;
    else {
        int height_subtree = T();
        return height_subtree;
    }
}

//T -> (S)
int T() {
  char character;
  cin >> character;
  if(character != '(')
     throw wrongBPS_exception{};
  int height_subtree = S();
  cin >> character;
  if(character != ')') 
     throw wrongBPS_exception{};
  return height_subtree+1;
}

int main() {
  cout << "Please type a BPS:" << endl;
  int result = T()-1;
  cout << "The height of the given BPS is " << result <<endl;
  return 0;
}