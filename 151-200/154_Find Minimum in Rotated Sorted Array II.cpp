/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0
Note:

This is a follow up problem to Find Minimum in Rotated Sorted Array.
Would allow duplicates affect the run-time complexity? How and why?

*/



// keypoints:
// 1. looking for left boundary
// 2. compare mid and right to decide which side is in sequence
// 3. use --right when duplicated

class Solution {
public:
    int findMin(vector<int>& nums) {
        // find which part is ordered
        if (nums.size() == 1)
            return nums[0];
        
        int left = 0;
        int right = nums.size()-1;
        // keypoint: draw graph to analyze
        // compare mid and right instead mid and left make life easier
        
        // search range: [left, right)
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > nums[right]) { // search right
                
                left = mid + 1; // make sure search range contiguous:[mid+1, right) 
                
            } else if (nums[mid] < nums[right]) { //search left, nums[mid] <= nums[right]
                
                right = mid; // make sure search range contiguous:[left, mid) 
                
            } else {
                
                --right;
                
            }
        }
        
        return nums[left]; // since left = right, both is ok
    }
};
