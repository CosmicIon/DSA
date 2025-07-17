#include <iostream>
using namespace std;

int recursionSum(int arr[], int size) {
    if(size == 0) return 0;
    return arr[0] + recursionSum(arr+1, size-1);
}

int main() {
    int arr[25] = {5, 3, 7, 7, 8, 7, 8, 9, 0, 5, 6, 7, 2, 1, 3, 7, 7, 8, 8, 8, 9, 0, 1, 2, 1};

    cout << recursionSum(arr, 25) << endl;

    return 0;
}