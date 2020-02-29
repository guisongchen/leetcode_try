/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

// two differents from "Combination Sum I"
// 1. elements may duplicate
// 2. elements only use once

// patch for--> 1. elements may duplicate
// -> if the start num is the same, skip it;
//    if (i-1 >= start && nums[i] == nums[i-1])  continue;
// NOTE: i-1 >= start, it MUST be "start" here, because we don't use the same start num, it cause repeated combination
// should not involve last loop, so it CAN'T be i -1 >= 0

// patch for--> 2. elements only use once
// i-->i+1, move one step forward

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // two differents from "Combination Sum I"
        // 1. elements may duplicate
        // 2. elements only use once
        
        // define return
        vector<vector<int>> ret;
        // null case
        if (candidates.size() == 0)
            return ret;
        
        sort(candidates.begin(), candidates.end());
        
        // cut
        if (target < candidates[0])
            return ret;
        
        vector<int> cur;
        dfs(candidates, target, ret, cur, 0, 0);
        
        return ret;
    }
    
private:
    void dfs(vector<int>& nums, int& target, vector<vector<int>>& ret,
             vector<int>& cur, int sum, int start) {
        if (sum == target) {
            ret.push_back(cur);
            return;
        } else if (sum > target) {
            return;
        }
        
        for (int i = start, n = nums.size(); i < n; i++) {
            
            if (sum+nums[i] > target)
                return;
            
            // patch for--> 1. elements may duplicate
            // NOTE: i-1 >= start, it MUST be "start", aka start of current loop
            // should not involve last loop, so it CAN'T be i -1 >= 0
            if (i-1 >= start && nums[i] == nums[i-1])
                continue;
            
            cur.push_back(nums[i]);
            
            // patch for--> 2. elements only use once
            // i-->i+1
            dfs(nums, target, ret, cur, sum+nums[i], i+1);
            cur.pop_back();
        }
        
    }
};
