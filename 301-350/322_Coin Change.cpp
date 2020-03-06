/*

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.

*/



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // package problem, use dynamic planning
        if (amount < 1)
            return amount == 0 ? 0 : -1;
        
        // start from 1, use amount+1 to distinguish all '1' case
        vector<int> dp(amount+1, amount+1); // worst case: if exist 1, use amount 1
        dp[0] = 0;
        
        // calcuate minimum coins number of amount i
        for (int i = 1; i <= amount; ++i) {       
            for (int j = 0, n = coins.size(); j < n; ++j) {
                if (coins[j] <= i)
                    // means only use i-th num or use j and i-corns[j]
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        
        return dp.back() == amount+1 ? -1 : dp.back();
    }
};
