/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/

// keypoints:
// 1. pre-order traverse, root->left->root, such that root value will be added on leaves
// 2. leaf's value will be the sum from root to leaf, compare with input to slove

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
    bool hasPathSum(TreeNode* root, int sum) {
        // keypoint: root to leaf
        // do it recursively is travial, let's do it iteratively
        // do pre-order traverse, add last  layer root value to current layer node
        // when we reach leaf node, compare to sum, if equal must exist path
        // why pre-order?
        // only this we first visit root and add root value to childern node
        
        if (!root)
            return false;
        
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            
            root = s.top();
            s.pop();
            if (!root->left && !root->right && sum == root->val)
                return true;
            
            if (root->left) {
                root->left->val += root->val;
                s.push(root->left);
            }
            
            if (root->right) {
                root->right->val += root->val;
                s.push(root->right);
            }
        }
        
        return false;
    }
};
