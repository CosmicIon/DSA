// Question link -> https://www.naukri.com/code360/problems/circular-queue_1170058

// Problem statement
// You will be given ‘Q’ queries. You need to implement a circular queue according to those queries. Each query will belong to one of these two types:

// 1 ‘X’: Enqueue element ‘X’ into the end of the nth queue. Returns true if the element is enqueued, otherwise false.

// 2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.
// Note:
// Enqueue means adding an element to the end of the queue, while Dequeue means removing the element from the front of the queue.


#include <bits/stdc++.h> 
class CircularQueue{
    public:
    // Initialize your data structure.
        int *arr;
        int size;
        int f;
        int r;
        int count;

    CircularQueue(int n){
        size = n;
        arr = new int[size];
        f = 0;
        r = 0;
        count = 0;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if (count == size) return false;
        arr[r] = value;
        r = (r + 1) % size;
        count++;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(count == 0) return -1;
        int temp = arr[f];
        f = (f + 1) % size;
        count--;
        return temp;
    }
};