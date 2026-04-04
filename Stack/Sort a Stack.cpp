// Question link -> https://www.naukri.com/code360/problems/sort-a-stack_985275


// Sort a Stack
// Easy
// 40/40
// Average time to solve is 10m
// Contributed by
// 513 upvotes
// Asked in companies
// Problem statement
// You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

// We can only use the following functions on this stack S.

// is_empty(S) : Tests whether stack is empty or not.
// push(S) : Adds a new element to the stack.
// pop(S) : Removes top element from the stack.
// top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
// Note :
// 1) Use of any loop constructs like while, for..etc is not allowed. 
// 2) The stack may contain duplicate integers.
// 3) The stack may contain any integer i.e it may either be negative, positive or zero.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= 'T' <= 100
// 1 <=  'N' <= 100
// 1 <= |'V'| <= 10^9

// Where |V| denotes the absolute value of any stack element.

// Time limit: 1 sec



#include <bits/stdc++.h> 

void sortInsert(stack<int>& stack, int x) {
	if(stack.empty()) {
		stack.push(x);
		return;
	}
	if(x > stack.top()) {
		stack.push(x);
		return;
	}
	
	int num = stack.top();
	stack.pop();

	sortInsert(stack, x);

	stack.push(num);
}

void sortStack(stack<int> &stack) {
	if(stack.empty()) {
		return;
	}

	int num = stack.top();
	stack.pop();

	//recursive call
	sortStack(stack);

	sortInsert(stack, num);
}