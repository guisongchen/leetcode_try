/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // corner case
        if (nums.empty())
            return false;
        
        int left = 0;
        int right = nums.size()-1;
        
        // keypoint: compare mid and right, decide which part is ordered
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > nums[right]) { // left ordered
                
                // since left is ordered, consider conditions make target lies in left
                // NOTE: "=" must apply on left or right to hit the corner case
                if (nums[mid] > target && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < nums[right]) { // right ordered
                // since right is ordered, consider conditions make target lies in right
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { // if mid equals to right, move left one step
                right--;
            }
        }
        
        return false;
    }
};
