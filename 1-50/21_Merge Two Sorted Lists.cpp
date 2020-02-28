/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// keypoints:
// 1. compare and reorder list
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // define return value
        ListNode* ret;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        // l1, l2 non-null
        ListNode* cur;
        if (l1->val <= l2->val) {
            cur = l1;
            l1 = l1->next;
        } else {
            cur = l2;
            l2 = l2->next;
        }
        
        // head of return list
        ret = cur;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        
        cur->next = l1 ? l1 : l2;
        
        return ret;
    }
};
