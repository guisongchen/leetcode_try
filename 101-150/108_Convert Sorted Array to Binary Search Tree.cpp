/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 */
 
 // keypoints:
 // 1. BST inorder traverse is a sorted array
 // 2. choose mid-point as root, BST will be height-balanced,
 // 3. divide and conque, we turn original problem into two sub-problems, recursively solve it
 
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // keypoint: BST in-order tarverse is a sorted array
        // if give a sorted array, we chose mid point as root
        // left part as left-subtree, right part as right-sbutree
        
        return bst(nums, 0, nums.size()-1);
    }
    
    TreeNode* bst(vector<int>& nums, int left, int right) {
        
        if (left > right)
            return nullptr;
        
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = bst(nums, left, mid-1);
        root->right = bst(nums, mid+1, right);
        
        return root;
    }
};
