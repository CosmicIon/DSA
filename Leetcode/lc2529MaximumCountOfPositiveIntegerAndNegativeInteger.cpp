// Leetcode 2529. Maximum Count of Positive Integer and Negative Integer

// Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

// In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
// Note that 0 is neither positive nor negative.




// linear search.
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int p = 0, n = 0;
            for (int i = 0; i<nums.size(); i++) {
                if (nums[i] > 0) {
                    p++;
                } else if (nums[i] < 0) {
                    n++;
                }
            }
            return max(p, n);
        }
    };





//binary search
class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int s = 0;
            int e = nums.size() - 1;
            int f = -1, l = -1;
    
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (nums[mid] < 0) {
                    f = mid;
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
            
            s = 0;
            e = nums.size() - 1;
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (nums[mid] > 0) {
                    l = mid;
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
    
            e = nums.size();
            if (f == -1 && l == -1) return 0;
            else if (f == -1) return e - l;
            else if (l == -1) return f + 1;
            else return max(f + 1, e - l);
        }
    };