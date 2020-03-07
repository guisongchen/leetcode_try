/*

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

*/

// keypoints:
// 1. layer trverse may be wrong, because we may skip two or more layers to find maximum
//    it may happens on left-subtree or right-subtree
// 2. better use recursive, split point will be use current node or not
//    base on different choise, we get maximum from two braches


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
    int rob(TreeNode* root) {
        // layer traverse, find the max sum of un-connected layers
        if (!root)
            return 0;
        
        // ret[0] for result without current node
        // ret[1] for result with current node
        vector<int> ret = dfs(root);
        
        return max(ret[0], ret[1]);
    }
    
    vector<int> dfs(TreeNode* root) {
        if (!root)
            return vector<int>(2, 0);
        
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        
        vector<int> ret(2, 0);
        // case 1: without current node, choose max from left or right(use or not both be accepted)
        ret[0] = max(left[0], left[1]) + max(right[0], right[1]);
        // case 2: using current node, then must NOT use left and right
        //         choose left[0] and right[0]
        ret[1] = left[0] + right[0] + root->val;
        
        return ret;
    }
};
