// Question link -> https://www.naukri.com/code360/problems/reverse-stack-using-recursion_631875

// Reverse Stack Using Recursion
// Easy
// 40/40
// Average time to solve is 21m
// Contributed by
// 400 upvotes
// Asked in companies
// Problem statement
// Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.

// Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.



void insertAtBottom(stack<int> &stack, int top) {
    if(stack.empty()) {
        stack.push(top);
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    insertAtBottom(stack, top);

    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    //base case
    if(stack.empty()) {
        return;
    }

    int top = stack.top();
    stack.pop();

    //recursive call
    reverseStack(stack);

    insertAtBottom(stack, top);
}