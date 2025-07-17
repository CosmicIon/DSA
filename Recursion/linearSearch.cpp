#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key) {
    if(size == 0) return false;
    if(arr[0] == key) return true;
    linearSearch(arr+1, size-1, key);
}

int main() {
    int arr[25] = {5, 3, 7, 7, 8, 7, 8, 9, 0, 5, 6, 7, 2, 1, 3, 7, 7, 8, 8, 8, 9, 0, 1, 2, 1};
    cout << linearSearch(arr, 25, 0) << endl;

    int arr1[5] = {5, 6, 7, 9, 10};
    cout << linearSearch(arr1, 5, 1) << endl;

    return 0;
}