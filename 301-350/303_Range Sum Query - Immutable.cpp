/*

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

*/


class NumArray {
public:
    NumArray(vector<int>& nums) {
        dp.assign(nums.begin(), nums.end());
        for (int i = 1, n = nums.size(); i < n; ++i) {
            dp[i] += dp[i-1];
        }
    }
    
    int sumRange(int i, int j) {      
        return i == 0 ? dp[j] : dp[j] - dp[i-1];
    }
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
