/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        // corner case
        if (!head)
            return head;
        
        // use current pointer to delete node
        ListNode* cur = head;
        
        // start from the first node
        while (cur->next) {
            ListNode* next = cur->next;
            
            // if duplicated, move next
            // since cur may update, check cur null or not
            if (next && cur->val == next->val) {
                next = next->next;
                cur->next = next;
            } else {
                cur = next;
            }
        }
        
        return head;
    }
};
