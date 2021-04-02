#include <iostream>
#include <vector>

using namespace std;

struct Token {
  bool isNumber;
  double value;
};

vector<Token> tok = vector<Token>(0);

void read_input() {
  double number = 0;
  char op;
  cin >> op;
  while(op!='=') {
     if(op >= '0' && op <= '9') {
         cin.putback(op);
         cin >> number;
         tok.push_back(Token{true, number});
     }
     else
         tok.push_back(Token{false, (double) op});
     cin >> op;
  }
}

double expression();
double term();
double primary();
double number();


Token get_token() {
   Token result = tok.at(0);
   tok.erase(tok.begin());
   return result;
}

void put_back(Token token) {
   tok.insert(tok.begin(), token);
}

struct syntax_error {};

double expression() {
   //Term
   //Expression '+' Term
   //Expression '-' Term
   double left = term();
   if(tok.empty())
      return left;
   Token op = get_token();
   if(op.isNumber)
      throw syntax_error{};
   while(true) {
      switch((char) op.value) {
         case '+':
            left += term();
            if(tok.empty())
               return left;
            op = get_token();
            break;
         case '-':
            left -= term();
            if(tok.empty())
               return left;
            op = get_token();
            break;
         default:
            put_back(op);
            return left;
      }
   }
}

double term() {
   //Primary
   //Term '*' Primary
   //Term '/' Primary
   double left = primary();
   if(tok.empty())
      return left;
   Token op = get_token();
   if(op.isNumber)
      throw syntax_error{};
   while(true) {
      switch((char) op.value) {
         case '*':
            left *= term();
            if(tok.empty())
               return left;
            op = get_token();
            break;
         case '/':
            left /= term();
            if(tok.empty())
               return left;
            op = get_token();
            break;
         default:
            put_back(op);
            return left;
      }
   }
}

double primary() {
   //Number
   //'(' Expression ')'
   Token op = get_token();
   double result;
   switch((char) op.value) {
      case '(':
         result = expression();
         op = get_token();
         if(op.isNumber || op.value!=')')
            throw syntax_error{};
         else return result;
         break;
      default:
         put_back(op);
         return number();
   }
}
double number() {
   Token t = get_token();
   if(t.isNumber)
      return t.value;
   else throw syntax_error{};
} 

int main() {
   read_input();
   double result = expression();
   cout << result << endl;
   return 0;
}
