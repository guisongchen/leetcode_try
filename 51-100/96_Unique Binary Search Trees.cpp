/*

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

// same as Unique Binary Search Trees II


class Solution {
public:
    int numTrees(int n) {
        // use dfs
        // corner case
        if (n < 1)
            return 0;
        
        // use cache to speed up
        vector<vector<int>> cache(n, vector<int>(n, 0));
        return dfs(1, n, cache);
    }
    
    int dfs(int start, int end, vector<vector<int>>& cache) {
        
        // notice: if left not exist, nullptr is still a node
        // return 1 rather than 0
        if (start > end)
            return 1;
        
        if (cache[start-1][end-1] != 0)
            return cache[start-1][end-1];
        
        int sum = 0;
        for (int i = start; i <= end; i++) {
            int left = dfs(start, i-1, cache);
            int right = dfs(i+1, end, cache);
            sum += left * right;
        }
        cache[start-1][end-1] = sum;
        
        return sum;
    }
};
