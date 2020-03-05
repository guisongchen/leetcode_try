/*

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

*/

// keypoints:
// 1. due to distance constrain, sort is not suitable
// 2. use hash, use value as key: <value, idx>

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // due to distance constrain, sort is not suitable
        // use hash
        
        // use value as key: <value, idx>
        unordered_map<int, int> hash;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            
            if (hash.count(nums[i]) && i - hash[nums[i]] <= k)
                    return true;

            hash[nums[i]] = i;
        }
        
        return false;
    }
};
