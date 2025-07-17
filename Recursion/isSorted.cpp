#include <iostream>
using namespace std;

bool isSorted(int arr[], int size) {
    if(size < 2) return true;
    if(arr[0] > arr[1]) return false;
    else isSorted(arr+1, size-1);
}

int main() {
    int arr[25] = {5, 3, 7, 7, 8, 7, 8, 9, 0, 5, 6, 7, 2, 1, 3, 7, 7, 8, 8, 8, 9, 0, 1, 2, 1};
    cout << isSorted(arr, 25) << endl;

    int arr1[5] = {5, 6, 7, 9, 10};
    cout << isSorted(arr1, 5) << endl;

    return 0;
}