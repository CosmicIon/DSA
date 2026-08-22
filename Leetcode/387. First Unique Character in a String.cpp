// 387. First Unique Character in a String

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

// Example 1:

// Input: s = "leetcode"

// Output: 0

// Explanation:

// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:

// Input: s = "loveleetcode"

// Output: 2

// Example 3:

// Input: s = "aabb"

// Output: -1



//using queue
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        queue<int> q;
        for(int i = 0; i<s.length(); i++) {
            freq[s[i]]++;
            if(freq[s[i]] <= 1) {
                q.push(i);
            } else {
                while(!q.empty() && freq[s[q.front()]] > 1) {
                    q.pop();
                }
            }
        }
        if(q.empty()) return -1;
        else return q.front();
    }
};




//using frequency table (100% beats)
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        for(char x : s) {
            freq[x - 'a']++;
        }

        for(int i = 0; i<s.length(); i++) {
            if(freq[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};