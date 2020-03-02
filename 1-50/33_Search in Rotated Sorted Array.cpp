/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        // define return value
        int ret = -1;
        // null case
        if (nums.size() == 0 || 
            (nums.size() == 1 && target != nums[0]) )
            return -1;
        
        // rule: if mid < right; right part must be ordered
        //       if mid > right; left part must be ordered
        
        const int n = nums.size();
        int left = 0;
        int right = n-1;
        int mid;
        
        // NOTE: MUST use "<="
        while (left <= right) {
            mid = (left + right)/2;
            
            if (nums[mid] == target) {
                return mid;
            } 
            else {
                // right ordered
                if (nums[mid] < nums[right]) {
                    if (target < nums[mid]) {
                        right = mid - 1;
                    } else {
                        if (target == nums[right]) {
                            return right;  
                        } else if (target > nums[right]) {
                            right = mid - 1;
                        } else {
                            left = mid + 1;
                        }
                    }
                } else { // left ordered
                    if (target < nums[mid]) {
                        if (target == nums[left]) {
                            return left;
                        } else if (target > nums[left]) {
                            right = mid - 1;
                        } else {
                            left = mid + 1;
                        }
                    } else {
                        left = mid + 1;
                    }   
                }   
            }
        }
        
        return -1;
    }
};
