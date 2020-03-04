/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0

*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        // find which part is ordered
        if (nums.size() == 1)
            return nums[0];
        
        int left = 0;
        int right = nums.size()-1;
        int ret = INT_MAX;
        // keypoint: draw graph to analyze
        // 4 cases exist, drawing will make problem clearer
        // compare mid and right instead mid and left make life easier
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > nums[right]) { // search right
                ret = min(ret, nums[right]);
                left = mid + 1;
            } else if (nums[mid] < nums[right]){ //search left
                ret = min(ret, nums[mid]);
                right = mid - 1;
            } else {
                ret = min(ret, nums[mid]);
                --right;
            }
        }
        
        return ret;
    }
};
