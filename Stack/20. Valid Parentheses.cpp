// 20. Valid Parentheses

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.



class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> stack;

        for(int i = 0; i<n; i++) {
            char ch = s[i];

            if(ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                if(stack.empty()) return false;     //if stack is empty then we can't check its top.. it will return segmentation fault. .. so we need to early check it and return false;

                if(ch == ')' && stack.top() == '(' || 
                   ch == ']' && stack.top() == '[' || 
                   ch == '}' && stack.top() == '{') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();       //if at the end stack is empty then we return true.
    }
};