/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

// keypoints:
// 1. use dfs to find all matched results
// 2. sort to speed up.(since sorted, we can cut branches to reduce runtime)

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            
            cur.push_back(nums[i]);
            dfs(nums, target, ret, cur, sum+nums[i], i);
            cur.pop_back();
        }
        
    }
    
};
