/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6


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
    void flatten(TreeNode* root) {
        // keypoint is link left-subTree to the first right node of root
        // recursive is travial. let's do it iteratively
        
        // another thought about this
        // for each node, check it has left node or not
        // if does, break root and right link
        // point root right to left node
        // point left node end right to original right node
        // repeat until no left node exist
        
        TreeNode* cur = root;
        while (cur) {
            // make sure left exist!!
            if (cur->left) {
                
                // find right end in left-subtree
                TreeNode* end = cur->left;
                while (end->right) {
                    end = end->right;
                }

                // point end right to original right
                end->right = cur->right;
                // handle left
                cur->right = cur->left;
                cur->left = nullptr;
            }
            
            // update cur pointer on right subtree
            cur = cur->right;
        }
        
    }
};
