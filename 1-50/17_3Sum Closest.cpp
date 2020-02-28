/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

// same idea with 3sum
// keypoints:
// 1. fix one elements, search for another 2
// 2. sort original array
// 3. use binary search

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // define return
        int ret = 0;
        const int n = nums.size();
        // null case
        if (nums.size() < 3)
            return ret;
        
        // sort to fix one of three elements
        sort(nums.begin(), nums.end());
        
        // do loop
        int minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            int& fix = nums[i];
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int lt = i+1;
            int rt = n-1;
            while (lt < rt) {
                int& lv = nums[lt];
                int& rv = nums[rt];
                
                
                if (abs(lv+rv+fix-target) <= minSum) {
                    ret = lv+rv+fix;
                    minSum = abs(ret-target);
                }
                
                if (lv+rv+fix == target) { 
                    return target;    
                } else if (lv+rv+fix < target) {
                    lt++;
                } else { rt--; }
            }
        }
        return ret;
    }
};
