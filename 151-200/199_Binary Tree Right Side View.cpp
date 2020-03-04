/*

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  
  */
  
// keypoints:
// change view, consider as layer traverse, return the last node of each layer
// why not use root->right?
// corner case:

/*
      1            <---
    /   \
   2     3         <---
  /     
 5   <---
  
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
    vector<int> rightSideView(TreeNode* root) {
        // change view, consider as layer traverse
        // return the last node of each layer
        if (!root)
            return vector<int>{};
        
        queue<TreeNode*> q({root});
        vector<int> ret;
        
        while (!q.empty()) {
            // the last node must stay at the back of queue
            ret.push_back(q.back()->val);
            
            int n = q.size();
            while (n--) {
                root = q.front();
                q.pop();

        
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
        }
        
        return ret;
    }
};
