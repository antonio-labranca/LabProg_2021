#include <iostream>

using std::cout;
using std::endl;

int main() {
    int* a = new int[10];
    cout << a[10] << endl;
    delete [] a;
}