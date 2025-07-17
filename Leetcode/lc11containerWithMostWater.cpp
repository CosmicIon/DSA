// Leetcode 11. <Container With Most Water.>

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int i=0, j=height.size()-1, max = 0, m;
            while (i<j) {
                if (height[i]>height[j]) {
                    m = height[j]*(j-i);
                    j--;
                }
                else if(height[i]<height[j]) {
                    m = height[i]*(j-i);
                    i++;
                }
                else {
                    m = height[i]*(j-i);
                    i++;
                }
                if(m>max)
                    max = m;       
            }
            return max;
        }
    };