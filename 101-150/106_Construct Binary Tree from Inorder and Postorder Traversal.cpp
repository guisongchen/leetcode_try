/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // old story, get root from postorder, then locate in inorder
        // then find left and right subtree
        
        if (inorder.size() == 0)
            return nullptr;
        
        return buildTreeSuper(inorder, postorder,
                              0, inorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* buildTreeSuper(vector<int>& inorder, vector<int>& postorder,
                             int stIn, int endIn, int stPost, int endPost) {
        
        if (stIn > endIn || stPost > endPost)
            return nullptr;
        
        int rootIdx = stIn;
        while (rootIdx <= endIn) {
            if (postorder[endPost] == inorder[rootIdx])
                break;
            rootIdx++;
        }
        
        TreeNode* root = new TreeNode(postorder[endPost]);
        root->left = buildTreeSuper(inorder, postorder, 
                                    stIn, rootIdx-1, stPost, stPost+rootIdx-stIn-1);
        root->right = buildTreeSuper(inorder, postorder, 
                                     rootIdx+1, endIn, stPost+rootIdx-stIn, endPost-1);
        
        return root;
    }
};
