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

// keypoints:
// 1. using binary search
// 2. since array is rotated, needs to find which part is in sequence
// 3. use three pointers: left, mid, right
//
// use mid and right pointers to find which part is sorted
// mid < right:   right part is in sequence
// mid > right:   left part is in sequence

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            
            int mid = left + (right-left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < nums[right]) { // right in sequence
                if (nums[mid] < target && nums[right] >= target) { // compare right head and tail
                    left = mid + 1; // update left, so "=" should at right side
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] > nums[right]) { // left in sequence
                if (nums[mid] > target && nums[left] <= target) { // compare left head and tail
                    right = mid -1 ; // update right, so "=" should at left side
                } else {
                    left = mid + 1;
                }
            } else { // nums[mid] == nums[right]
                return -1;
            }
        }
        
        return -1;
        
    }
};


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
