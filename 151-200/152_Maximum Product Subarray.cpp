/*

Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // keypoints: contiguous and largest product
        // negative is tricky, odd is bad even is good
        // zero is tricky too, better than neg, worse than pos
        
        // track max and min at the same time for each idx
        // max for pos or zero exist case
        // min for neg case, if we meet two neg, it will bw positive
        
        if (nums.size() == 1)
            return nums[0];
        
        int ret = nums[0];
        int maxVal = nums[0];
        int minVal = nums[0];
        
        for (int i = 1, n = nums.size(); i < n; i++) {
            
            // max value must be one of those three
            
            int cur = nums[i]; // if maxVal <= 0, minVal <= 0
            int maxProd = maxVal*nums[i]; // if maxVal > 0, num > 0
            int minProd = minVal*nums[i]; // if minVal < 0, num < 0
            
            maxVal = max(max(maxProd, minProd), cur);
            minVal = min(min(maxProd, minProd), cur);
            
            ret = max(ret, maxVal);
        }
        
        return ret;
    }
};
