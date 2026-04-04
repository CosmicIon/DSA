// Question link -> https://www.naukri.com/code360/problems/delete-middle-element-from-stack_985246


// Delete middle element from stack
// Easy
// 40/40
// Average time to solve is 15m
// Contributed by
// 237 upvotes
// Asked in companies
// Problem statement
// You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.

// A stack is a linear data structure where both insertion and deletion of elements take place at the top. It follows FILO (First In Last Out) or LIFO (Last In First Out) approaches. Books piled on top of each other is an example of a stack, where you can only remove a single book at a time, which is at the top of the stack. Likewise, you can only add a single book at a time, on the top of the stack only.

// Example :-
// INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
// OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ]

// The above example contains an odd number of elements, hence the middle element is clearly the (N+1) / 2th element, which is removed from the stack in the output.

// INPUT : ARR [ ] = [ 5, 6, 7, 8 ] , N = 3
// OUTPUT: ARR [ ] = [ 5, 7, 8 ]

// The above example contains an even number of elements, so out of the two middle elements, we consider the one which occurs first. Hence, the middle element would be ((N+1) / 2 - 1) element, which is 6 and is removed from the stack in the output.



//using another stack.
#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int N){
   stack<int> temp;
   for(int i = 0; i < N/2; i++) {
      temp.push(inputStack.top());
      inputStack.pop();
   }
   inputStack.pop();
   while(!temp.empty()) {
      inputStack.push(temp.top());
      temp.pop();
   }
}



//using recursion .. it is a better approach. idk why .. but it is what it is.
#include <bits/stdc++.h> 
void solve(stack<int> &inputStack, int N, int count) {

   //base case
   if(count == N/2) {
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();

   //recursive call
   solve(inputStack, N, count+1);

   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
   solve(inputStack, N, 0);
}