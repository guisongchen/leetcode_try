/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]


*/

// keypoints: use finite state machine

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // use finite state machine
        
        //        cooldown(do noting)
        //         ______
        //        |__s0__|
        //        /       \
        //      buy     cooldown
        //      /   sell    \ 
        //     _s1__ ------ s2
        //    |_____|
        //    cooldown(do nothing)    
        // s0: do nothing, no buy, no sell
        // s1: holding (after buy)
        // s2: transacted(after sell)
        
        // s0 and s1 may cooldown, which means they just repreat last status
        // s0[i] = max(s0[i-1], s2[i-1]) 
        // s1[i] = max(s1[i-1], s0[i-1] - price[i]) 
        // s2[i] = s1[i-1] + price[i]
        
        if (prices.empty())
            return 0;
        
        int n = prices.size();
        vector<int> s0(n, 0);
        vector<int> s1(n, 0);
        vector<int> s2(n, 0);
        
        s1[0] = -prices[0];
        
        for (int i = 1; i < n; ++i) {
            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
            s2[i] = s1[i-1] + prices[i];
        }
        
        // s1 is holding status, definitely less than s0 and s2
        return max(s0[n-1], s2[n-1]);
    }
};
