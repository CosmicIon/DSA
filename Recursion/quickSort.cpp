#include<iostream>
using namespace std;

int partition(int *arr, int s, int e) {
    int pivot = arr[s]; //take starting index as pivot
    int count = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <= pivot)
            count++; //count the element in array smaller than pivot.
    }
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while(i < (pivotIndex) && j > (pivotIndex)) {
        while(arr[i] < pivot) 
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < (pivotIndex) && j > (pivotIndex))
            swap(arr[i++], arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e) {
    if(s>=e) return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1); //sort left part
    quickSort(arr, p+1, e); //sort right part
}

int main() {
    int arr[] = {4,6,2,6,9,1};
    int size = 6;

    quickSort(arr, 0, size-1);

    for(int i = 0; i<size; i++)
        cout << arr[i] << " ";
    return 0;
}