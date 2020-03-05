/*

Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 

*/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // first, O(n) be greedy
        int left = 0, right = 0, len = INT_MAX, sum = 0;
        int n = nums.size();
        
        // given left, check the min length when sum >= s
        for (right = 0; right < n; ++right) {
            while (right < n && sum < s) {
                sum += nums[right];
                ++right;
            }
            
            // retrive to get valid right idx
            --right;
            
            // now sum >= s, fix right idx, shift left idx to get min len
            while (sum >= s) {
                len = min(len, right-left+1);
                sum -= nums[left];
                ++left; // move left
            }
        }
        
        return len == INT_MAX ? 0 : len;
    }
};
