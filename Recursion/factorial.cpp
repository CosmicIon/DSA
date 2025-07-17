#include <iostream>
using namespace std;

int factorial(int n) {
    if(n < 2) return 1;
    return n * factorial(n-1);
}

int main() {
    cout << factorial(2) << endl << factorial(3) << endl << factorial(4) << endl << factorial(5);

    return 0;
}