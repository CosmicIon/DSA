// Question link -> https://www.naukri.com/code360/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

// Insert An Element At Its Bottom In A Given Stack
// Easy
// 40/40
// Average time to solve is 15m
// 167 upvotes
// Asked in company
// Problem statement
// You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

// Note :
// If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.
// For Example :
// Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].



#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& myStack, int x) {
    //base case.
    if(myStack.empty()) {
        myStack.push(x);
        return myStack;
    }

    int num = myStack.top();
    myStack.pop();

    //recursion call
    myStack = pushAtBottom(myStack, x);

    myStack.push(num);
    return myStack;
}
