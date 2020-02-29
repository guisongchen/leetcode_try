/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
// keypoints: cut branches by if-expression

// if ( i>0 && !visited[i-1] && nums[i] == nums[i-1])
// MUST be "!visited[i-1]", use "i-1" here
// we already know visited[i] is false here
// if visited[i-1] is false, two possible reason:
// 1. nums[i-1] is not used, which is impossible, since we move forward, i-1 must be used
// 2. nums[i-1] is used before, this is retrieved value after dfs
//    since it is used, and nums[i] == nums[i-1]
//    means put nums[i] into num[i-1] position will cause repeat permutation

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // difference from Permutation I : contain duplicates
        
        // null case
        if (nums.size() < 2) 
            return vector<vector<int>> {nums};
        
        vector<vector<int>> ret;
        vector<bool> visited(nums.size(), false);
        vector<int> cur;
        
        // patch for duplicates: order to simplify
        sort(nums.begin(), nums.end());
        dfs(nums, ret, visited, cur);
        
        return ret;
    }
    
private:
    void dfs(vector<int>& nums, vector<vector<int>>& ret, 
             vector<bool>& visited, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            ret.push_back(cur);
            return;
        }
        
        for (int i = 0, n = nums.size(); i < n; i++) {
            
            if (visited[i])
                continue;
            
            // MUST be "!visited[i-1]", use "i-1" here
            // we already know visited[i] is false here
            // if visited[i-1] is false, two possible reason:
            // 1. nums[i-1] is not used, which is impossible, since i = 0 must use it
            // 2. nums[i-1] is used before, this is retrieved value after dfs
            //    since it is used, and nums[i] == nums[i-1]
            //    means nums[i] was coverd by nums[i-1] permutation
            if ( i>0 && !visited[i-1] && nums[i] == nums[i-1])
                continue;
            
            visited[i] = true;
            cur.push_back(nums[i]);
            dfs(nums, ret, visited, cur);
            cur.pop_back();
            visited[i] = false;
            
        }
    }
};
