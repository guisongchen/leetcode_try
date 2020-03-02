/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.

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
    bool isSymmetric(TreeNode* root) {
        // do it recursively
        
        if (!root)
            return true;
        
        return check(root->left, root->right);
    }
    
    bool check(TreeNode* left, TreeNode* right) {
        // first check current root node
        // left and right both null
        if (!left && !right)
            return true;
        
        if (left && right) {
            if (left->val != right->val)
                return false;
        } else if (left != right) { // only one of them is null
            return false;
        }
        
        // then check symmetric of childern
        return check(left->left, right->right) && check(left->right, right->left); 
    }
        
};
