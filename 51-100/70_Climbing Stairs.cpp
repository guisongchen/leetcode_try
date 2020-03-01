/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

// keypoints:
// 1. using dynamic planning, dp[i] = dp[i-1] + dp[i-2];
// 2. corner case: n =1, n =2
// 3. step from 1 to n, dp should from 0 to n, with dp[0] = 1

class Solution {
public:
    int climbStairs(int n) {
        // must be dynamic planning
        // corner case
        if (n < 3)
            return n;
        
        // padding to map 0~n steps, padding grid dp[0] = 1
        vector<int> dp(n+1, 1);
        for (int i = 2; i<= n; i++) {
            // current status i = (i-1) move 1 step and (i-1) move 2 steps
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};
