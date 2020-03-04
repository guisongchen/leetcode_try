/*

Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?

*/

// solution 1:
// 1. backup original array, reassign them using map:   nums[(i+k) % n] = backup[i]
//    if we link tail to head, it's clear to see the rule.

// solution 2:
// using O(1) space by reverse sub-array
// 1 2 3 4 5 6 7 -> reverse n-k from head(n = 7 , k = 3)
// 4 3 2 1 5 6 7 -> reverse k from tail
// 4 3 2 1 7 6 5 -> reverse all
// 5 6 7 1 2 3 4
// in case k > n, k %= n;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // idx map: i -> (i+k) % n;
        
        if (k == 0)
            return;
        
        vector<int> cp(nums);
        for (int i = 0, n = nums.size(); i < n; ++i) {
            nums[(i+k) % n] = cp[i];
        }
    }
};



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // idx map: i -> (i+k) % n;
        // or using O(1) space by reverse sub-array
        // 1 2 3 4 5 6 7 -> reverse n-k from head(n = 7 , k = 3)
        // 4 3 2 1 5 6 7 -> reverse k from tail
        // 4 3 2 1 7 6 5 -> reverse all
        // 5 6 7 1 2 3 4
        
        // corner case: [-1], 2
        if (nums.empty() || k % nums.size() == 0)
            return;  
        
        
        int n = nums.size();
        k %= n; // in case k > n
        for (int i = 0, j = n-k-1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        
        for (int i = n-k, j = n-1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
        
        for (int i = 0, j = n-1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }
};
