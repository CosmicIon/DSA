// Question link -> https://www.geeksforgeeks.org/problems/queue-reversal/1

// Given a queue q containing integer elements, your task is to reverse the queue.

// Examples:

// Input: q[] = [5, 10, 15, 20, 25]
// Output: [25, 20, 15, 10, 5]
// Explanation: After reversing the given elements of the queue, the resultant queue will be 25 20 15 10 5.
// Input: q[] = [1, 2, 3, 4, 5]
// Output: [5, 4, 3, 2, 1]
// Explanation: After reversing the given elements of the queue, the resultant queue will be 5 4 3 2 1.
// Constraints:
// 1 ≤ q.size() ≤ 103
// 0 ≤ q[i] ≤ 105


//Approach 1 (using Stack)
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        int n = q.size();
        stack<int> s;
        for(int i = 0; i<n; i++) {
            int temp = q.front();
            s.push(temp);
            q.pop();
        }
        for(int i = 0; i<n; i++) {
            int temp = s.top();
            q.push(temp);
            s.pop();
        }
    }
};


//Approach 2: (using stack without temp variable)
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        int n = q.size();
        stack<int> s;
        for(int i = 0; i<n; i++) {
            s.push(q.front());
            q.pop();
        }
        for(int i = 0; i<n; i++) {
            q.push(s.top());
            s.pop();
        }
    }
};


//Approach 3 :(recursion)
class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        //base case
        if(q.empty()) return;
        
        int front = q.front();
        q.pop();
        
        reverseQueue(q);
        q.push(front);
    }
};