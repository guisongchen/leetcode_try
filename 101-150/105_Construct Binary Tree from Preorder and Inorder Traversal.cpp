/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // use pre-order find root, then use it to find left-subtree in in-order
        
        // corner case
        if (preorder.size() == 0)
            return nullptr;
        
        return  buildTreeWithIdx(preorder, inorder,
                                 0, preorder.size()-1, 0, preorder.size()-1);
    }
    
    TreeNode* buildTreeWithIdx(vector<int>& preorder, vector<int>& inorder,
                               int stPre, int endPre, int stIn, int endIn) {
        
        if (stPre > endPre || stIn > endIn)
            return nullptr;
        
        // locate root in inorder, i is the root idx of left-subtree
        int i = stIn;
        while (i <= endIn) {
            if (preorder[stPre] == inorder[i])
                break;
            i++;
        }
        
        int leftLen = i-stIn;
        
        TreeNode* root = new TreeNode(preorder[stPre]);
        root->left = buildTreeWithIdx(preorder, inorder,
                                      stPre+1, stPre+leftLen, stIn, i-1);
        root->right = buildTreeWithIdx(preorder, inorder,
                                       stPre+leftLen+1, endPre, i+1, endIn);
        
        return root;
    }
};
