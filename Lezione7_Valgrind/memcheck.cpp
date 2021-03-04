#include <iostream>

using std::cout;
using std::endl;

int main() {
    int* a = new int[10];
    delete [] a;
    cout << "Hi " << a[5] << endl;
}