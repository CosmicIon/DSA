// Leetcode 567. Permutation in String

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.
// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

class Solution {
    private:
        bool checkEqual(int a[26], int b[26]) {
            for(int i = 0; i<26; i++) {
                if(a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        }
    public:
        bool checkInclusion(string s1, string s2) {
            int count1[26] = {0};
    
            for(int i = 0; i<s1.length(); i++) {
                int index = s1[i] - 'a';
                count1[index]++;
            }
    
            int i = 0;
            int window = s1.length();
            int count2[26] = {0};
    
            while(i<window && i<s2.length()) {
                int index = s2[i] - 'a';
                count2[index]++;
                i++;
            }
    
            if(checkEqual(count1, count2)) {
                return true;
            }
    
            while(i<s2.length()) {
                char newChar = s2[i];
                int index = newChar - 'a';
                count2[index]++;
    
                char oldChar = s2[i-window];
                index = oldChar - 'a';
                count2[index]--;
    
                i++;
    
                if(checkEqual(count1, count2)) {
                    return true;
                }
            }
            return false;
        }
    };