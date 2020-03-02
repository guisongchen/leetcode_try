/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        // keypoint is the path to LEAF node
        // recursive is travial, we can do it iteratively
        // do layer trarverse, return layer num of first LAEF node
        if (!root)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while (!q.empty()) {
            int n = q.size();
            cnt++;
            while (n--) {
                TreeNode* t = q.front();
                
                // this is NOT choose branch here, we do it one by one
                // do NOT use if-else
                
                // check leaf node or not
                if (!t->left && !t->right)
                    return cnt;
                
                // left behind in case we can save some time
                q.pop();
                
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
        
        return cnt;
    }
};
