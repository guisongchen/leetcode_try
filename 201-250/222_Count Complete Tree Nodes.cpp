/*

Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

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
    int countNodes(TreeNode* root) {
        // if left sub-tree height is same as right, then it will be perfect binary tree
        // which nodes is 2^n - 1
        // else we have to recusive divide it into subtree, until only one node exist
        
        if (!root)
            return 0;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        int cnt1 = 1, cnt2 = 1; // since root exist
        
        while (left) {
            left = left->left;
            ++cnt1;
        }
        
        while (right) {
            right = right->right;
            ++cnt2;
        }
        
        if (cnt1 == cnt2) // full, 2^n - 1
            return pow(2, cnt1) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
