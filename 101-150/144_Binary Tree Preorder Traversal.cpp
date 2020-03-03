/*

Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
Follow up: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> preorderTraversal(TreeNode* root) {
        // first do it recursively
        // now let's do it iteratively
        if (!root)
            return vector<int>{};
        
        vector<int> ret;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            
            while (root) {
                ret.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            
            root = root->right;   
        }
        
        return ret;
    }
};
