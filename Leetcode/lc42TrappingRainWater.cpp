// Leetcode 42. Trapping Rain Water

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


class Solution {
    public:
    
        int addWater(vector<int>& arr, int left, int right) {
            int water = 0;
            int small = (arr[left] > arr[right]) ? arr[right] : arr[left];
            water = small * (right - left - 1);
            for (int i = left + 1; i < right; i++) {
                water -= arr[i];
            }
            return water;
        }
    
        int trap(vector<int>& height) {
            if (height.empty()) return 0;
    
            // first we need to find the max element
            int max = 0; // max is the index of the largest element.
            int water = 0;
            for (int i = 1; i < height.size(); i++) {
                if (height[i] > height[max])
                    max = i;
            }
    
            // Traverse from 0 to max element
            int i = 0;
            while (i < max) {
                int j = i + 1;
                while (height[i] > height[j] && j < height.size()) {
                    j++;
                }
                water += addWater(height, i, j);
                i = j;
            }
    
            // Traverse from last to max element
            i = height.size() - 1;
            while (i > max) {
                int j = i - 1;
                while (height[i] > height[j] && j >= 0) {
                    j--;
                }
                water += addWater(height, j, i);
                i = j;
            }
            return water;
        }
    };




//Optimized code
class Solution {
    public:
        int trap(vector<int>& height) {
            if (height.empty()) return 0;
    
            int left = 0, right = height.size() - 1;
            int leftMax = 0, rightMax = 0;
            int water = 0;
    
            while (left < right) {
                if (height[left] < height[right]) {
                    if (height[left] >= leftMax) {
                        leftMax = height[left];
                    } else {
                        water += leftMax - height[left];
                    }
                    left++;
                } else {
                    if (height[right] >= rightMax) {
                        rightMax = height[right];
                    } else {
                        water += rightMax - height[right];
                    }
                    right--;
                }
            }
            return water;
        }
    };