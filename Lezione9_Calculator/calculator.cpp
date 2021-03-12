#include <iostream>

using namespace std;



int stringToIntFromLeft(string s) {
    int result = 0;
   for(int i = 0; i < s.length(); i++) {
      int digit = s.at(i)-'0';
      result = result*10 + digit;  
   }
   return result;
}

int stringToIntFromRight(string s) {
   int j = 1;
   int result = 0;
   for(int i = s.length()-1; i >= 0 ; i--) {
      int digit = s.at(i)-'0';
      result += digit*j;
      j = j * 10;
   }
   return result;
}

int perforOperation(int left, int right, char op) {
    if(op=='+')
      return left+right;

}

int main()
{
   //input: 3+5 //no white space
   //output: 8
   string input;
   cin >> input;

   int i = 0;
   while(input.at(i) >= '0' && input.at(i) <= '9')
      i++;
   string leftNumber = input.substr(0, i);

   char op = input.at(i);

   string rightNumber = input.substr(i+1, input.length()-i-1);

   int leftNumberInt = stringToIntFromLeft(leftNumber);
   int rightNumberInt = stringToIntFromRight(rightNumber);

   int result = perforOperation(leftNumberInt, rightNumberInt, op);

   cout << "L'input e' " << input << endl;
   cout << "Il risultato e' " << result << endl;
   return 0;
}