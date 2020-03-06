/*

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // corner case
        int n = nums.size();
        
        if (n < 3)
            return n == 0 ? 0 : nums[0];
        
        // binary search 
        int left = 1;
        int right = n;
        
        // use the pre-info nums are in range [1, n]
        // which means value has same range with idx
        while (left < right) {
            int mid = left + (right-left)/2;
            
            // compare all nums with val, decide 
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid) {
                    ++cnt;
                } 
            }
            
            if (cnt <= mid) { // 1~mid has no repeat, move to [mid+1, n], 
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
        
        
    }
};
