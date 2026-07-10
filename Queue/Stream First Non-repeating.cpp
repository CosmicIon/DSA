// Question link -> https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// Stream First Non-repeating
// Difficulty: MediumAccuracy: 31.65%Submissions: 243K+Points: 4Average Time: 15m
// Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n), find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.


class Solution {
  public:
    string firstNonRepeating(string &s) {
        string ans = "";
        map<char, int> count; // make a map to store the frequency of char
        queue<int> q;
        int n = s.length();
        
        for(int i = 0; i<n; i++) {
            count[s[i]]++; // increasing the count of that char
            
            q.push(s[i]); // pushing char in the queue.
            
            while(!q.empty()) {
                if(count[q.front()] > 1) { // if the front of queue have freq more than 1.
                    q.pop(); // we remove that element from queue.
                }
                else {
                    ans.push_back(q.front()) ; // if count is only one then we push it in ans.
                    break; // after pushing we need to break.
                }
            }
            if(q.empty()) ans.push_back('#'); // if the queue became empty then we push '#'.
        }
        return ans;
    }
};