// Question link -> https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908

// Problem statement
// Implement a Queue Data Structure specifically to store integer data using a Singly Linked List or an array.

// You need to implement the following public functions :

// 1. Constructor: It initializes the data members as required.

// 2. enqueue(data): This function should take one argument of type integer. It enqueues the element into the queue.

// 3. dequeue(): It dequeues/removes the element from the front of the queue and in turn, returns the element being dequeued or removed. In case the queue is empty, it returns -1.

// 4. front(): It returns the element being kept at the front of the queue. In case the queue is empty, it returns -1.

// 5. isEmpty(): It returns a boolean value indicating whether the queue is empty or not.
// Operations Performed on the Queue :
// Query-1(Denoted by an integer 1): Enqueues integer data to the queue.

// Query-2(Denoted by an integer 2): Dequeues the data kept at the front of the queue and returns it to the caller, return -1 if no element is present in the queue.

// Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the front of the queue but doesn't remove it, unlike the dequeue function, return -1 if no element is present in the queue.

// Query-4(Denoted by an integer 4): Returns a boolean value denoting whether the queue is empty or not.

#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int size;
    int f; //front
    int r; //rear

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        f = 0;
        r = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(f == r) return true;
        else return false;
    }

    void enqueue(int data) {
        arr[r] = data;
        r++;
    }

    int dequeue() {
        if(f == r) return -1;
        else {
            int temp = arr[f];
            f++;
            return temp;
        }
    }

    int front() {
        if(f == r) return -1;
        else {
            return arr[f];
        }
    }
};