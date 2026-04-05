// Question link -> https://www.naukri.com/code360/problems/minimum-cost-to-make-string-valid_1115770


// Minimum Cost To Make String Valid
// Moderate
// 80/80
// Average time to solve is 20m
// Contributed by
// 264 upvotes
// Asked in companies
// Problem statement
// Ninja has been given a string ‘STR’ containing either ‘{’ or ‘}’. 'STR’ is called valid if all the brackets are balanced. Formally for each opening bracket, there must be a closing bracket right to it.

// For Example:
// “{}{}”, “{{}}”, “{{}{}}” are valid strings while “}{}”, “{}}{{}”, “{{}}}{“ are not valid strings.
// Ninja wants to make ‘STR’ valid by performing some operations on it. In one operation, he can convert ‘{’ into ‘}’ or vice versa, and the cost of one such operation is 1.

// Your task is to help Ninja determine the minimum cost to make ‘STR’ valid.

// For Example:
// Minimum operations to make ‘STR’ =  “{{“ valid is 1.
// In one operation, we can convert ‘{’ at index ‘1’ (0-based indexing) to ‘}’. The ‘STR’ now becomes "{}" which is a valid string.

// Note:
// Return -1 if it is impossible to make ‘STR’ valid.



#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  if(str.length()%2 != 0) return -1;

  int ans = 0;
  int n = str.length();
  stack<char> stack;
  for(int i = 0; i<n; i++) {
    char ch = str[i];
    if(ch == '{') {
      stack.push(ch);
    } else {
      if(stack.empty()) {
        stack.push('{');
        ans++;
        continue;
      }
      stack.pop();
    }
  }
  ans += stack.size()/2;
  return ans;
}