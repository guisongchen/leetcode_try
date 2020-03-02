/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // first, do it recursively
        // or we can do it iteratively
        if (!root)
            return vector<vector<int>>{};
        
        vector<vector<int>> ret;
        vector<TreeNode*> s;
        int cnt = 0;
        
        TreeNode* prev = nullptr;
        while (root || !s.empty()) {
            while (root) {
                s.push_back(root);
                cnt += root->val;
                root = root->left;
            }
            
            // check last node, two possiblilites
            // 1. push from top to down, may be left leaf or subtree without left-node
            // 2. pop from down to top
            // use prev to distinguish those two
            root = s.back();

            // if root is left leaf, which means has no right child
            if (!root->left && !root->right && sum == cnt) {
                vector<int> cur;
                for (auto t : s) 
                    cur.push_back(t->val);
                ret.push_back(cur);
            }

            if (root->right && root->right != prev) { // top to down, do iterative
                root = root->right;
            } else { // down to top, root->right == prev(has visited!)
                // roll back
                prev = root;
                cnt -= root->val;
                s.pop_back();
                root = nullptr; // set null to pop left nodes until back to original root
            }
        }
        
        return ret;
    }
};
