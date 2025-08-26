#include<iostream>
using namespace std;

void merge(int *arr, int s, int mid, int e){
    int l1 = mid + 1 - s;
    int l2 = e - mid;

    int a1[l1], a2[l2]; //making temporary array to store the merging array.

    for(int i = 0; i<l1; i++) {
        a1[i] = arr[s+i];
    }
    for(int i = 0; i<l2; i++) {
        a2[i] = arr[mid+1+i];
    }

    //merge of 2 sorted array.
    int i = 0, j = 0, k = s;
    while(i<l1 && j<l2) {
        if(a1[i] < a2[j]) {
            arr[k++] = a1[i++];
        } else {
            arr[k++] = a2[j++];
        }
    }
    while(i<l1) {
        arr[k++] = a1[i++];
    }
    while(j<l2) {
        arr[k++] = a2[j++];
    }
}

void mergeSort(int *arr, int s, int e) {
    if(s>=e) return;

    int mid = s + (e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, mid, e);
}

int main() {
    int arr[] = {2, 3, 7, 1, 3, 6};
    int size = 6;
    mergeSort(arr, 0, size-1);

    for(int i = 0; i<size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}