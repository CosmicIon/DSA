#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n) {
    //base case
    if(n == 0 || n == 1) return;
    
    for(int i = 0; i<n; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }
    
    bubbleSort(arr, n-1);
}

int main() {
    int arr[5] = {1,5,2,6,3};
    bubbleSort(arr, 5);

    for(int i = 0; i<5; i++) {
        cout << arr[i] << " " ; //output:-> 1 2 3 5 6
    }

    return 0;
}