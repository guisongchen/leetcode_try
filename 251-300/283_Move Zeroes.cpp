/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

// instead of moving zero to the end, we move non-zero to the front!!

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // keypoints: move non-zero digits forward, put in nonZeroCnt position
        for (int cur = 0, nonZeroCnt = 0, n = nums.size(); cur < n; ++cur) {
            if (nums[cur]) {
                swap(nums[nonZeroCnt], nums[cur]);
                ++nonZeroCnt;
            }
        }
    }
};
