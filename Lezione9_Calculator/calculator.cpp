#include <iostream>

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
}