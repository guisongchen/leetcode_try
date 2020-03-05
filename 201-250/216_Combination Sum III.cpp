/*

Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]

*/


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n < k)
            return vector<vector<int>>{};
        
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(ret, cur, k, n, 1);
        
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int>& cur,
             int k, int sum, int start) {
        if (start > 10 || cur.size() > k)
            return;
        if (cur.size() == k) {
            if (sum == 0)
                ret.push_back(cur);
            return;
        }
        
        for (int i = start; i < 10; ++i) {
            cur.push_back(i);
            dfs(ret, cur, k, sum-i, i+1);
            cur.pop_back();
        }
    }
};
