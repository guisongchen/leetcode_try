/*

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

// keypoints:
// 1. use dfs, sort at first make life easier
// 2. skip duplicate in for-loop(thanks to sort make this efficient)
// 3. using "i > start" to make sure at least use one of duplicates

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        // use vector instead of set, cut duplicated when recursive
        vector<vector<int>> ret;
        vector<int> cur;
        
        // it's hard to distinguish "4414" and "4144". so sort at first
        sort(nums.begin(), nums.end());
        dfs(nums, ret, cur, 0);
        return ret;
    }
    
private:
    void dfs(vector<int>& nums, vector<vector<int>>& ret,
             vector<int>& cur, int start) {
        
        ret.push_back(cur);
        
        for (int i = start, n = nums.size(); i < n; i++) {
            
            // MUST use "i > start" to make sure use one of duplicated nums
            if (i > start && nums[i] == nums[i-1])
                continue;
            
            cur.push_back(nums[i]);
            dfs(nums, ret, cur, i+1);
            cur.pop_back();
            
            // this code is used to skip duplicated num
            // since we should use one of duplicated nums
            // OR we can use code  "if-continue" like above 
            /*
            while (i+1 < n && nums[i+1] == nums[i])
                i++;
            */
        }
    }
    
};

