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


// keypoints:
// 1. in array [1,n], if no duplicates exist, mid = (1+n)/2, which split array into left and right part
// 2. if no duplicates exist, count(i<mid) = count (i > mid), left and right part should have the same amount
// 3. if duplicates exist, which part has more num than mid, must exist duplicates
// 4. how to decide search range ( or ] and return value (left ? right ?) 
// 
// search range: [1,n) n = nums.size();
// --> nums.size() = n, nums value in range [1, n-1], if we choose right = n, should use <. right = n-1, use =
// return value depends on we serach left boundary or right boundary
// --> left boundary: return left    right boundary: return left-1 


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
        
        // given info: nums are in range [1, n]
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
