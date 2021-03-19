#include <iostream>
#include <vector>

using namespace std;

struct unknown_operation_exception
{
   char op;
};

double performOperation(double left, double right, char op)
{
   double result;
   switch (op)
   {
   case '+':
      result = left + right;
      break;
   case '-':
      result = left - right;
      break;
   case '*':
      result = left * right;
      break;
   case '/':
      result = left / right;
      break;
   default:
      throw unknown_operation_exception{op};
   }
   return result;
}
/*
int main()
{
   //input: 3+5 //no white space
   //output: 8
   double left, right;
   char op;
   cin >> left >> op;
   double result = left;
   try
   {
      while(op!='=') {
         cin >> right;
         result = performOperation(result, right, op);
         cin >> op;
      }
      cout << "Il risultato e' " << result << endl;
   }
   catch (unknown_operation_exception e)
   {
      cout << "Operatore " << op << " sconosciuto nell'espressione " << endl;
   }
   return 0;
}*/

struct Token {
  bool isNumber;
  double value;
};

vector<Token> tok = vector<Token>(0);

void read_input() {
  double number = 0;
  char op = 0;
  cin >> number >> op; 
  while(op!='=') {
    tok.push_back(Token{true, number});
    tok.push_back(Token{false, (double) op});
    cin >> number >> op; 
  }
  tok.push_back(Token{true, number});
}

int main() {
   read_input();
   double result = tok.at(0).value;
   for(int i = 1; i < tok.size()-1; i+=2) {
      if(tok.at(i).value == '+') {
         result = result + tok.at(i+1).value;
      }
      if(tok.at(i).value == '*') {
         result = result * tok.at(i+1).value;
      }
   }
   cout << result;
   return 0;

}
