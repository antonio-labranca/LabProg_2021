#include <iostream>

using namespace std;

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

   int leftNumberInt = 0;
   int rightNumberInt = 0;

   for(int i = 0; i < leftNumber.length(); i++) {
      int digit = leftNumber.at(i)-'0';
      leftNumberInt = leftNumberInt*10 + digit;  
   }


   int j = 1;
   for(int i = rightNumber.length()-1; i >= 0 ; i--) {
      int digit = rightNumber.at(i)-'0';
      rightNumberInt += digit*j;
      j = j * 10;
   }

   int result;

   if(op=='+')
      result = leftNumberInt+rightNumberInt;

   cout << "L'input e' " << input << endl;
   return 0;
}