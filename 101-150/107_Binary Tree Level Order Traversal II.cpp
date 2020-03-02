/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // which is travial, use queue traverse then reverse
        if (!root)
            return vector<vector<int>>{};
        
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> cur;
            
            while (n--) {
                TreeNode* t = q.front();
                q.pop();
                
                cur.push_back(t->val);
                
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            
            ret.push_back(cur);
        }
        
        return vector<vector<int>>(ret.rbegin(), ret.rend());
        
    }
};
