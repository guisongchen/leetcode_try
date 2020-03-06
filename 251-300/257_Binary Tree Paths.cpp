/*

Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

*/



// keypoints:
// 1. for tree-associate problems, recursive will alway be a choise
// 2. careful when we need to add "->"


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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root)
            return vector<string>{};
        if (!root->left && !root->right)
            return vector<string>{to_string(root->val)};
        
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        
        string cur = to_string(root->val);
        vector<string> ret;
        for (auto it : left) {
            string temp = cur + "->" + it;
            ret.push_back(temp);
        }
        for (auto it : right) {
            string temp = cur + "->" + it;
            ret.push_back(temp);
        }
        
        return ret;
    }
};
