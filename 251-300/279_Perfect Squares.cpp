/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/


class Solution {
public:
    int numSquares(int n) {
        // use dynamic programming
        vector<int> dp(1, 0);
        
        // size at most is n(which: 1+1+1....)
        while (dp.size() <= n) {
            int m = dp.size();
            int val = INT_MAX;
            
            // i move one step forward, dp[] move 1 step backward
            // aka if exist i >= 1 and i*i < m, we could use i*i to replace '1'
            // this will decrease numbers
            for (int i = 1; i*i <= m; ++i) {
                
                // update val
                val = min(val, dp[m - i*i] + 1);
            }
            
            dp.push_back(val);
        }
        
        return dp.back();
    }
};
