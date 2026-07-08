// Question link -> https://www.naukri.com/code360/problems/deque_1170059

// Problem statement
// Design a data structure to implement deque of size ‘N’. It should support the following operations:

// pushFront(X): Inserts an element X in the front of the deque. Returns true if the element is inserted, otherwise false.

// pushRear(X): Inserts an element X in the back of the deque. Returns true if the element is inserted, otherwise false.

// popFront(): Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.

// popRear(): Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.

// getFront(): Returns the first element of the deque. If the deque is empty, it returns -1.

// getRear(): Returns the last element of the deque. If the deque is empty, it returns -1.

// isEmpty(): Returns true if the deque is empty, otherwise false.

// isFull(): Returns true if the deque is full, otherwise false.
// Following types of queries denote these operations:

// Type 1: for pushFront(X) operation.
// Type 2: for pushRear(X) operation.
// Type 3: for popFront() operation.
// Type 4: for popRear() operation.
// Type 5: for getFront() operation.
// Type 6: for getRear() operation.
// Type 7: for isEmpty() operation.
// Type 8: for isFull() operation.


#include <bits/stdc++.h> 
class Deque
{
public:
    // Initialize your data structure.
    int *arr;
    int f;
    int size;
    int r;
    int count;

    Deque(int n)
    {
        size = n;
        arr = new int[n];
        f = 0;
        r = 0;
        count = 0;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(count == size) return false;
        f = (f - 1 + size) % size;
        arr[f] = x;
        count++;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(count == size) return false;
        arr[r] = x;
        r = (r + 1) % size;
        count++;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(count == 0) return -1;
        int temp = arr[f];
        f = (f + 1) % size;
        count--;
        return temp;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(count == 0) return -1;
        r = (r - 1 + size) % size;
        int temp = arr[r];
        count--;
        return temp;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(count == 0) return -1;
        return arr[f];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(count == 0) return -1;
        return arr[(r - 1 + size) % size];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        return (count == 0);
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        return (count == size);
    }
};