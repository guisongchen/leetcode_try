/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.

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

// solution 1
// 1. traverse left and right sun-tree then compare node value
// 2. left sub-tree order: root->left->right
// 3. right sun-tree order: root->right->left
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
    bool isSymmetric(TreeNode* root) {
        // do it recursively
        // keypoint:
        // 1. nullptr is consider as a exist node
        //    when tarverse, even root is null. must push it then return
        // 2. due to 1, we must traverse root first, then left-right or right-left
        // 3. compare squence: mid-left-right and mid-right-left,they should be the same
          
        // corner case
        if (!root)
            return true;
        
        // check result of post-order traverse
        vector<TreeNode*> subLeft;
        leftOrder(root->left, subLeft);
        vector<TreeNode*> subRight;
        rightOrder(root->right, subRight);
        
        if (subLeft.size() != subRight.size())
            return false;
        
        for (int i = 0, n = subLeft.size(); i < n; i++) { 
            if (subLeft[i] && subRight[i]) {   
                if (subLeft[i]->val != subRight[i]->val)
                    return false;
            } else if (subLeft[i] != subRight[i]) {
                    return false;
            }
        }
        
        return true;
    }
    
    void leftOrder(TreeNode* root, vector<TreeNode*>& ret) {
        // push it before return in order to keep null node
        ret.push_back(root); 
        if (!root)
            return;
        
        leftOrder(root->left,ret);
        leftOrder(root->right, ret);
    }
    
    void rightOrder(TreeNode* root, vector<TreeNode*>& ret) {
        ret.push_back(root); 
        if (!root)
            return;

        rightOrder(root->right, ret);
        rightOrder(root->left, ret);
        
    }
};



// solution 2
// use stack to do traverse
// left subtree: root -> left -> right
// right subtree: root -> right -> left


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
    bool isSymmetric(TreeNode* root) {
        // do it iteratively use stack
        
        if (!root)
            return true;
        
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        stack<TreeNode*> lt;
        stack<TreeNode*> rt;
        while ((left && right) || (!lt.empty() && !rt.empty())) {
                
            while (left && right) {
                
                if (left->val != right->val)
                    return false;
                
                lt.push(left);
                rt.push(right);
                
                left = left->left;
                right = right->right;
            }
            
            // must use left and right are both bull, if not, false
            if (left != right)
                return false;
            
            if (!lt.empty() && !rt.empty()) {
                
                left = lt.top();
                lt.pop();
                right = rt.top();
                rt.pop();
                
                if (left->val != right->val)
                    return false;
                
                left =left->right;
                right = right->left;
            }
        }
        
        if (left != right)
            return false;
        
        return true;
    }
};


// solution 3
// 1. do it recursively
// 2. check root node, then check left sub-tree, then check right sub-tree

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // do it recursively
        
        if (!root)
            return true;
        
        return check(root->left, root->right);
    }
    
    bool check(TreeNode* left, TreeNode* right) {
        // first check current root node
        // left and right both null
        if (!left && !right)
            return true;
        
        if (left && right) {
            if (left->val != right->val)
                return false;
        } else if (left != right) { // only one of them is null
            return false;
        }
        
        // then check symmetric of childern
        return check(left->left, right->right) && check(left->right, right->left); 
    }
        
};
