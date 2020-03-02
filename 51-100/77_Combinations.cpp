/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // corner case
        if (n < 1 || k < 1)
            return vector<vector<int>>{};
        
        vector<vector<int>> ret;
        vector<int> cur(k, 0);
        
        // notice the fact:
        // 1. the first elements add 1 after the last elements over k
        // 2. the first elements should not over n-k+1
        
        int i = 0;
        while (i >= 0) {
            // update first element
            cur[i]++;
            
            if (cur[i] > n) { // over n, retrive back to last position
                i--;
            } else if (i == k-1) {
                ret.emplace_back(cur);
            } else {
                // move i to i+1, then update i(plus one)
                cur[i+1] = cur[i];
                i++;
            }
        }
        
        return ret;
    }
    
};


// keypoints:
// dfs always works

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // corner case
        if (n < 1 || k < 1)
            return vector<vector<int>>{};
        
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(n, k, ret, cur, 1);
        
        return ret;
    }
    
private:
    void dfs(int n, int k, vector<vector<int>>& ret,
             vector<int>& cur, int idx) {
        if (idx > n+1)
            return;
        
        if (cur.size() == k) {
            ret.push_back(cur);
            return;
        }
        
        for (int i = idx; i <= n; i++) {
            cur.push_back(i);
            dfs(n, k, ret, cur, i+1);
            cur.pop_back();
        }
    }
    
};
