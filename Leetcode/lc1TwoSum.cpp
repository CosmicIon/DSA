// Leetcode 1. Two Sum 

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.


class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> umap;
            vector<int> result;
            int diff, i;
            for(i=0; i<nums.size();i++) {
                diff = target - nums[i];
                if(umap.count(diff)) {
                    result.push_back(i);
                    result.push_back(umap.find(diff)->second);
                }
                umap[nums[i]]=i;
            }
            return result;
        }
    };