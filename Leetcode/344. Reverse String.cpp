// 344. Reverse String

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.



//code using stack
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> stack;
        for(int i = 0; i<s.size(); i++) {
            stack.push(s[i]);
        }
        for(int i = 0; i<s.size(); i++) {
            s[i] = stack.top();
            stack.pop();
        }
    }
};



//optimal solution using two pointer.
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0, j = s.size()-1;
        while(i<j)
            swap(s[i++], s[j--]);
    }
};