/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
 
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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

// keypoints:
// 1. find mid-point then use same trick as sorted array
// 2. use fast and slow pointers to find mid-point
// 3. record prev node of mid-point to split list into two parts


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // keypoint: list DO NOT support random access
        // turn list into array is travial, consider something different
        // how to find the midpoint of sorted list?
        // use slow and fast pointer!
        // slow pointer move 1 step each time while fase move two steps
        // when fast comes the end, slow must be on the mid-point
        
        // corner case
        if (!head)
            return nullptr;
        
        // make sure slow and fast pointer exist
        if (!head->next) // corner case: 1
            return new TreeNode(head->val);
        
        // or we don't handle fast here
        /*
        if (!head->next->next) { // corner case: 1-2
            TreeNode* root = new TreeNode(head->val);
            root->right = new TreeNode(head->next->val);
            return root;
        }
        */
        
        // init slow and fast as head
        ListNode* slow = head;
        ListNode* fast = head;
        
        // this is used to cut list later
        // must make sure prev exist, aka at last 3 node exist
        // so then prev will be updated, or we will be trouble
        ListNode* prev = slow;
        
        // notice we must make sure fast is non-null
        // so check both next and next-next of fast
        while (fast->next && fast->next->next) {
            // keep current slow to locate node before mid-point
            prev = slow;
            // slow move 1 step
            slow = slow->next;
            // fast move 2 steps
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        
        // cut list into left and right parts at mid-point
        // left part
        
        // make sure prev is updated, otherwise prev == slow, no left subtree
        if (prev != slow) {
            prev->next = nullptr;
            root->left = sortedListToBST(head);
        }
        
        // right part
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
