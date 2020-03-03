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
          
*/

// keypoints:
// 1. break link between root and right subtree
// 2. break link between root and left subtree
// 3. link root->right with root of left subtree
// 4. link left subtree right leaf(at bottom) with root right subtree
// 5. like tree traverse, we can do it both recursively and iteratively


// solution 1: try do it recursively

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
        // maybe try to do it recursively
        
        // divide and consque
        // first flatten left-child, then right-child
        if (!root)
            return;
        if (root->left)
            flatten(root->left);
        if (root->right)
            flatten(root->right);
        
        // then link flatted left-subTree to first right node of root
        // two steps:
        // 1. link end of left to first of right
        // 2. link first of left to right of root
        TreeNode* end = root->left;
        
        // find last node of left-subtree
        while (end && end->right) {
            end = end->right;
        }
        
        // in case end is null
        if (end) {
            // point left end to right
            end->right = root->right;
            // point root right to left head
            root->right = root->left;
        }
        // set left null
        root->left = nullptr;
    }
};

// solution 2:
// 


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
