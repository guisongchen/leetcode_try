/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

// same as 3sum, but we need to fix 2 elements, then convert to 2sum


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // key idea: trans to 3sum problem
        // define return value
        vector<vector<int>> ret;
        // null case
        if (nums.size() < 4)
            return ret;
        
        // sort to fix 1st and 2st pointer
        sort(nums.begin(), nums.end());
        
        const int n = nums.size();
        for (int i = 0; i < n-3; i++) {
            
            // fix pointer 1
            int& fix1 = nums[i];
            // cut to reduce runtime
            if (fix1 >= 0 && fix1 > target)
                return ret;
            
            // avoid reduatant
            if (i > 0 && nums[i] == nums[i-1])
                    continue;
            
            
            for (int j = i+1; j < n-2; j++) {
                
                // fix pointer 2
                int& fix2 = nums[j];
                
                // cut to reduce runtime
                // NOTE: use break here, NOT return
                if (fix1 + fix2 > target && fix2 >= 0)
                    break;
                
                // avoid reduatant
                if (j > i+1 && nums[j] == nums[j-1])
                    continue;
                int tar = target - fix1 - fix2;
                int lt = j+1;
                int rt = n-1;

                while (lt < rt) {
                    if (nums[lt]+nums[rt] == tar) {
                        vector<int> cur{fix1, fix2, nums[lt], nums[rt]};
                        ret.push_back(cur);
                        lt++;
                        rt--;
                        while (lt < rt && nums[lt] == nums[lt-1])
                            lt++;
                        while (lt < rt && nums[rt] == nums[rt+1])
                            rt--;
                    } else if (nums[lt]+nums[rt] < tar) {
                        lt++;
                        while (lt < rt && nums[lt] == nums[lt-1])
                            lt++;
                    } else {
                        rt--;
                        while (lt < rt && nums[rt] == nums[rt+1])
                            rt--;
                    }
                }
            }
        }
        
        return ret;
    }
};
