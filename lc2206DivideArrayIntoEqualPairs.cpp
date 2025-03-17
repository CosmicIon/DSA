// Leetcode 2206. Divide Array Into Equal Pairs

// You are given an integer array nums consisting of 2 * n integers.
// You need to divide nums into n pairs such that:
// Each element belongs to exactly one pair.
// The elements present in a pair are equal.
// Return true if nums can be divided into n pairs, otherwise return false.

 
class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            int freq[501] = {0};
            for (int num : nums) {
                freq[num]++;
            }
            for (int i = 1; i <= 500; i++) {
                if (freq[i] % 2 != 0) {
                    return false;
                }
            }
            return true;
        }
    };