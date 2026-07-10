// Question link -> https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1


//First Negative in Windows of Size K
// Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

// Note: If a window does not contain a negative integer, then return 0 for that window.


class Solution {
	public:
	vector<int> firstNegInt(vector<int>& arr, int k) {
		vector<int> ans;
		deque<int> dq;
		int n = arr.size();
		
		//processing first window
		for (int i = 0; i<k; i++) {
			if (arr[i] < 0)
				dq.push_back(i); //pushing the index of only negative value
		}
		
		//pushing the answer from the first window
		if (dq.empty())
			ans.push_back(0);
		else
			ans.push_back(arr[dq.front()]);
		
		//traversal for remaining elements
		for (int i = k; i<n; i++) {
		    //removal of the first occuring negative value
			if (!dq.empty() && (i - dq.front()) >= k)
				dq.pop_front();
				
			//pushing the index of negaive value
			if (arr[i] < 0) {
				dq.push_back(i);
			}
			
			//pushing into ans the front of deque.
			if (dq.empty())
				ans.push_back(0);
			else
				ans.push_back(arr[dq.front()]);
		}
		return ans;
	}
};
