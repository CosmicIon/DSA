#include <iostream>
#include <cmath>
using namespace std;

int getpower(int a, int b) {
    // base case
    if (b == 0) 
        return 1;
    if (b % 2 == 0) {
        return pow(getpower(a, b/2),2);
    } else {
        return (a * pow(getpower(a, b/2),2));
    }
}

int main() {
    int a = 2, b = 10;
    cout << getpower(a, b) << endl;

    return 1;
}