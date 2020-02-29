/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // null case
        if (nums.size() < 2)
            return vector<vector<int>> {nums};
        
        vector<vector<int>> ret;
        dfs(nums, ret, 0);
        
        return ret;
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>>& ret, int start) {

        // since last element won't have any permutation
        // use "nums.size() - 1" is BETTER than "nums.size()"
        
        for (int i = start, n = nums.size(); i < n; i++) {
            
            if (start == n - 1) {
                // since nums is swaped, we use it as permutation
                // no need to use another vector to keep permutation
                ret.push_back(nums);
                return;
            }
            
            swap(nums[start], nums[i]);
            
            // NOTE: this MUST be start+1 here, NOT i+1
            // reason: we keep 0~start fix, permutation start+1 ~ n-1
            dfs(nums, ret, start+1);
            
            // after dfs, we reset it (make sure nums is the same as original)
            swap(nums[i], nums[start]);
        }
    }
    
};
