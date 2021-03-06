/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

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
    bool isValidBST(TreeNode* root) {
        // in order traverse and compare
        // corner case
        if (!root)
            return true;
        
        // inorder travesal is ordered, last should less than curr
        int last = INT_MIN;
        bool init = false;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            
            while (root) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            
            if (init) {
                
                if (root->val <= last)
                    return false;
                
            } else { // corner case, in case root->val = INT_MIN
                init =true;
                last = root->val;
            }
            
            st.pop();
            last = root->val;
            
            root = root->right;
        }
        
        return true;
    }
};
