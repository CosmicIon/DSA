// Question link -> https://www.naukri.com/code360/problems/redundant-brackets_975473


// Redundant Brackets
// Easy
// 40/40
// Average time to solve is 15m
// 304 upvotes
// Asked in companies
// Problem statement
// Given valid mathematical expressions in the form of a string. You are supposed to return true if the given expression contains a pair of redundant brackets, else return false. The given string only contains ‘(‘, ’)’, ‘+’, ‘-’, ‘*’, ‘/’ and lowercase English letters.

// Note :
// A pair of brackets is said to be redundant when a subexpression is surrounded by needless/ useless brackets.

// For Example :
// ((a+b)) has a pair of redundant brackets. The pair of brackets on the first and last index is needless. 
// While (a + (b*c)) does not have any pair of redundant brackets. 



#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s) {
    int n = s.length();
    stack<char> stack;
    for(int i = 0; i<n; i++) {
        char ch = s[i];
        if(ch == '(' || ch == '-' || ch == '+' || ch == '*' || ch == '/') {
            stack.push(ch);
        } else {
            if(ch == ')') {
                if(stack.top() == '(') return true;
                while(stack.top() != '(') {
                    stack.pop();
                }
                stack.pop();
            }
        }
    }
    return false;
}
