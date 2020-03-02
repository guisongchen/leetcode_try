/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

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
    bool isBalanced(TreeNode* root) {
        // this is travial, get height of left and right subtree, then compare
        // keypoint is every node, not only the max height of subtree
        
        // corner case
        if (!root)
            return true;
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        if ((left - right < -1) || (left - right > 1))
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};
