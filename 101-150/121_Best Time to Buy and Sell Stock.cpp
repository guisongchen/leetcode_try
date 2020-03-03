/*

ay you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // keypoints:
        // 1. use until-now min as buy price(NOT min of all array)
        // 2. compute profit use cur value and buy price

        if (prices.empty())
            return 0;
        
        int buy = INT_MAX; // must use INT_MAX, not 0
        int profit = 0;
        for (auto p : prices) {
            buy = min(buy, p);
            profit = max(profit, p - buy);
        }

        return profit;
    }
};
