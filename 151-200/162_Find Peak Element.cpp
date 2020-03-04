/*

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
Note:

Your solution should be in logarithmic complexity.

*/


// solution 1 
// 1. search from begin to end
// 2. corner cases: "1" "12" "21"

// solution 2
// 1. we are told peak must exist, so we can use binary search to get logarithmic complexity

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // corner case: "1" "12" "21"
        // notice: return index not value
        if (nums.size() < 2)
            return 0;
        if (nums.size() == 2)
            return nums[0] > nums[1] ? 0 : 1;
        
        int n = nums.size();
        for (int i = 0; i <= n-3; i++) {
            if (nums[i+1] > nums[i] && nums[i+1] > nums[i+2]) {
                return i+1;
            }
        }
        
        if (nums[n-1] > nums[n-2])
            return n-1;
        
        return 0;
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // corner case: "1" "12" "21"
        // notice: return index not value
        if (nums.size() < 2)
            return 0;
        
        // also such compare left and right will lead to binary seach naturally
        int left = 0;
        int right = nums.size()-1;
        
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > nums[mid+1]) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        
        return right;
    }
};
