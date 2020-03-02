/*

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/

// keypoints:
// 1. use bfs
// 2. use queue to record each layer elements
// 3. use queue.size() to control pop time, make sure only same layer elements are poped

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // keypoint is how to decide a layer is finished
        if (!root)
            return vector<vector<int>>{};
        
        vector<vector<int>> ret;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
        
            // now all elements in que is on same layer
            int n = que.size();
            vector<int> cur;
            
            // use n to control pop times, make sure only pop current nodes
            // use queue to make sure next layer nodes are added at the end
            while (n--) {
                TreeNode* t = que.front();
                cur.push_back(t->val);
                que.pop();
                
                if (t->left)
                    que.push(t->left);
                if (t->right)
                    que.push(t->right);
            }
            
            // save current layer in result
            ret.push_back(cur);
        }
        
        return ret;
    }
};
