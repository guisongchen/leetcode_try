/*

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

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
    TreeNode* invertTree(TreeNode* root) {
        // layer traverse, then invert layer elements
        if (!root)
            return nullptr;
        
        // use itertive approach
        TreeNode* cur = root;
        queue<TreeNode*> q({cur});
        
        while (!q.empty()) {
            
            int n = q.size();
            
            while (n--) {
                cur = q.front();
                q.pop();

                // swap left ad right
                TreeNode* temp = cur->left;
                cur->left = cur->right;
                cur->right = temp;
                
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                
            }
        }
        
        return root;
    }
};
