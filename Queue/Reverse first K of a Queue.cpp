// Question link -> https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

// Reverse first K of a Queue
// Difficulty: EasyAccuracy: 81.28%Submissions: 192K+Points: 2
// Given an integer k and a queue of integers, we need to reverse the order of the first k elements of the queue, leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

// "If the size of queue is smaller than the given k , then return the original queue."



class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        stack<int> s;
        int n = q.size();
        
        if(k>n) return q; //size of queue is smaller than k.
        
        //store the k element on the stack.
        for(int i = 0; i<k; i++) {
            s.push(q.front());
            q.pop();
        }
        
        //push the stack back to queue.
        for(int i = 0; i<k; i++) {
            q.push(s.top());
            s.pop();
        }
        //-> output till here will be [4, 5, 3, 2, 1] but i want [4, 5] in the back
        
        //push (n-k) elements back of the queue.
        for(int i = 0; i<n-k; i++) {
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};