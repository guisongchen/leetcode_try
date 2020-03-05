/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
             
*/

// keypoints:
// 1. similar as house robber I, challenge is first one and last now are adjacent
//    --> can't rob first and last at same time
// 2. divide this into two problems: 
// 1st. remove last house and do house robber I
// 2nd. remove first house and do house robber I
// 3. choose the maximum of those two scenarios


class Solution {
public:
    int rob(vector<int>& nums) {
        // corner case, since last and first linked in circle
        int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
        else if (n == 2)
            return max(nums[0], nums[1]);
        
        // use dp
        // now 0 and n-1 are linked, so consider two scenario:
        // 0 to n-2
        // 1 to n-1
        int sum1 = 0, sum2 = 0;
        vector<int> dp(n, 0);
        
        // scenario 1: 0 to n-2
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);     
        for (int i = 2; i < n-1; ++i) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }     
        sum1 = dp[n-2];
        
        // scenario 2: 1 to n-1
        // instead of re-assign value of dp, we over-write
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; ++i) {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }     
        sum2 = dp[n-1];
        
        return max(sum1, sum2);
    }
};
