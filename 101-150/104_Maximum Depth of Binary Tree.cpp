/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
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

// solution 1: recursively
// solution 2: layer traverse, return layer count

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // corner case
        if (!root)
            return 0;
        // if root exist, depth+1
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // corner case
        if (!root)
            return 0;
        
        // use layer traverse, return layers cnt
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        
        while (!q.empty()) {
            // use n to control pop same layers notes
            int n = q.size();
            cnt++;
            while (n--) {
                TreeNode* t = q.front();
                q.pop();
                
                if(t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
        
        return cnt;
    }
};
