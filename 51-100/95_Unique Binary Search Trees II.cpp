/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        // corner case
        if (n < 1)
            return vector<TreeNode*>{};
        
        // now add memo to speed up
        vector<vector<vector<TreeNode*>>> memo(n, vector<vector<TreeNode*>>(n));
        return helper(1, n, memo);
    }
    
    vector<TreeNode*> helper(int start, int end,
                             vector<vector<vector<TreeNode*>>>& memo) {
        
        if (start > end)
            return vector<TreeNode*>{nullptr};
        
        if (!memo[start-1][end-1].empty())
            return memo[start-1][end-1];
        
        vector<TreeNode*> ret;
        for (int i = start; i <= end; i++) {
            
            // less than i consider as left subTree, it may has many options
            vector<TreeNode*> left = helper(start, i-1, memo);
            // greater than i consider as right subTree, it may has many options
            vector<TreeNode*> right = helper(i+1, end, memo);
            
            // put root and all left and right options together
            for (auto a : left) {
                for (auto b : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = a;
                    root->right = b;
                    ret.push_back(root);
                }
            }
        }
        
        memo[start-1][end-1] = ret;
        
        return ret;
    }
};
