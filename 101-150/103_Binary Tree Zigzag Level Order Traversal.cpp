/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // two keypoints: layer traverse and zigzag
        // layer traverse is handle by queue
        // zigzag is handle by the sequence of push left and push right 
        
        if (!root)
            return vector<vector<int>>{};
        
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        
        // since root is left to right, init as true
        bool l2r = true;
        while (!q.empty()) {     
            // use n to control only pop same layer nodes, leave next layer untouched
            int n = q.size();
            
            // instead od use stack, use vector do reverse when envalue elements
            vector<int> cur(n);
            
            for (int i = 0; i < n; i++) {
                TreeNode* t = q.front();
                if (l2r)
                    cur[i] = t->val;
                else
                    cur[n-i-1] = t->val;
                q.pop();
                
                if (t->left) 
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            
            // swap
            l2r = !l2r;  
            ret.push_back(cur);
        }
        
        return ret;
    }
};
