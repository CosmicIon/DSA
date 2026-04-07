// 84. Largest Rectangle in Histogram

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 
// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.



class Solution {
private:
    void prevSmallest(vector<int>& arr, vector<int>& prev) {
        int n = arr.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if(s.empty()) prev[i] = -1;
            else prev[i] = s.top();
            s.push(i);
        }
    }

    void nextSmallest(vector<int>& arr, vector<int>& next) {
        int n = arr.size();
        stack<int> s;
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if(s.empty()) next[i] = n;
            else next[i] = s.top();
            s.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        
        vector<int> prev(n), next(n);
        prevSmallest(heights, prev);
        nextSmallest(heights, next);

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int width = next[i] - prev[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};