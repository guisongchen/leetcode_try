/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

// keypoints:
// basic idea: fix one element, then choose another two elements(like 2 sum)
//
// How to handle it efficiently and without repeat elements
// 1. sort, we search along with sorted number, and skip the repeated ones(which is import)
// 2. use double pointer, search from left and right side of sorted array
// 3. cut branches, when the fix number is positive, since sorted from small to big, we can break safely

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // define return
        vector<vector<int>> ret;
        // null case
        if (nums.size() == 0)
            return ret;
        const int n = nums.size();
        
        // sort to fix one of three elements
        sort(nums.begin(), nums.end());
        
        // do loop
        for (int i = 0; i < n; i++) {
            int& fix = nums[i];
            if (fix > 0)
                break;
            // handle redundant for fix element
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int lt = i+1;
            int rt = n-1;
            
            while (lt < rt) {
                int& lv = nums[lt];
                int& rv = nums[rt];
                
                if (lv+rv == -fix) {
                    vector cur{fix, lv, rv};
                    ret.push_back(cur);
                    lt++;
                    rt--;
                    
                    // handle repeated elements for left and right elements
                    while (lt < rt && nums[lt] == nums[lt-1])
                        lt++;
                    while (lt < rt && nums[rt] == nums[rt+1])
                        rt--;
                } else if (lv+rv < -fix) {
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
        return ret;
    }
};
