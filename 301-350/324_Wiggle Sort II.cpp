/*

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

*/



class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // sort and split nums into two parts
        // across insert second part into first part
        sort(nums.begin(), nums.end());
        vector<int> temp(nums);

        int mid = (nums.size()+1)/2; // use --
        // from mid to end may occur error when duplicated exist(4 5 5 6)
        // start from end to mid and mid to start
        int big = nums.size(); // use --big
        for (int i = 0, n = nums.size(); i < n; ++i) {
            nums[i] = i % 2 ? temp[--big] : temp[--mid];
        }
    }
};
