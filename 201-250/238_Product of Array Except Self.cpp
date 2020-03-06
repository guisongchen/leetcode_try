/*

Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // result = prevProduct * nextProduct
        int n = nums.size();
        
        vector<int> ret(n, 1);
        
        // compute product of all nums which ahead of i
        for (int i = 1; i < n; ++i) {
            ret[i] = ret[i-1] * nums[i-1];
        }
        
        // now ret[i] keeps product of all nums which ahead of i(prev)
        
        // compute product of all nums which next of i
        int temp = 1; // track products from right
        for (int i = n-1; i >= 0; --i) {
            
            // ret = prev * next = ret * temp
            ret[i] *= temp;
            
            // update products from right
            temp *= nums[i];
        }
        
        return ret;
    }
};
