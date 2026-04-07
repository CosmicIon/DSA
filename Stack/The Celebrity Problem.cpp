// Question link -> https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

// The Celebrity Problem
// Difficulty: MediumAccuracy: 38.33%Submissions: 374K+Points: 4Average Time: 30m

// A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Note: Follow 0-based indexing.



//Brute force -> o(n^2)
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            bool isCelebrity = true;
            
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (mat[i][j] == 1 || mat[j][i] == 0) {
                    isCelebrity = false;
                    break;
                }
            }

            if (isCelebrity) return i;
        }

        return -1;
    }
};


//optimized -> o(n) without using stack.
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0;
        int down = n - 1;

        // Step 1: Find the potential candidate
        while (top < down) {
            if (mat[top][down] == 1) {
                top++; // top knows down, so top is not a celebrity
            } else {
                down--; // top doesn't know down, so down is not a celebrity
            }
        }

        int candidate = top;

        // Step 2: Verify the candidate
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;

            // Celebrity should not know anyone (row must be 0)
            // Everyone should know the celebrity (column must be 1)
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }

        return candidate;
    }
};


//optimal. using Stack -> O(n) 
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> s;

        for(int i = 0; i < n; i++) {
            s.push(i);
        }

        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if(mat[a][b] == 1) {
                // a knows b, so a cannot be the celebrity
                s.push(b);
            } else {
                // a doesn't know b, so b cannot be the celebrity
                s.push(a);
            }
        }

        //Verification
        int candidate = s.top();
        
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;

            // Row check: Candidate must not know i
            // Column check: i must know candidate
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }

        return candidate;
    }
};