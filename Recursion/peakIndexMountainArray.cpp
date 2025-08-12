#include <iostream>
using namespace std;

int peakIndex(int arr[], int start, int end) {
    if(start >= end) return start;
    else {
        int mid = start + (end - start) / 2;
        if(arr[mid] < arr[mid+1]) 
            return peakIndex(arr, mid+1, end);
        else
            return peakIndex(arr, start, mid);
    }
}

int main() {
    int arr[6] = {0, 5, 10, 25, 29, 2}; //output 4
    cout << peakIndex(arr, 0, 5) << endl;

    int arr1[5] = {5, 6, 17, 9, 3}; //output 2
    cout << peakIndex(arr1, 0, 4) << endl;

    return 0;
}