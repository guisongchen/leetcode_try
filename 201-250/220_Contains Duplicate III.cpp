/*

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

*/

// keypoints:
// 1. use slinding window makes sure j - i <= k
// 2. use set to sort(ascending order) numbers in window
// default set is ascending order, so we look back for [xxx, nums[i]-t) 
// iter points to nums[i]-t or someValue less than nums[i]-t
// which means *iter <= nums[i]-t
// we require: |nums[i]-*iter| <= t
// so needs to check *iter <= nums[i] + t ! <--important



class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // using sliding window and two pointer
        set<long> window;
        
        for (int i = 0, n = nums.size(); i < n; ++i) {
            
            // maintance sliding window
            if (i > k) {
                // if exist, erase the first element in window
                window.erase(static_cast<long>(nums[i-k-1]));
            }
            
            // default set is ascending order, so we look back for [xxx, nums[i]-t) 
            // iter points to nums[i]-t or someValue less than nums[i]-t
            // which means *iter <= nums[i]-t
            // we require: |nums[i]-*iter| <= t
            // so needs to check *iter <= nums[i] + t
            
            auto iter = window.lower_bound(static_cast<long>(nums[i]) - t);
            if (iter != window.end() && *iter-t <= static_cast<long>(nums[i]))
                return true;
            
            window.insert(nums[i]);
        }
        
        return false;
    }
};
