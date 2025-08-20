// Leetcode 912. Sort an Array

// Given an array of integers nums, sort the array in ascending order and return it.
// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 class Solution {
public:

    void merge(vector<int>& arr, int s, int mid, int e) {
        int l1 = mid - s + 1;
        int l2 = e - mid;

        vector<int> temp1(l1), temp2(l2); //making temproray array to store arr

        for(int i = 0; i<l1; i++) {
            temp1[i] = arr[s+i];      //making copy of original array to temp1 array
        }

        for(int i = 0; i<l2; i++) {
            temp2[i] = arr[mid+1+i];    //making copy of original array to temp2 array
        }

        int i = 0, j = 0, k = s;


        //concept of merge 2 sorted array. 
        while(i<l1 && j<l2) {
            if(temp1[i]<temp2[j]){
                arr[k++] = temp1[i++];
            } else {
                arr[k++] = temp2[j++];
            }
        }

        while(i<l1) {
            arr[k++] = temp1[i++];
        }
        while(j<l2) {
            arr[k++] = temp2[j++];
        }
    }

    void mergeSort(vector<int>& arr, int s, int e) {
        if(s>=e) return;

        int mid = s + (e-s)/2;

        mergeSort(arr, s, mid); //recursive call for left part.
        mergeSort(arr, mid+1, e); //recursive call for right part.

        merge(arr, s, mid, e); //now finally merge the whole array back to sorted
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};