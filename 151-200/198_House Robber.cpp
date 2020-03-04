/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
             Total amount you can rob = 2 + 9 + 1 = 12.
             
*/


// keypoint: kind of like climb stairs,
// i-th maxVal is based on use or not use i-th num
// dp[i] = dp[i-1] means skip i-th num
// dp[i] = dp[i-2] + nums[i] means use i-th num
// init: dp[0] and dp[1] are corner cases


class Solution {
public:
    int rob(vector<int>& nums) {
        // corner case
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        // keypoint: kind of like climb stairs,
        // i-th maxVal is based on use or not use i-th num
        // dp[i] = dp[i-1] means skip i-th num
        // dp[i] = dp[i-2] + nums[i] means use i-th num
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]); // notice this, could start foem 0 or 1
        
        for (int i = 2, n = nums.size(); i < n; i++) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        
        return dp.back();
    }
};
