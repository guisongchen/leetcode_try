/*

Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

*/

// solution 1: dynamic planning
// solution 2: binary search


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // use dynamic planning
        // corner case
        if (nums.empty())
            return 0;
        
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int ret = 1;
        for (int i = 1; i < n; ++i) { // search [0, 1], [0, 2]...[0, i]...[0, n-1]
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) { // if nums[i] change, length may change
                    dp[i] = max(dp[j]+1, dp[i]); 
                }
            }
            
            ret = max(ret, dp[i]);
        }
        
        return ret;
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // use dynamic planning
        // corner case
        // or we can use bianry search
        if (nums.empty())
            return 0;
        
        int n = nums.size();
        // traverse nums, if cur num greater than all elements of backup, push back
        // else, update the first one which less or equal to cur num
        // init backup with nums[0]
        vector<int> backup({nums[0]});
        for (int i = 1; i < n; ++i) {
            int left = 0;
            int right = backup.size();
            while (left < right) {
                int mid = left + (right-left)/2;
                if (backup[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            if (left == backup.size()) { // push
                backup.push_back(nums[i]);
            } else { // update
                backup[left] = nums[i];
            }
        }
        
        return backup.size();    
    }
};
