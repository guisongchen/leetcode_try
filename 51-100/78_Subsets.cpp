/*

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        // use distinct property, so we have 2^n subsets
        // since 0 =< n <= 10, use bit operate is safe(INT_MAX = 2^31 - 1)
        
        // k means how many distinct integers are used(if used set correspond bit '1')
        for (int k = 0, max = 1 << nums.size(); k < max; k++) {
            vector<int> cur;
            dfs(nums, cur, k);
            ret.push_back(cur);
        }
        
        return ret;
    }
    
private:
    void dfs(vector<int>& nums, vector<int>& cur, int k) {
        
        // nums index start from 0
        int i = 0;
        
        // use k >> 1 to record finished loop   
        while (k > 0) {
            if (k & 1 == 1) 
                cur.push_back(nums[i]);
            // use one integer, idx move forward
            // set one bit '1', still has k-1 to do, update k by bits
            i++;
            k >>= 1;
        }
    }
};
