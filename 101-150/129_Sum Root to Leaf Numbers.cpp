/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/


// solution 1
// 1. we do it recursively
// 2. keypoint is curSum = 10*rootVal + leftVal + rightVal
// 3. recursive expression is :   dfs(curRootNode, parentVal)
//    curVal: 10*parentVal + curRootNode->val
//    sum = dfs(leftNode, curVal) + dfs(rightNode, curVal)


// solution 2
// 1. we do it iteratively
// 2. pre-order traverse, add rootVal*10 on left and rigt node, return leaf sum value
// 3. layer traverse also works


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
    int sumNumbers(TreeNode* root) {
        // do it recursively
        if (!root)
            return 0;
        return dfs(root, 0);
    }
    
    int dfs (TreeNode* root, int last) {
        if (!root)
            return 0;
        
        // deep down a layer, multiply 10 of last sum
        if (!root->left && !root->right)
            return 10*last + root->val;
        
        int cur = 10 * last + root->val;
        
        return dfs(root->left, cur) + dfs(root->right, cur);
    }
};


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
    int sumNumbers(TreeNode* root) {
        // do it iteratively
        // 1. add each layer value to leaf
        // -> use layer traverse and update node value according to depth
        // 2. add leaf value and return
        
        // last solution has changed input tree node
        // maybe we can try more cleaner way without change node value
        // maybe use stack and roll back with sum/10 to retrive node value
        
        if (!root)
            return 0;
        
        queue<TreeNode*> q({root});
        
        int sum = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                root = q.front();
                q.pop();
                
                // leaf value sum
                if (!root->left && !root->right)
                    sum += root->val;
                
                // update node value by layer number
                if (root->left) {
                    root->left->val += 10 * root->val;
                    q.push(root->left);
                }
                
                if (root->right) {
                    root->right->val += 10 * root->val;
                    q.push(root->right);
                }
            }
        }
        
        return sum;
    }
};
